#ifndef _GITHUB_PROVIDER_CONFIG_
#define _GITHUB_PROVIDER_CONFIG_
#include <cstdio>
#include <cstdlib>
#include <string>
#include <curl/curl.h>
#include "GithubProviderInternal.hpp"

class GithubProviderConfig
{
    public:
        GithubProviderConfig(std::string userAgent);
        ~GithubProviderConfig();

        void addSetting(Settings key, void *value);
        void addHeaderSetting(HeaderSettings key, std::string value);
        void setUserSettings(std::string username, std::string passwrd);
        Map getSettings();

    protected:
        struct curl_slist *list = NULL;
        Map globalSettings;
};

#endif /*_GITHUB_PROVIDER_CONFIG_*/
