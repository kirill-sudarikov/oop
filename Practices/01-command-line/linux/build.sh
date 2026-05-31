#!/bin/bash

mkdir -p build/linux

gcc -o build/linux/practice1 main.c

if [ $? -eq 0 ]; then
    build/linux/practice1
fi
