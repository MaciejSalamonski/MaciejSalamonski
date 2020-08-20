# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/SHM1
# Build directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/SHM1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(shm_test "/home/maciej/Documents/MyTasks/MaciejSalamonski/SHM1/build/shm-ut")
set_tests_properties(shm_test PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/MaciejSalamonski/SHM1/CMakeLists.txt;67;add_test;/home/maciej/Documents/MyTasks/MaciejSalamonski/SHM1/CMakeLists.txt;0;")
subdirs("googletest-build")
