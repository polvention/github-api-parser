#include "GithubAPIUri.hpp"

GithubAPIUri::GithubAPIUri(std::string url)
{
    this->url = url;
}

GithubAPIUri::~GithubAPIUri()
{
}

std::string
GithubAPIUri::getUrl()
{
    return url;
}
