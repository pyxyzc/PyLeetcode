#!/bin/bash

# 设置构建输出目录
BUILD_DIR="out/dev"

# 如果构建目录不存在，则创建
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# 进入构建目录
cd "$BUILD_DIR" || exit 1

# 运行 cmake 配置生成 Makefile
echo "Running cmake..."
cmake ../../ || { echo "CMake configuration failed"; exit 1; }

# 运行 make 编译所有目标
echo "Running make..."
make -j$(nproc) || { echo "Build failed"; exit 1; }

# 打印成功消息
echo "Build completed successfully!"
echo "Executables are available in ${BUILD_DIR}/build/<TASK>/"