#ifndef _GITHUB_API_
#define _GITHUB_API_
#include "GithubProvider.hpp"
#include "GithubAPINode.hpp"
#include "json.hpp"
#include <string>

using json = nlohmann::json;

class GithubAPI {
    public:
        GithubAPI(std::string token);
        ~GithubAPI();

        void setUserSettings(std::string username, std::string passwrd);

        GithubAPINode *getNode(std::string tag);

    private:
        GithubProvider *provider;
        GithubAPINode *root;
        json jparser;

        void getData(GithubAPINode *node);
        GithubAPINode *findNode(GithubAPINode *node, std::string tag);

};
#endif /* _GITHUB_API_ */
