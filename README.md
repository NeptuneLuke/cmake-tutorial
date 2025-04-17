# A CMake official tutorial, step by step

This is a collection of all the steps in the official [CMake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/). Following this tutorial step by step will give you a basic but useful overview of most CMake use cases.

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
- Add a library.
- Create an **option** to use (or not use) the library with the value of pre-processor variables.

<br>

## Step 3
In this exercise, we will refactor our code from **Step 2** to use the modern CMake approach. We will let our library define its own **usage requirements** so they are passed **transitively** to other targets as necessary.

With these changes, all of our code still requires C++ 11 to build, but it gives us the ability to be specific about which targets get specific requirements. In addition, we create a single source of truth in our Interface library.

### Goals:
- Add the Usage Requirements for a library, that allows for far better control over a library or executable's link and include line while also giving more control over the transitive property of targets
- Set the C++ standard with Interface libraries, using a modern technique to set properties to multiple targets.

