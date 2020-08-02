# CMake generated Testfile for 
# Source directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/PasswordCheck
# Build directory: /home/maciej/Documents/MyTasks/MaciejSalamonski/PasswordCheck/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(PasswordCheck_test "/home/maciej/Documents/MyTasks/MaciejSalamonski/PasswordCheck/build/PasswordCheck-ut")
set_tests_properties(PasswordCheck_test PROPERTIES  _BACKTRACE_TRIPLES "/home/maciej/Documents/MyTasks/MaciejSalamonski/PasswordCheck/CMakeLists.txt;44;add_test;/home/maciej/Documents/MyTasks/MaciejSalamonski/PasswordCheck/CMakeLists.txt;0;")
subdirs("googletest-build")
