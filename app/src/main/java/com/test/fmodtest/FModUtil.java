package com.test.fmodtest;

import android.content.Context;

import org.fmod.FMOD;

public class FModUtil {

    private static FModUtil ins;

    public FModUtil(Context mContext) {
        System.loadLibrary("native-lib");
        FMOD.init(mContext.getApplicationContext());
    }

    public static FModUtil ins(Context context) {
        if (ins == null) {
            synchronized (FModUtil.class) {
                if (ins == null) {
                    ins = new FModUtil(context);
                }
            }
        }
        return ins;
    }

    public native void changeVoices(int model, String path, CallBack callBack);

    interface CallBack {
        void onFinish();
    }
}
