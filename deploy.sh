#!/bin/sh

set -e
cd ../../.. 
adb push out/target/product/generic/system/bin/helloworldservice /data
adb push out/target/product/generic/system/bin/helloworldclient /data
adb push out/target/product/generic/system/lib/libhelloworldservice.so /system/lib 

