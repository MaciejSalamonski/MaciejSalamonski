# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci
# Build directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(fibonacci-test "/home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build/fibonacci-ut")
set_tests_properties(fibonacci-test PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/CMakeLists.txt;43;add_test;/home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/CMakeLists.txt;0;")
subdirs("googletest-build")
