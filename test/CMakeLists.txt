cmake_minimum_required(VERSION 3.1.3)
project(test)

find_package(catkin REQUIRED COMPONENTS message_generation roscpp)

# ROS messages, services and actions
add_message_files(DIRECTORY msg FILES
	main.msg
	sub.msg
)

generate_messages()

catkin_package(
	CATKIN_DEPENDS
		message_runtime
		roscpp
)

include_directories(${catkin_INCLUDE_DIRS})

if (CATKIN_ENABLE_TESTING)
  catkin_add_gtest(printer printer.cpp)
  target_link_libraries(printer ${catkin_LIBRARIES})
endif()
