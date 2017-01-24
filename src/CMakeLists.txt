set(NAME parser)

set(SOURCES
    main.cpp
    GithubProvider.cpp
    GithubProviderRequest.cpp
    GithubProviderConfig.cpp
    Project.cpp
    BuildProject.cpp
    Configuration.cpp
    Integrator.cpp
    #    PVGithubAPI.cpp
    #PVGithubAPIUri.cpp
    #PVGithubAPINode.cpp
)

add_executable(${NAME} ${SOURCES})
target_link_libraries(${NAME} curl)
