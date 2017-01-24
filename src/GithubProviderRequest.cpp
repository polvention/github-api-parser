#include <iostream>
#include <sstream>
#include <cstdlib>
#include "GithubProviderRequest.hpp"

GithubProviderRequest::GithubProviderRequest(Map globalSettings)
{
    curl = curl_easy_init();
    if (!curl) {
        throw std::string("curl_easy_init() failed.\n");
    }
    buffer = std::string();
    for (Map::iterator it = globalSettings.begin(); it != globalSettings.end(); it++) {
        curl_easy_setopt(curl, (CURLoption) it->first, it->second);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &GithubProviderRequest::requestCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
#ifdef DEBUG
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, debug);
#endif
}

GithubProviderRequest::~GithubProviderRequest()
{
    curl_easy_cleanup(curl);
}

void
GithubProviderRequest::performRequest()
{
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cout << curl_easy_strerror(res) << std::endl;
        throw new std::string("curl_easy_perform() failed.");
    }
}
/*
const char *
GithubProviderRequest::getResponse()
{
    // TODO add request state to control if request was performed
    return buffer.c_str();
}
*/
std::string
GithubProviderRequest::getResponse()
{
    // TODO add request state to control if request was performed
    return buffer;
}

int GithubProviderRequest::requestCallback(char *data, size_t size, size_t nmemb,
                                             std::string *buffer)
{
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
    }
    return size * nmemb;
}

#ifdef DEBUG
int
GithubProviderRequest::debug(CURL *handle, curl_infotype type, char *data,
                               size_t size, void *userp)
{
    switch (type) {
        case CURLINFO_TEXT:
            fprintf(stdout, "== Info: %s\n", data);
            return 0;
        case CURLINFO_HEADER_OUT:
            std::cout << "=> Send header" << std::endl;
            break;
        case CURLINFO_DATA_OUT:
            std::cout << "=> Send data" << std::endl;
            break;
        case CURLINFO_SSL_DATA_OUT:
            std::cout << "=> Send SSL data" << std::endl;
            break;
        case CURLINFO_HEADER_IN:
            std::cout << "<= Recv header" << std::endl;
            break;
        case CURLINFO_DATA_IN:
            std::cout << "<= Recv data" << std::endl;
            break;
        case CURLINFO_SSL_DATA_IN:
            std::cout << "<= Recv SSL data" << std::endl;
            break;
        default:
            std::cout << "Unknown curl_infotype\n";
    }

    for (int i = 0; i < size; i++) {
        fprintf(stdout, "%02x", data[i]);
    }
    fprintf(stdout, "\n\n");
    return 0;
}
#endif

/*
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
