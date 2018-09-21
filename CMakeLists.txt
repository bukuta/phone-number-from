project(restapi)                                                 
cmake_minimum_required(VERSION 3.11)
add_definitions(-std=c++17)

MESSAGE(STATUS "This is BINARY dir" ${RESTAPI_BINARY_DIR})
MESSAGE(STATUS "This is SROUCE dir" ${RESTAPI_SOURCE_DIR})

SET(SRC_LIST main.cpp post.hpp post.cpp RestApi.hpp)

INCLUDE_DIRECTORIES(cget/include)

LINK_DIRECTORIES(cget/lib)


#ADD_EXECUTABLE(hello main.c)
ADD_EXECUTABLE(restapi ${SRC_LIST})

#TARGET_LINK_LIBRARIES(restapi libcrypto.a)
#TARGET_LINK_LIBRARIES(restapi libssl.a)
#TARGET_LINK_LIBRARIES(restapi libtls.a)
#TARGET_LINK_LIBRARIES(restapi libboost_system.a)
#TARGET_LINK_LIBRARIES(restapi libboost_iostreams.a)
#TARGET_LINK_LIBRARIES(restapi libboost_exception.a)
#TARGET_LINK_LIBRARIES(restapi libboost_filesystem.a)
#TARGET_LINK_LIBRARIES(restapi libboost_stacktrace_basic.a)
TARGET_LINK_LIBRARIES(restapi libcpprest.dylib)
