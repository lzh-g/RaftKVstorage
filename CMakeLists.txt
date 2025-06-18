cmake_minimum_required(VERSION 3.10)
project(KVRaftCpp)

set(CMAKE_CXX_STANDARD 20)

# 生成debug版本，进行gdb调试
set(CMAKE_BUILD_TYPE "Debug")

# 设置项目可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置项目库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置项目编译头文件搜索路径 -I
include_directories(${PROJECT_SOURCE_DIR}/include/Common)
include_directories(${PROJECT_SOURCE_DIR}/include/Fiber)
include_directories(${PROJECT_SOURCE_DIR}/include/RaftClerk)
include_directories(${PROJECT_SOURCE_DIR}/include/RaftCore)
include_directories(${PROJECT_SOURCE_DIR}/include/RaftRpcPro)
include_directories(${PROJECT_SOURCE_DIR}/include/Rpc)
include_directories(${PROJECT_SOURCE_DIR}/include/SkipList)

# 设置项目库文件搜索路径 -L
link_directories(${PROJECT_SOURCE_DIR}/lib)

# src包含了所有相关代码
add_subdirectory(src)
# example包含了使用的示例代码
add_subdirectory(example)

# add_library(skip_list_on_raft STATIC ${src_rpc} ${src_fiber} ${rpc_example} ${raftsource} ${src_raftCore} ${src_raftRpcPro})
# target_link_libraries(skip_list_on_raft muduo_net muduo_base pthread dl)

# add_custom_target(format
#         COMMAND bash ${PROJECT_SOURCE_DIR}/format.sh
#         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
#         COMMAND echo "format done!"
# )