cmake_minimum_required( VERSION 3.0 )

project(JiPP_lab6)

include_directories( ./src ./include/JiPP_lab6 )

add_executable(binary ./src/main.cpp ./src/employeeClass.cpp ./src/HRMS.cpp)

