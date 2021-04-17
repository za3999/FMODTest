#include <jni.h>
#include <string>
#include "android/log.h"
#include <fmod.hpp>

#ifndef FMODTEST_NATIVE_H
#define FMODTEST_NATIVE_H
#endif
extern "C" JNIEXPORT void JNICALL Java_com_test_fmodtest_FModUtil_changeVoices
        (JNIEnv *, jobject, jint, jstring);


