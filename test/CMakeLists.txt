add_executable(cango_nstd_simple simple.cpp)
set_target_properties(cango_nstd_simple PROPERTIES CXX_STANDARD 26)
target_link_libraries(cango_nstd_simple ${cango.lib.alias})
add_test(NAME cango_nstd_simple COMMAND cango_nstd_simple)
