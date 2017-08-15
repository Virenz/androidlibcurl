//
// Created by cylin on 2017/8/1.
//

//自己创建一个c文件，实现自己定义的native方法，也就是.h文件中的方法
//引入自己生成的.h头文件
#include "com_bingdu_cy_jnidemo_Hello.h"

#define __DEBUG__
//返回一个字符串
JNIEXPORT jstring JNICALL Java_com_bingdu_cy_jnidemo_Hello_hello
  (JNIEnv * env, jclass thiz){



}

JNIEXPORT void JNICALL Java_com_bingdu_cy_jnidemo_Hello_download
(JNIEnv* env,jobject obj){

//    HttpRequest* http = new HttpRequest();
//    char http_return[4096] = {0};
//    char http_msg[4096] = {0};
//    strcpy(http_msg, "http://116.62.119.70:8081/hxjz.apk");
//    printf("11111111111",http_msg);
//    if(http->HttpGet(http_msg, http_return)){
//    printf("jni:%s", http_return);
//
//    }
//    delete http;

}

//返回 a+b的结果
JNIEXPORT jint JNICALL Java_com_bingdu_cy_jnidemo_Hello_add
  (JNIEnv *env, jclass jobj, jint a, jint b){
  return a+b;
}
