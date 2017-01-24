#include "GithubAPI.hpp"
#include "GithubAPIUri.hpp"
#include "GithubProviderRequest.hpp"

GithubAPI::GithubAPI(std::string token)
{
    provider = new GithubProvider(token);
    root = new GithubAPINode("ROOT", "https://api.github.com/");
    getData(root);
}

GithubAPI::~GithubAPI()
{
    delete provider;
}

/*
 * Settings functions
 */

void
GithubAPI::setUserSettings(std::string username, std::string passwrd)
{
    provider->addSetting(GithubProvider::Settings::User, (void *) username.c_str());
    provider->addSetting(GithubProvider::Settings::Password, (void *) passwrd.c_str());
    provider->addSetting(GithubProvider::Settings::Auth, NULL);
}

/*
 * 
 */
GithubAPINode *
GithubAPI::getNode(std::string tag)
{
    GithubAPINode *ret = findNode(root, tag);
    std::cout << "=========" << ret->getUrl()->getUrl().c_str() << std::endl;
    getData(ret);
    return ret;
}

/*
 * private functions
 */
void
GithubAPI::getData(GithubAPINode *node)
{
    std::cout << "=========" << node->getUrl()->getUrl().c_str() << std::endl;
    GithubProviderRequest *request = provider->createRequest(node->getUrl()->getUrl());
    std::cout << "=========" << node->getUrl()->getUrl().c_str() << std::endl;
    request->performRequest();
    std::string res = request->getResponse();
    jparser = json::parse(res);
    GithubAPINode *newNode = NULL;
    int size = 0;
    std::string tag, value;
    for (json::iterator it = jparser.begin(); jparser.end() != it; it++) {
        tag = it.key();
        value = it.value() == NULL ? "" : it.value();
        size = tag.size();
        if (size > 4 && tag.compare(size - 4, 4, "_url") == 0) {
            newNode = new GithubAPINode(tag, value);
            node->addSubNode(tag, newNode);
        } else {
            node->addProperties(tag, value);
        }
        std::cout << tag << ":" << value << std::endl;
    }
    delete request;
}

GithubAPINode *
GithubAPI::findNode(GithubAPINode *node, std::string tag)
{
    GithubAPINode *ret = NULL;
    for (GithubAPINode::NodesMap::iterator it = node->subNodes.begin(); it != node->subNodes.end(); it++) {
        if ((ret = findNode(&(it->second), tag))) {
            return ret;
        }
    }
    if (tag.compare(node->getTag()) == 0) {
        return node;
    }
    return NULL;
}
