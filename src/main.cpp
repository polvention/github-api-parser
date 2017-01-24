#include <cstdio>
#include <string>
#include "GithubProvider.hpp"
#include "GithubProviderRequest.hpp"
#include "GithubProviderConfig.hpp"
#include "Configuration.hpp"
#include "Integrator.hpp"
#include "Project.hpp"
#include "BuildProject.hpp"

using json = nlohmann::json;

int main(void)
{
    try {
//        std::string user = "tymion";
//        std::string user = "tymion:c87732f9db1467f6c808710b3c902d5ad70ebda5";
//        std::string token = "c87732f9db1467f6c808710b3c902d5ad70ebda5";
        std::string token = "su5gpioYy4hiarWBph3M";
        char url[63] = "http://polvention/AISGroup/AIS-CustomConf/raw/master/conf.json";
//        std::string passwrd = "c87732f9db1467f6c808710b3c902d5ad70ebda5";

//        GithubAPI *github = new GithubAPI(token);
//        github->setUserSettings(user, passwrd);
//        github->getNode("current_user_url");
        GithubProvider *provider = new GithubProvider();
        GithubProviderConfig *config = provider->createConfig();
        config->addHeaderSetting(PrivateToken, token);
        config->addSetting(Url, url);
        GithubProviderRequest *req = provider->createRequest(config);
        req->performRequest();
        //provider->parseRequestResponse(req);
        std::string res = req->getResponse();
        json jparser = json::parse(res);
        Configuration *cfg = new Configuration(jparser);
        Integrator *integ = new Integrator(cfg);
        
        Project *project = cfg->getProject();
        if (project) {
            BuildProject *build = integ->processProject(project);
            std::string str = project->getName();
            std::cout << "!!!!!:" << str << std::endl;
        }
        delete integ;
        delete provider;
        delete req;
        delete config;
    } catch (std::string *ex) {
        std::cout << "Catch:" << *ex << std::endl;
        delete ex;
    } catch (std::exception const &exc) {
        std::cout << "Catch:" << exc.what() << std::endl;
    } catch (...) {
        std::cout << "Catch unknowkn exception" << std::endl;
    }
    return 0;
}
