cmake_minimum_required(VERSION 3.5.0)
project(py_leetcode VERSION 0.1.0 LANGUAGES C CXX)

# 设置源文件的根目录
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# 定义任务子目录
set(TASKS dfs stack dp prefix)

# 遍历任务目录并配置独立的构建目标
foreach(TASK ${TASKS})
    # 获取该任务目录下的所有 .cpp 文件
    file(GLOB TASK_SOURCES ${SRC_DIR}/${TASK}/*.cpp)
    
    # 为每个 .cpp 文件创建单独的目标
    foreach(SOURCE_FILE ${TASK_SOURCES})
        # 获取文件名（不含路径和扩展名）
        get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
        
        # 创建单独的可执行文件
        add_executable(${TASK}_${FILE_NAME} ${SOURCE_FILE})

        # 指定输出目录
        set_target_properties(${TASK}_${FILE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${TASK}
        )
    endforeach()
endforeach()