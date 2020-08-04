# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort
# Build directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(LengthSort_test "/home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build/LengthSort-ut")
set_tests_properties(LengthSort_test PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/CMakeLists.txt;44;add_test;/home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/CMakeLists.txt;0;")
subdirs("googletest-build")
