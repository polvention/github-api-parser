#include "BuildProject.hpp"

void
BuildProject::addString(std::stringstream *ss, int n)
{
    if (n < 10) {
        *ss << "0";
    }
    *ss << std::to_string(n);
}

BuildProject::BuildProject(Project *project)
{
    time_t rawtime;
    time(&rawtime);
    //struct tm *timeinfo = localtime (&rawtime);
    struct tm *timeinfo = gmtime (&rawtime);
    std::stringstream ss;
    ss << "build-" + project->getName() + "-" + std::to_string(timeinfo->tm_year + 1900);
    addString(&ss, timeinfo->tm_mon + 1);
    addString(&ss, timeinfo->tm_mday);
    ss << "-";
    addString(&ss, timeinfo->tm_hour);
    addString(&ss, timeinfo->tm_min);
    addString(&ss, timeinfo->tm_sec);

    name = ss.str();
}

BuildProject::~BuildProject()
{
}

std::string
BuildProject::getName()
{
    return name;
}
