PROJECT(alpha_beta_filter)

set(CMAKE_CXX_FLAGS "-O3 -g -Wall -DNDEBUG")

ADD_EXECUTABLE(alpha_beta_filter main.cpp simulator.cpp)

