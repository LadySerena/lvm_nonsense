cmake_minimum_required(VERSION 3.23)
project(lvm_bullshit C)

set(CMAKE_C_STANDARD 23)

add_executable(lvm_bullshit main.c)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB_2.0 REQUIRED IMPORTED_TARGET glib-2.0)
pkg_check_modules(BLOCKDEV REQUIRED IMPORTED_TARGET blockdev)
pkg_check_modules(BLOCKDEV_UTILS REQUIRED IMPORTED_TARGET blockdev-utils)

target_link_libraries(lvm_bullshit PkgConfig::GLIB_2.0)
target_link_libraries(lvm_bullshit PkgConfig::BLOCKDEV)
target_link_libraries(lvm_bullshit PkgConfig::BLOCKDEV_UTILS)
target_link_libraries(lvm_bullshit bd_lvm)