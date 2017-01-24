#ifndef _PROJECT_HPP_
#define _PROJECT_HPP_
#include <string>
#include <list>
#include "json.hpp"

using json = nlohmann::json;

class Project
{
    public:
        Project(json project);
        ~Project();

        std::string getName();
        std::string getUrl();
        std::string getRootDir();
        std::list<std::string> getDirectories();
        std::list<std::string> getCommands();

    private:
        void getPath(std::string base, json tree);
        std::string name;
        std::string url;
        std::string rootDir;
        std::list<std::string> dependencies;
        std::list<std::string> commands;
        std::list<std::string> directories;
};

#endif /* _PROJECT_HPP_ */
