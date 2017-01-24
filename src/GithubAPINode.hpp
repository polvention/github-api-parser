#ifndef _GITHUB_API_NODE_
#define _GITHUB_API_NODE_
#include "GithubAPIUri.hpp"
#include <string>
#include <map>

class GithubAPINode {

    public:
        GithubAPINode(std::string tag, std::string url);
        ~GithubAPINode();

        std::string getTag();
        GithubAPIUri *getUrl();

        void addSubNode(std::string tag, GithubAPINode *node);
        void addProperties(std::string tag, std::string value);
        void addProperties(std::string tag, int value);

        typedef std::map<std::string, GithubAPINode> NodesMap;
        typedef std::pair<std::string, GithubAPINode> NodesPair;

        typedef std::map<std::string, std::string> PropMap;
        typedef std::pair<std::string, std::string> PropPair;

        NodesMap subNodes;

    private:
        std::string tag;
        GithubAPIUri *url;
        PropMap properties;

};

#endif /* _GITHUB_API_NODE_ */
