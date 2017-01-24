#ifndef _BUILD_PROJECT_HPP_
#define _BUILD_PROJECT_HPP_
#include <string>
#include <sstream>
#include "Project.hpp"

class BuildProject
{
    public:
        BuildProject(Project *project);
        ~BuildProject();

        std::string getName();

    private:
        void addString(std::stringstream *ss, int n);
        std::string name;
};

#endif /* _BUILD_PROJECT_HPP_ */
