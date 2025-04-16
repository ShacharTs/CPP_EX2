cmake_minimum_required(VERSION 3.10)
project(CPP_EX2)

# Create a library target from your class files
add_library(SquareMatrix STATIC
        SquareMat.cpp
)

# Then create the executable
add_executable(CPP_EX2
        test.cpp
)

# Link the library to the executable
target_link_libraries(CPP_EX2 PRIVATE SquareMatrix)
