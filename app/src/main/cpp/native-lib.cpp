#include "native.h"

using namespace FMOD;

#define LOGD(message) __android_log_write(ANDROID_LOG_DEBUG, "native", message);

extern "C" JNIEXPORT void JNICALL
Java_com_test_fmodtest_FModUtil_changeVoices(JNIEnv *env, jobject object, jint mode, jstring path) {
    char *hello = "Hello from C++";
    LOGD(hello)
}