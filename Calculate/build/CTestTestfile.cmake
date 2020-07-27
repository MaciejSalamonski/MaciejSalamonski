# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/Calculate
# Build directory: /home/maciej/Documents/MyTasks/Calculate/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(calculateTests "/home/maciej/Documents/MyTasks/Calculate/build/calculate-ut")
set_tests_properties(calculateTests PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/Calculate/CMakeLists.txt;43;add_test;/home/maciej/Documents/MyTasks/Calculate/CMakeLists.txt;0;")
subdirs("googletest-build")
