cmake_minimum_required(VERSION 3.10)
project(PrivilegeChecker)

set(CMAKE_CXX_STANDARD 17)

add_executable(PrivilegeChecker main.cpp)

target_link_libraries(PrivilegeChecker Netapi32)

add_definitions(-D_ATL_NO_AUTOMATIC_NAMESPACE)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

target_link_libraries(PrivilegeChecker netapi32)

include_directories(${CMAKE_VS_DEVENV_DIR}/VC/Tools/MSVC/14.29.30133/include)
link_directories(${CMAKE_VS_DEVENV_DIR}/VC/Tools/MSVC/14.29.30133/lib/x64)