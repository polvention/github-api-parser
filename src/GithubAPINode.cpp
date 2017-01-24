#include "GithubAPINode.hpp"

GithubAPINode::GithubAPINode(std::string tag, std::string url)
{
    this->tag = tag;
    this->url = new GithubAPIUri(url);
}

GithubAPINode::~GithubAPINode()
{
}

std::string
GithubAPINode::getTag()
{
    return tag;
}

GithubAPIUri *
GithubAPINode::getUrl()
{
    return url;
}

void
GithubAPINode::addSubNode(std::string tag, GithubAPINode *node)
{
    subNodes.insert(std::pair<std::string, GithubAPINode>(tag, *node));
}

void
GithubAPINode::addProperties(std::string tag, std::string value)
{
}

void
GithubAPINode::addProperties(std::string tag, int value)
{
}
