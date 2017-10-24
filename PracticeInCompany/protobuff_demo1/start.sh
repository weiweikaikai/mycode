#!/bin/bash
    protoc --cpp_out=. msg.proto    #生成对应的msg.pb.h和msg.pb.cpp文件
    g++ protobuff_demo.cc msg.pb.cc -o protobuff_test  -lprotobuf

    ./protobuff_test 
    rm -rf ./protobuff_test msg.pb.cc msg.pb.h
