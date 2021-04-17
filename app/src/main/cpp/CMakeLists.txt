cmake_minimum_required(VERSION 3.10.2)

project("fmodtest")

# TODO 导入头文件
include_directories("inc")
# TODO 导入库文件
# CMAKE_SOURCE_DIR == CMakeLists.txt所在的路径
# CMAKE_ANDROID_ARCH_ABI == 当前的CPU架构
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")

# TODO 批量导入所有源文件
file(GLOB allFile *.c *.h *.cpp)
add_library(
        native-lib
        SHARED
        ${allFile})

target_link_libraries(
        native-lib
        log
        fmod
        fmodL)