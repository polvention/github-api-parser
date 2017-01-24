#include "Project.hpp"

Project::Project(json project)
{
    url = project["url"];
    name = project["name"];
    if (project["dependencies"] != NULL) {
        dependencies = std::list<std::string>();
        for (size_t i = 0; i < project["dependencies"].size(); i++) {
            dependencies.push_back(project["dependencies"][i]);
        }
    }
    if (project["commands_list"] != NULL) {
        commands = std::list<std::string>();
        for (size_t i = 0; i < project["commands_list"].size(); i++) {
            commands.push_back(project["commands_list"][i]);
        }
    }
    
    json tree = project["files_tree"];
    if (tree != NULL) {
        for (json::iterator iter = tree.begin(); iter != tree.end(); iter++) {
            getPath((*iter)["name"], (json) (*iter)["subdirectories"]);
        }
    }
    if (project["root_dir"] != NULL) {
        rootDir = project["root_dir"];
    }
}

Project::~Project()
{
}

void
Project::getPath(std::string base, json tree)
{
    for (json::iterator iter = tree.begin(); iter != tree.end(); iter++) {
        if (iter->is_primitive()) {
            std::cout << "!!!!!2" << *iter << std::endl;
            continue;
        }
        std::string str = base + "/";
        str.append((*iter)["name"]);
        if ((*iter)["subdirectories"].empty()) {
            directories.push_front(str);
            continue;
        }

        getPath(str, (json) (*iter)["subdirectories"]);
    }
}

std::string
Project::getName()
{
    return name;
}

std::string
Project::getUrl()
{
    return url;
}

std::string
Project::getRootDir()
{
    return rootDir;
}

std::list<std::string>
Project::getDirectories()
{
    return directories;
}

std::list<std::string>
Project::getCommands()
{
    return commands;
}
