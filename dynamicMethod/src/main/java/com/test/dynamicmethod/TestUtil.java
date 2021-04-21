package com.test.dynamicmethod;

public class TestUtil {

    static {
        System.loadLibrary("native-lib");
    }

    public static native void testDynamicMethod(String text);
}
