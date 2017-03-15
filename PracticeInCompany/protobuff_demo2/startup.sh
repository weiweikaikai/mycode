#!/bin/bash

    kill -TERM `ps -ef | grep "AsynServ ./bench.conf" | grep -v 'grep' | awk '{print $2}'`
    sleep 1
    protoc --cpp_out=. msg.proto    #生成对应的msg.pb.h和msg.pb.cpp文件
#    g++ echo.c msg.pb.cc -o service  -lprotobuf
    ./AsynServ ./bench.conf
