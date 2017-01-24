#include <cstdlib>
#include "GithubProvider.hpp"
#include "json.hpp"

using json = nlohmann::json;

GithubProvider::GithubProvider()
{
    //TODO Add settings for custom SSL
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

GithubProvider::~GithubProvider()
{
    curl_global_cleanup();
}

GithubProviderConfig*
GithubProvider::createConfig()
{
    return new GithubProviderConfig("AIS");
}

GithubProviderRequest*
GithubProvider::createRequest(GithubProviderConfig *config)
{
    /*
    if (url == NULL) {
        throw new std::string("Invalid argument type passed.");
    }
*/
    return new GithubProviderRequest(config->getSettings());
}

void
GithubProvider::parseRequestResponse(GithubProviderRequest *request)
{
    //const  char * res = request->getResponse();
    //std::cout  << res << std::endl;
//    std::ifstream t("test.json");
//    std::string res((std::istreambuf_iterator<char>(t)),
//                     std::istreambuf_iterator<char>());
    std::string res = request->getResponse();
    json jparser = json::parse(res);
    std::cout << "user_url: " << jparser["config"] << std::endl;
}

/*
//    system("python -m json.tool /tmp/file-github-api-parser > /tmp/file-github-api-parser.json");
   char *ct;
   res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
   if (res != CURLE_OK) {
   fprintf(stderr, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(res));
   goto cleanup;
   }

   if (ct) {
   printf("We received Content-Type: %s\n", ct);
   }
   */
