#include "native.h"
#include <unistd.h>

using namespace FMOD;

#define LOGD(message) __android_log_write(ANDROID_LOG_DEBUG, "native", message);

void addDsp(int mode, System *system, Channel *channel);

extern "C" JNIEXPORT void JNICALL
Java_com_test_fmodtest_FModUtil_changeVoices(JNIEnv *env, jobject object, jint mode, jstring path,
                                             jobject callBack) {
    const char *path_ = env->GetStringUTFChars(path, NULL);
    LOGD(path_);

    System *system = 0;  // 音效引擎系统
    Sound *sound = 0; // 声音
    Channel *channel = 0;  // 通道，音轨
    //创建系统
    System_Create(&system);
    //系统的初始化 参数1：最大音轨数，  参数2：系统初始化标记， 参数3：额外数据
    system->init(32, FMOD_INIT_NORMAL, 0);
    //创建声音  参数1：路径，  参数2：声音初始化标记， 参数3：额外数据， 参数4：声音指针
    system->createSound(path_, FMOD_DEFAULT, 0, &sound);
    //播放声音 参数1：声音，参数2：分组音轨， 参数3：控制， 参数4：通道
    system->playSound(sound, 0, false, &channel);
    addDsp(mode, system, channel);

    bool isPlayer = true; // 你用不是一级指针  我用一级指针接收你，可以修改给你
    while (isPlayer) {
        channel->isPlaying(&isPlayer); // 如果真的播放完成了，音轨是知道的，内部会修改isPlayer=false
        usleep(1000 * 1000); // 每个一秒
    }

    jclass clazz = env->GetObjectClass(callBack);
    jmethodID methodId = env->GetMethodID(clazz, "onFinish", "()V");
    env->CallVoidMethod(callBack, methodId);

    sound->release();
    system->close();
    system->release();
    env->ReleaseStringUTFChars(path, path_);
}

void addDsp(int mode, System *system, Channel *channel) {
    DSP *dsp = 0;   // DSP：digital signal process
    system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
    // 2.设置Pitch音调调节2.0
    dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.0f);
    // 3.添加音效进去 音轨
    channel->addDSP(0, dsp);
}
