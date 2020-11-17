#!/bin/sh

for file in `find . -name "*.c" -o -name "*.cpp" -o -name "*.h"`
do
  clang-format -verbose -style=llvm -i $file
done
