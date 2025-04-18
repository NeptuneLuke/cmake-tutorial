add_library(MathFunctions MathFunctions.cxx)

target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  add_library(SqrtLibrary STATIC mysqrt.cxx)

  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

  include(CheckCXXSourceCompiles)

  check_cxx_source_compiles("#include <cmath> int main() { std::log(1.0); return 0; }" HAVE_LOG)
  check_cxx_source_compiles("#include <cmath> int main() { std::exp(1.0); return 0; }" HAVE_EXP)

  if(HAVE_LOG)
    target_compile_definitions(SqrtLibrary PRIVATE "HAVE_LOG" "HAVE_EXP")
  endif()

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()

install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
