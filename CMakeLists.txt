cmake_minimum_required(VERSION 3.10.0)
project(serverwatch VERSION 0.1.0 LANGUAGES C CXX)

add_executable(serverwatch main.cpp
    CpuMonitor.cpp
    CpuMonitor.h)

install(TARGETS serverwatch RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "serverwatch")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "serverwatch@example.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "serverwatch")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

include(CPack)
