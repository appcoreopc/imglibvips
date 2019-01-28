cmake_minimum_required(VERSION 2.8.9)
project (imp)

find_package(PkgConfig REQUIRED)

pkg_search_module(GLIB REQUIRED glib-2.0 vips)

SET(CMAKE_CXX_COMPILER /usr/bin/g++)

set (CMAKE_CXX_FLAGS "-pthread -I/usr/local/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -L/usr/local/lib -lvips-cpp -lvips -lgobject-2.0 -lglib-2.0")

add_executable(imp imp.cc)