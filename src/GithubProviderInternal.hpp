#ifndef _GITHUB_PROVIDER_INTERNAL_
#define _GITHUB_PROVIDER_INTERNAL_
#include <map>

typedef std::map<int, void*> Map;
typedef std::pair<int, void*> Pair;

enum Settings{
    User,
    Password,
    Auth,
    Url
};

enum HeaderSettings{
    Token,
    PrivateToken
};

#endif /*_GITHUB_PROVIDER_INTERNAL_*/
