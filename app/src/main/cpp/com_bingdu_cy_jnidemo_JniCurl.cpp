//
// Created by cylin on 2017/8/8.
//

#include <jni.h>
#include <thread>
#include "DownloadModule.h"
#include <android/log.h>
#define LOG_TAG "JNI_LOG"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C"
{
void performActions()
{
    MyDownloadModule download;
    const char* url = "http://116.62.119.70:8081/hxjz.apk";
    int nRet = download.DownLoad(url, "/storage/emulated/0/", "hxjz.apk");
    if (nRet == 0) {
        LOGI("download success!");
    }
    else {
        LOGE("download error code:%d", nRet);
    }
}

//jobject g_objAc = NULL;
void Java_com_wr_jnidownload_MainActivity_Download(JNIEnv* env,
                                                         jobject obj)
{
    std::thread action(performActions);
    action.detach();

}
/*size_t PostDispose(char *buffer, size_t size, size_t nmemb, void *userdata)
{
    JNIUtil util;
    jobject jdata = util.String2Jstring(buffer);
    JNIEnv* env = util.GetJNIEnv();
    jclass cMainActivity = env->GetObjectClass(g_objAc);
    jmethodID methodPostDispose = env->GetMethodID(cMainActivity, "postDispose",
                                                   "(Ljava/lang/String;)V");
    env->CallVoidMethod(g_objAc, methodPostDispose, jdata);
    return nmemb;
}
void Java_com_bingdu_cy_jnidemo_JniCurl_MyHttpPost(JNIEnv* env,
                                                         jobject obj)
{
    HttpPostModule post;
    post.SetTimeOut(60);
    post.SetHttpHead("Content-Type:application/json;charset=UTF-8");
    post.SetWriteFunction(PostDispose);
    post.SetURL("http://api.map.baidu.com/place/v2/suggestion?query=tiananmen&region=131&output=json&ak=fTF5Wt01MNLs7ci9G9G6X76d");
    int nRet = post.SendPostRequest();
    if (nRet == 0)
        LOGI("post success!");
    else
        LOGE("post error code:%d", nRet);
}
void Java_com_bingdu_cy_jnidemo_JniCurl_Init(JNIEnv* env, jobject obj)
{
    HttpPostModule::Init();
    JavaVM* vm;
    env->GetJavaVM(&vm);
    JNIUtil::Init(env);
    g_objAc = env->NewGlobalRef(obj);
}
void Java_com_bingdu_testjni_TestJNI_Cleanup(JNIEnv* env, jobject obj)
{
    HttpPostModule::Cleanup();
    env->DeleteGlobalRef(g_objAc);
    g_objAc = NULL;
    JNIUtil::CleanUp(env);
}*/
}