add_library(MathFunctions MathFunctions.cxx)

# TODO 1: Specify the Usage requirements. State that anybody linking to MathFunctions
# needs to include the current source directory, while MathFunctions itself doesn't.
# This can be expressed with an INTERFACE usage requirement. Remember INTERFACE
# means things that consumers require but the producer doesn't.
# Hint: Use target_include_directories with the INTERFACE keyword
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

option(USE_MYMATH "Use tutorial provided math implementation" ON)
if(USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # library that just does sqrt
  add_library(SqrtLibrary STATIC mysqrt.cxx)

  # TODO 6: Link SqrtLibrary to tutorial_compiler_flags
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# TODO 7: Link MathFunctions to tutorial_compiler_flags
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)