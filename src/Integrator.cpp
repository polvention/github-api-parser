#include "Integrator.hpp"
#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

static void _mkdir(const char *dir)
{
    char tmp[256];
    char *p = NULL;
    size_t len;
    
    std::cout << dir  << std::endl;
    snprintf(tmp, sizeof(tmp),"%s",dir);
    len = strlen(tmp);
    if (tmp[len - 1] == '/') {
        tmp[len - 1] = 0;
    }
        
    for (p = tmp + 1; *p; p++) {
        if (*p != '/') {
            continue;
        }

        *p = 0;
        if (mkdir(tmp, S_IRWXU) != 0) {
            *p = '/';
            if (errno == EEXIST) {
                continue;
            }
            std::cout << tmp  << std::endl;
            perror("Cannot create directory.");
            throw new std::string("Cannot create directory.\n");
        }
        *p = '/';
    }
    if (mkdir(tmp, S_IRWXU) != 0) {
        std::cout << tmp  << std::endl;
        perror("Cannot create directory.");
        throw new std::string("Cannot create directory.\n");
    }
    //mkdir(this->rootDir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0
}

static void
createDir(const char *dir)
{
    struct stat info;
    if (stat(dir, &info) != 0) {
        _mkdir(dir);
        if (stat(dir, &info) != 0) {
            throw new std::string("Cannot access root dir from configuration.\n");
        }
    } else if (!(info.st_mode & S_IFDIR)) {
        throw new std::string("root dir from configuration is not a directory.\n");
    }
}

Integrator::Integrator(Configuration *config)
{
    if (asprintf(&this->rootDir, "%s", config->getRootPath().c_str()) == -1) {
        throw new std::string("Function asprintf failed.\n");
    }
    createDir(this->rootDir);
    this->config = config;
}

Integrator::~Integrator()
{
}

BuildProject*
Integrator::processProject(Project *project)
{
    BuildProject *build = new BuildProject(project);
    char* dir = NULL;
    if (project->getRootDir().length() > 0) {
        if (asprintf(&dir, "%s/%s", project->getRootDir().c_str(),
                    build->getName().c_str()) == -1) {
            throw new std::string("Function asprintf failed.\n");
        }
        createDir(dir);
    } else {
        if (asprintf(&dir, "%s/%s", config->getRootPath().c_str(),
                    build->getName().c_str()) == -1) {
            throw new std::string("Function asprintf failed.\n");
        }
        createDir(dir);
    }
    char* tree = NULL;
    if (asprintf(&tree, "%s/rootfs", dir) == -1) {
        throw new std::string("Function asprintf failed.\n");
    }
    createDir(tree);
    free(tree);
    std::list<std::string> list = project->getDirectories();
    for (std::list<std::string>::iterator iter = list.begin(); iter != list.end(); iter++) {
        if (asprintf(&tree, "%s/rootfs/%s", dir, (*iter).c_str()) == -1) {
            throw new std::string("Function asprintf failed.\n");
        }
        createDir(tree);
        free(tree);
    }
    if (asprintf(&tree, "%s/sources", dir) == -1) {
        throw new std::string("Function asprintf failed.\n");
    }
    createDir(tree);
    free(tree);
    list = project->getCommands();
    char *command = NULL;
    if (asprintf(&command, "cd %s", tree) == -1) {
        throw new std::string("Function asprintf failed.\n");
    }
    system(command);
    free(command);
    for (std::list<std::string>::iterator iter = list.begin(); iter != list.end(); iter++) {
        system((*iter).c_str());
    }
    return build;
}
