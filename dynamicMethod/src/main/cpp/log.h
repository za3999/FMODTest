#include "android/log.h"

#define LOGD(message) __android_log_write(ANDROID_LOG_DEBUG, "native", message)
#define LOGE(message) __android_log_write(ANDROID_LOG_ERROR, "native", message)