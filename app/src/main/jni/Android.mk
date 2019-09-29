LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := native-lib
LOCAL_SRC_FILES := native-lib.cpp
LOCAL_LDLIBS    := -llog
LOCAL_ADDRESS_SANITIZER:=true


LOCAL_CFLAGS    := -fsanitize=address -fno-omit-frame-pointer
LOCAL_LDFLAGS   := -fsanitize=address
LOCAL_ARM_MODE := arm

#LOCAL_CFLAGS=-fno-omit-frame-pointer
#LOCAL_ARM_MODE := arm
#APP_STL := gnustl_shared


APP_CPPFLAGS := -fexceptions
include $(BUILD_SHARED_LIBRARY)