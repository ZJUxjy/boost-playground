include(cmake/CPM.cmake)

# CPMAddPackage(
#     NAME jsoncpp
#     GIT_REPOSITORY git@github.com:open-source-parsers/jsoncpp.git
#     GIT_TAG master 
# )
# include_directories(${jsoncpp_SOURCE_DIR}/include)
# link_directories(${jsoncpp_BINARY_DIR}/src/lib_json)


# glog
CPMAddPackage(
    NAME glog
    URL http://mirrors.phigent.io/nfs/pkgs/glog_0.5.0/x86_64-ubuntu-linux-gcc9.3.0/glog_0.5.0.tar
)
include_directories(${glog_SOURCE_DIR}/include)
link_directories(${glog_SOURCE_DIR}/lib)
# # gtest
# CPMAddPackage(
#     NAME gtest
#     GIT_REPOSITORY git@github.com:google/googletest.git
#     GIT_TAG main 
#     )
# include_directories(${gtest_SOURCE_DIR}/include)
# link_directories(${gtest_SOURCE_DIR}/lib)
# # folly
# CPMAddPackage(
#     NAME folly
#     GIT_REPOSITORY git@github.com:facebook/folly.git
#     GIT_TAG main 
#     )
# include_directories(${folly_SOURCE_DIR}/include)
# link_directories(${folly_SOURCE_DIR}/lib)