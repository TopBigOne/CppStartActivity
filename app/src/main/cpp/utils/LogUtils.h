//
// Created by DEV on 9/4/23.
//

#ifndef TESTNDKNETWORK_CLOGUTILS_H
#define TESTNDKNETWORK_CLOGUTILS_H

#include <android/log.h>
#include <jni.h>
#include <string>

static bool IS_BUILD_DEBUG = true;

#define  LOG_TAG "NativeTask"

#define NATIVE_LOGCAT_V(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__);
#define NATIVE_LOGCAT_I(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__);
#define NATIVE_LOGCAT_D(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__);
#define NATIVE_LOGCAT_W(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__);
#define NATIVE_LOGCAT_E(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__);


#define  LOGI(...)   \
    if(IS_BUILD_DEBUG){    \
          NATIVE_LOGCAT_I(__VA_ARGS__);\
    }\

#define  LOGV(...){ \
    if(IS_BUILD_DEBUG){    \
          NATIVE_LOGCAT_V(__VA_ARGS__);\
    }\
}

#define LOGD(...)\
    if(IS_BUILD_DEBUG){    \
           NATIVE_LOGCAT_D(__VA_ARGS__);\
    }

#define  LOGE(...)\
    if(IS_BUILD_DEBUG){    \
           NATIVE_LOGCAT_E(__VA_ARGS__);\
    }

#define  LOGW(...)\
    if(IS_BUILD_DEBUG){    \
           NATIVE_LOGCAT_W(__VA_ARGS__);\
    }


#endif //TESTNDKNETWORK_CLOGUTILS_H
