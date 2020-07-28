# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/AddEven
# Build directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/AddEven/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AddEven_test "/home/maciej/Documents/MyTasks/MaciejSalamonski/AddEven/build/AddEven-ut")
set_tests_properties(AddEven_test PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/MaciejSalamonski/AddEven/CMakeLists.txt;44;add_test;/home/maciej/Documents/MyTasks/MaciejSalamonski/AddEven/CMakeLists.txt;0;")
subdirs("googletest-build")
