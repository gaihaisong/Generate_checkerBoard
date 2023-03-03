#添加OPENCV库
#指定OpenCV版本，代码如下
#find_package(OpenCV 3.3 REQUIRED)
#如果不需要指定OpenCV版本，代码如下
project(main)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#添加OpenCV头文件
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
#显示OpenCV_INCLUDE_DIRS的值
message(${OpenCV_INCLUDE_DIRS})
 

# set(HDRS_PnpSolver
#   pnp_solver.h)
# set(SRC_PNPSOLVER
#   pnp_solver.cpp)

# add_library(DPnpSolver SHARED ${SRC_PNPSOLVER})
# 添加一个可执行程序
# 语法：add_executable( 程序名 源代码文件 ）
add_executable( main main3.cpp )
 
# 将库文件链接到可执行程序上
# target_link_libraries( main3 DPnpSolver ${OpenCV_LIBS})
target_link_libraries( main ${OpenCV_LIBS})