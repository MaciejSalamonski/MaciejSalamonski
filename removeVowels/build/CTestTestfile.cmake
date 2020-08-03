# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels
# Build directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RemoveVowels_test "/home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build/RemoveVowels-ut")
set_tests_properties(RemoveVowels_test PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/CMakeLists.txt;44;add_test;/home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/CMakeLists.txt;0;")
subdirs("googletest-build")
