#ifndef _CONFIGURATION_
#define _CONFIGURATION_
#include <list>
#include <string>
#include "json.hpp"
#include "Project.hpp"

using json = nlohmann::json;

class Configuration
{
    public:
        Configuration(json config);
        ~Configuration();

        std::string getRootPath();

        Project* getProject();

    private:
        std::list<Project*> *projects;
        std::list<Project*>::iterator it;
        std::string rootPath;
        size_t projectIdx;
};

#endif /*_CONFIGURATION_*/
