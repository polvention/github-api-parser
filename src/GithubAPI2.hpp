#ifndef _GITHUB_API_
#define _GITHUB_API_
#include <cstdio>

namespace GithubAPI {

    enum RequestType {
        User = 0,
        Repository,
        Max
    };

    static const char *apiRequests[Max] = {
        "https://api.github.com/users",
        "https://api.github.com/repo/"
    };
}
#endif /* _GITHUB_API_ */
