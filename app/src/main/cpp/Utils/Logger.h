#include <android/log.h>

#define _TAG "cheat_native"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,_TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,_TAG,__VA_ARGS__)