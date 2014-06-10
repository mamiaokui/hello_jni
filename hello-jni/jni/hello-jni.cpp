#include <string.h>
#include <jni.h>
#include "JNIHelp.h"
#include <android/log.h>

static const char* className = "com/example/hello_jni/MainActivity";
int add(JNIEnv * env, jobject obj, int a, int b)
{
    jclass clazz = env->FindClass(className);
    if (clazz == 0) {
        return 0;
    }
    jmethodID javamethod = env->GetMethodID(clazz, "fakeResult", "()Z");
    if (javamethod == 0) {
        LOGI("GetMethodID error");
        return 0;
    }
    jboolean fake = env->CallBooleanMethod(obj, javamethod);

	__android_log_print(ANDROID_LOG_DEBUG, "mamk", "add a=%d b=%d fackResult=%d", a, b, fake?1:0);

    if (fake)
        return a-b;
    else
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

    jniRegisterNativeMethods(env, className,
            g_javaMethods, NELEM(g_javaMethods));


    return JNI_VERSION_1_6;
}
