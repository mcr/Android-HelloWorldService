LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-java-files-under, src) \
	src/org/credil/helloworldservice/IHelloWorld.aidl

LOCAL_PACKAGE_NAME := HelloWorldService

LOCAL_REQUIRED_MODULES := libhelloworldservice
LOCAL_JNI_SHARED_LIBRARIES := libhelloworldservice

include $(BUILD_PACKAGE)

# Use the following include to make our test apk.
include $(call all-makefiles-under,$(LOCAL_PATH))
