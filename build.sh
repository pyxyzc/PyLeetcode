#!/bin/bash

# 设置构建输出目录
BUILD_DIR="./build"

# Check if the folder exists
if [ -d "$BUILD_DIR" ]; then
    # Delete all files inside the folder
    rm -rf "$BUILD_DIR"/*
    echo "All files inside build folder have been deleted."
else
    echo "No build folder now."
fi

# 如果构建目录不存在，则创建
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# 进入构建目录
cd "$BUILD_DIR" || exit 1

# 运行 cmake 配置生成 Makefile
echo "Running cmake..."
cmake .. || { echo "CMake configuration failed"; exit 1; }

# 运行 make 编译所有目标
echo "Running make..."
make -j$(nproc) || { echo "Build failed"; exit 1; }

# 打印成功消息
echo "Build completed successfully!"
echo "Executables are available in ${BUILD_DIR}/<TASK>/"