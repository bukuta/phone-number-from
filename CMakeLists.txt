project(restapi)                                                 
cmake_minimum_required(VERSION 3.11)
add_definitions(-std=c++17)

MESSAGE(STATUS "This is BINARY dir" ${RESTAPI_BINARY_DIR})
MESSAGE(STATUS "This is SROUCE dir" ${RESTAPI_SOURCE_DIR})

# SET(SRC_LIST main.cpp Logger.cpp post.hpp post.cpp RestApi.hpp)
# SET(SRC_LIST MakeCalls.cpp Logger.cpp Call.cpp call.hpp post.hpp post.cpp RestApi.hpp)
# SET(SRC_LIST testString.cpp Logger.cpp )
SET(SRC_LIST_PHONE findPhone.cpp )

INCLUDE_DIRECTORIES(cget/include)

LINK_DIRECTORIES(cget/lib)


#ADD_EXECUTABLE(hello main.c)
#ADD_EXECUTABLE(restapi ${SRC_LIST})
# ADD_EXECUTABLE(hello main.cpp)
# ADD_EXECUTABLE(testString ${SRC_LIST})
ADD_EXECUTABLE(findPhone ${SRC_LIST_PHONE})

#TARGET_LINK_LIBRARIES(restapi libcrypto.a)
#TARGET_LINK_LIBRARIES(restapi libssl.a)
#TARGET_LINK_LIBRARIES(restapi libtls.a)
#TARGET_LINK_LIBRARIES(restapi libboost_system.a)
#TARGET_LINK_LIBRARIES(restapi libboost_iostreams.a)
#TARGET_LINK_LIBRARIES(restapi libboost_exception.a)
#TARGET_LINK_LIBRARIES(restapi libboost_filesystem.a)
#TARGET_LINK_LIBRARIES(restapi libboost_stacktrace_basic.a)
TARGET_LINK_LIBRARIES(restapi libyaml-cpp.a)
TARGET_LINK_LIBRARIES(restapi libcpprest.dylib)
# TARGET_LINK_LIBRARIES(testString libyaml-cpp.a)
# TARGET_LINK_LIBRARIES(testString libcpprest.dylib)

# TARGET_LINK_LIBRARIES(findPhone libyaml-cpp.a)
# TARGET_LINK_LIBRARIES(findPhone libcpprest.dylib)
