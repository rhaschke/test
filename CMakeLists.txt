cmake_minimum_required(VERSION 3.15)
project(testpkg VERSION 1.2.3 LANGUAGES C)

find_package(catkin REQUIRED COMPONENTS)

add_library(testpkg_lib SHARED lib.c)
set_target_properties(testpkg_lib PROPERTIES OUTPUT_NAME testpkg)

add_library(testpkg_lib_versioned SHARED lib.c)
set_target_properties(testpkg_lib_versioned PROPERTIES
  OUTPUT_NAME testpkg_versioned
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

add_executable(testpkg main.c)
target_link_libraries(testpkg testpkg_lib)

install(TARGETS
  testpkg_lib
  testpkg_lib_versioned
  testpkg
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

catkin_python_setup()
catkin_package()