#include "Configuration.hpp"
#include <iostream>

Configuration::Configuration(json config)
{
    rootPath.append(config["config"]["root_dir"]);
    json projects = config["config"]["projects"];
    this->projects = new std::list<Project*>();
    for (size_t i = 0; i < projects.size(); i++) {
        Project *project = new Project(projects[i]);
        this->projects->push_back(project);
    }
    this->projectIdx = 0;
    this->it = this->projects->begin();
}

Configuration::~Configuration()
{
}

Project*
Configuration::getProject()
{
    if (this->it != this->projects->end()) {
        return *(this->it)++;
    } else {
        this->it = this->projects->begin();
    }
    return NULL;
}

std::string
Configuration::getRootPath()
{
    return this->rootPath;
}
