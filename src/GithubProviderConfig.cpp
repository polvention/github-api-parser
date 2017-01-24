#include <iostream>
#include "GithubProviderConfig.hpp"

GithubProviderConfig::GithubProviderConfig(std::string userAgent)
{
    list = curl_slist_append(list, ("User-Agent: " + userAgent).c_str());
//    globalSettings.insert(Pair((int) CURLOPT_FOLLOWLOCATION, (void *) 1L));
//    globalSettings.insert(Pair((int) CURLOPT_HEADER, (void *) 1L));
}

GithubProviderConfig::~GithubProviderConfig()
{
}

/*
 * Settings functions
 */

void
GithubProviderConfig::addSetting(Settings key, void *value)
{
    switch (key)
    {
        case User:
            globalSettings.insert(Pair((int) CURLOPT_USERNAME, value));
            break;
        case Password:
            globalSettings.insert(Pair((int) CURLOPT_PASSWORD, value));
            break;
        case Auth:
            globalSettings.insert(Pair((int) CURLOPT_HTTPAUTH, (void *) CURLAUTH_BASIC));
            break;
        case Url:
            globalSettings.insert(Pair((int) CURLOPT_URL, value));
            break;
        default:
            std::cout << "Invalid settings key\n";
    }
}

void
GithubProviderConfig::addHeaderSetting(HeaderSettings key, std::string value)
{
    switch (key)
    {
        case Token:
            list = curl_slist_append(list, ("Authorization: token" + value).c_str());
            break;
        case PrivateToken:
            list = curl_slist_append(list, ("PRIVATE-TOKEN: " + value).c_str());
            break;
        default:
            std::cout << "Invalid settings key\n";
    }
}

void
GithubProviderConfig::setUserSettings(std::string username, std::string passwrd)
{
    /*
    provider->addSetting(GithubProviderConfig::Settings::User, (void *) username.c_str());
    provider->addSetting(GithubProviderConfig::Settings::Password, (void *) passwrd.c_str());
    provider->addSetting(GithubProviderConfig::Settings::Auth, NULL);
    */
}

Map
GithubProviderConfig::getSettings()
{
    globalSettings.insert(Pair((int) CURLOPT_HTTPHEADER, (void *) list));
    return globalSettings;
}
