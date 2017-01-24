#ifndef _GITHUB_PROVIDER_
#define _GITHUB_PROVIDER_
#include <cstdio>
#include "GithubProviderRequest.hpp"
#include "GithubProviderConfig.hpp"


class GithubProvider
{
    public:
        GithubProvider();
        ~GithubProvider();

        void parseRequestResponse(GithubProviderRequest *request);
        GithubProviderRequest* createRequest(GithubProviderConfig *config);
        GithubProviderConfig* createConfig();
};

#endif /*_GITHUB_PROVIDER_*/
