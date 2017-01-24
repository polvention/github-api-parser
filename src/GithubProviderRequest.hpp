#ifndef _GITHUB_PROVIDER_REQUEST_
#define _GITHUB_PROVIDER_REQUEST_
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <curl/curl.h>
#include "GithubProviderInternal.hpp"

class GithubProviderRequest
{
    public:
        GithubProviderRequest(Map globalSettings);
        ~GithubProviderRequest();

        void performRequest();
        //const char *getResponse();
        std::string getResponse();

    private:
        static int requestCallback(char *data, size_t size, size_t nmemb,
                                   std::string *buffer);
#ifdef DEBUG
        static int debug(CURL *handle, curl_infotype type, char *data,
                         size_t size, void *userp);
#endif

    protected:
        CURL *curl;
        std::string buffer;
};

#endif /*_GITHUB_PROVIDER_REQUEST_*/
