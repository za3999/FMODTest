#include <jni.h>
#include <string>
#include "log.h"

void testMethod(JNIEnv *env, jclass cls, jstring text) {
    LOGD("testMethod");
    const char *value = env->GetStringUTFChars(text, nullptr);
    LOGD(value);
}

static const JNINativeMethod methods[] = {
        {"testDynamicMethod", "(Ljava/lang/String;)V", (void *) (testMethod)}
};

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    jclass clazz = env->FindClass("com/test/dynamicmethod/TestUtil");
    env->RegisterNatives(clazz, methods, 1);
    return JNI_VERSION_1_6;
}

