cmake_minimum_required(VERSION 3.17)
project(AD_TP_Classes)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})

# Add the source files of each TP class
#file(GLOB TP1_FILES CONFIGURE_DEPENDS "TP1/*.cpp")
#file(GLOB TP2_FILES CONFIGURE_DEPENDS "TP2a/*.cpp")
#file(GLOB TP2_FILES CONFIGURE_DEPENDS "TP2b/*.cpp")
#file(GLOB TP3_FILES CONFIGURE_DEPENDS "TP3a/*.cpp")
file(GLOB TP3_FILES CONFIGURE_DEPENDS "TP3b/*.cpp")
#...

#add_executable(TP1 main.cpp ${TP1_FILES})
#add_executable(TP2 main.cpp ${TP2_FILES})
add_executable(TP3 main.cpp ${TP3_FILES})
#...

#target_link_libraries(TP1 gtest_main gmock_main)
#target_link_libraries(TP2 gtest_main gmock_main)
target_link_libraries(TP3 gtest_main gmock_main)
#...