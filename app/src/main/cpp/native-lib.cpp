#include <jni.h>
#include <string>

#include "utils/LogUtils.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_jar_cpp_startactivity_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jar_cpp_startactivity_MainActivity_enterTarget(JNIEnv *env, jobject mainObject) {
    jclass mainClass = env->GetObjectClass(mainObject);
    jmethodID getPackageNameId = env->GetMethodID(mainClass, "getPackageName",
                                                  "()Ljava/lang/String;");
    auto pkgName = (jstring) env->CallObjectMethod(mainObject, getPackageNameId);
    NATIVE_LOGCAT_D("pkgName :%s", env->GetStringUTFChars(pkgName, JNI_FALSE))

    //获取 Intent 的 Class，并获取 Intent 的构造函数，调用构造函数，获取intent 对象
    jclass intentClass = env->FindClass("android/content/Intent");
    jmethodID newIntent = env->GetMethodID(intentClass, "<init>", "()V");
    jobject intentObject = env->NewObject(intentClass, newIntent);
    env->CallVoidMethod(intentObject, newIntent);
    jmethodID setFlagsId = env->GetMethodID(intentClass, "setFlags",
                                            "(I)Landroid/content/Intent;");
    env->CallObjectMethod(intentObject, setFlagsId, 0x10000000);

    // put parameter
    jmethodID putExtraId = env->GetMethodID(intentClass, "putExtra",
                                            "(Ljava/lang/String;I)Landroid/content/Intent;");
    jstring pOne_key = env->NewStringUTF("main_key");
    env->CallObjectMethod(intentObject, putExtraId, pOne_key, 16838678);
    //获取 ComponentName 类，并获取该类构造函数
    jclass componentClass = env->FindClass("android/content/ComponentName");
    jmethodID componentMID = env->GetMethodID(componentClass, "<init>",
                                              "(Ljava/lang/String;Ljava/lang/String;)V");
    //获取需要打开的Activity 全名称，路径用点
    jstring clsName = env->NewStringUTF("com.jar.cpp.startactivity.SecondActivity");
    //获取 ComponentName 构造函数并调用
    jobject componentObj = env->NewObject(componentClass, componentMID, pkgName, clsName);
    env->CallVoidMethod(componentObj, componentMID, pkgName, clsName);

    //调用 intent 的 setComponent 方法，将 component 设置其中
    jmethodID setComponentName = env->GetMethodID(intentClass, "setComponent",
                                                  "(Landroid/content/ComponentName;)Landroid/content/Intent;");
    env->CallObjectMethod(intentObject, setComponentName, componentObj);

    //获取Activity 类，并调用 startActivity 方法
    jclass activityClass = env->FindClass("android/app/Activity");
    jmethodID startActivity = env->GetMethodID(activityClass, "startActivity",
                                               "(Landroid/content/Intent;)V");

    env->CallVoidMethod(mainObject, startActivity, intentObject);


}