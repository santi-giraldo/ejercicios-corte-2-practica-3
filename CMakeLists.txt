cmake_minimum_required(VERSION 3.10)

project(ParcialCorte2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(bank Bank_Account.cpp)
add_executable(auth Design_Authentication_Manager.cpp)
add_executable(exam Design_Exam_Scores_Tracker.cpp)
add_executable(square Crypto_Square/square_code.cpp)

find_package(Threads REQUIRED)
target_link_libraries(bank Threads::Threads)
