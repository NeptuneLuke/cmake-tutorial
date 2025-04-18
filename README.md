# A CMake official tutorial, step by step

This is a collection of all the steps in the official [CMake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/). Following the tutorial step by step will give you a basic but useful overview of most CMake use cases. This repo is only used as a solution archive.

The folders are organized as follows:

- **step_xxx** is the finished step with no comments
- **step_xxx_verbose** is the finished step with some basic comments about what the CMake command is about or why we are doing it in that specific way

The actual **/builds** directories are not included.

<br>

## Step 1
The most basic **CMake project** is an executable built from a single source code file. For simple projects like this, a CMakeLists.txt file with three commands is all that is required.

### Goals:
- Build a basic project.
- Specify the C++ standard.
- Specify the **input** Configured Header File, which makes possible to have variables that are both defined in the CMakeLists.txt and in the source code.

<br>

## Step 2
At this point, we have seen how to create a basic project using CMake. In this step, we will learn how to create and use a **library** in our project. We will also see how to make the use of our **library optional**.

With these changes, the mysqrt function is now completely optional to whoever is building and using the MathFunctions library. Users can toggle **USE_MYMATH** using the **compiler flag** -DUSE_MYMATH=ON or -DUSE_MYMATH=OFF to manipulate what library is used in the build. Note that the user does not need to set the USE_MYMATH value everytime the project is built.

### Goals:
- Add a library: rather than placing all of the source files in one directory, we can organize our project with subdirectories (in this case, we will create a subdirectory specifically for our library). Here, we can add a new CMakeLists.txt file and all the source files. In the top level CMakeLists.txt file, we will use the add_subdirectory() command to add the subdirectory to the build.
- Create an **option** to use (or not use) the library with the value of pre-processor variable USE_MYMATH.

<br>

## Step 3
In this exercise, we will refactor our code from **Step 2** to use the modern CMake approach. We will let our library define its own **usage requirements** so they are passed **transitively** to other targets as necessary.

With these changes, all of our code still requires C++ 11 to build, but it gives us the ability to be specific about which targets get specific requirements. In addition, we create a single source of truth in our Interface library.

### Goals:
- Add the Usage Requirements for a library, that allows for far better control over a library or executable's link and include line while also giving more control over the transitive property of targets
- Set the C++ standard with Interface libraries, using a modern technique to set properties to multiple targets.

<br>

## Step 4
**Generator expressions** are evaluated during build system generation to produce **information specific** to each **build configuration**. Generator expressions may be used to enable conditional linking, conditional definitions used when compiling, conditional include directories and more. The conditions may be based on the build configuration, target properties, platform information or any other queryable information.

### Goals:
- Add Compiler warning flags when building but not for installed versions. A common usage of generator expressions is to conditionally add compiler flags, such as those for language levels or warnings. A nice pattern is to associate this information to an INTERFACE target allowing this information to propagate.

<br>

## Step 5
Often, it is not enough to only build an executable, it should also be installable. With CMake, we can specify install rules using the install() command. Supporting local installations for your builds in CMake is often as simple as specifying an install location and the targets and files to be installed.

### Goals:
- Specify install rules for the Tutorial executable and the MathFunctions library.
- Add testing support with CTest.

### Commands
To test if everything is alright run the following commands:
- cd step5_build
- cmake ../step5
- cmake --build . --config Release
- cmake --install . --config Release --prefix "C:/.../STEP_5/folder where you want to install the directories bin - include - lib"

- to make a Debug build just replace **Debug** in the **Release** values

<br>

To use the tests:
- cd step5_build
- (Release mode): ctest -C Release
- (Debug mode): ctest -C Debug -VV

<br>

## Step 6
Adding support for submitting our test results to a **dashboard** is simple. We already defined a number of tests for our project in Step 5. Now we just have to run those tests and submit them to **CDash**.

### Goals:
- Display our CTest results with CDash.

### Additional info
We will need to acquire a **CTestConfig.cmake** file to be placed in the top-level directory. When run, the ctest executable will read this file to gather information about the testing dashboard. It contains:

- The project name
- The project "Nightly" start time
  - The time when a 24 hour "day" starts for this project.
- The **URL** of the **CDash instance** where the submission's generated documents will be sent

For this tutorial, a **public dashboard server (Kitware dashboard)** is used and its corresponding CTestConfig.cmake file is provided for you in this step's root directory. In practice, this file would be downloaded from a project's Settings page on the CDash instance intended to host the test results. Once downloaded from CDash, the file should not be modified locally.

### Commands
To create the test dashboard, run the cmake command to configure the project but **do not build it**:
- cd step5_build
- cmake ../step5

Instead, navigate to the build directory and run the command:
- (Release mode): ctest [-VV] -C Release -D Experimental
- (Debug mode): ctest [-VV] -C Debug -D Experimental

After that, the ctest will build the project, run the tests, and submit the result to Kitware's public dashboard [https://my.cdash.org/index.php?project=CMakeTutorial](https://my.cdash.org/index.php?project=CMakeTutorial)

<br>

## Step 7
Now we can add some code that depends on features of the target platform. We will make use of the **check_cxx_compile_source()** command to check if a certain function/library is available for the target system.

### Goals:
- Change implementation based on system dependencies, using variables HAVE_LOG and HAVE_EXP that are set if check_cxx_compile_source() determines that the C++ source code can be built.