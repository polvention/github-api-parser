#ifndef _GITHUB_API_URI_
#define _GITHUB_API_URI_
#include <string>

class GithubAPIUri {
    public:
        GithubAPIUri(std::string uri);
        ~GithubAPIUri();

        std::string getUrl();

    private:
        std::string url;

};

#endif /* _GITHUB_API_URI_ */
