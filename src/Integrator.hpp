#ifndef _INTEGRATOR_
#define _INTEGRATOR_
#include <list>
#include <string>
#include "Configuration.hpp"
#include "Project.hpp"
#include "BuildProject.hpp"

class Integrator
{
    public:
        Integrator(Configuration *config);
        ~Integrator();

        BuildProject *processProject(Project *project);
    private:
        char* rootDir = NULL;
        Configuration *config;

};

#endif /*_INTEGRATOR_*/
