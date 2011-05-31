LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := main_helloworldclient.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../libhelloworldservice/include

LOCAL_CFLAGS += -DPLATFORM_ANDROID

LOCAL_MODULE := helloworldclient
LOCAL_MODULE_TAGS := optional

# for now, until I do a full rebuild.
LOCAL_PRELINK_MODULE := false

# LOCAL_LDFLAGS += -llog

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils libui libbinder
LOCAL_SHARED_LIBRARIES += libhelloworldservice

LOCAL_CFLAGS += -Idalvik/libnativehelper/include/nativehelper

include $(BUILD_EXECUTABLE)

