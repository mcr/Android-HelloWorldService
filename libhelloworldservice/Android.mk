LOCAL_PATH := $(call my-dir)

tw_module_tags := eng user

include $(CLEAR_VARS)

LOCAL_SRC_FILES := src/helloworldservice.cpp 
LOCAL_SRC_FILES += src/helloworldclient.cpp 

LOCAL_C_INCLUDES :=         \
    $(LOCAL_PATH)/include

LOCAL_CFLAGS += -DPLATFORM_ANDROID

LOCAL_MODULE_TAGS := $(tw_module_tags)

LOCAL_MODULE := libhelloworldservice

# for now, until I do a full rebuild.
LOCAL_PRELINK_MODULE := false

# LOCAL_LDFLAGS += -llog

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils libui

LOCAL_CFLAGS += -Idalvik/libnativehelper/include/nativehelper

include $(BUILD_SHARED_LIBRARY)
