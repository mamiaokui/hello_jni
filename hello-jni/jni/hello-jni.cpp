#include <string.h>
#include <jni.h>
#include "JNIHelp.h"
#include <android/log.h>

int add(JNIEnv * env, jobject obj, int a, int b)
{
	__android_log_print(ANDROID_LOG_DEBUG, "mamk", "add a=%d b=%d ", a, b);
    return a+b;
}


static JNINativeMethod g_javaMethods[] = {
	{ "nativeTest", "(II)I",
        (void*) add },
};


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*)
{
    JNIEnv * env;
    if(JNI_OK != vm->AttachCurrentThread(&env,NULL))
    {
        return JNI_VERSION_1_6;
    }

    jniRegisterNativeMethods(env, "com/example/hello_jni/MainActivity",
            g_javaMethods, NELEM(g_javaMethods));


    return JNI_VERSION_1_6;
}
