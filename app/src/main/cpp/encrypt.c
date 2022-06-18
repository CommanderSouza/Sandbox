//
// Created by Ricardo on 11-Jun-22.
//

#include <string.h>
#include <jni.h>

void encrypt(char *message){
    while (*message) {
        *message = *message ^ 31;
        message++;
    }
}

int checksum(char *message){
    int c = 0;
    while (*message) {
        c += c ^ (int)(*message);
        message++;
    }

    return c;
}

JNIEXPORT jstring JNICALL
Java_com_commandersouza_sandbox_MainActivity_00024Companion_encryptText(JNIEnv *env, jobject thiz,
                                                                        jstring txt) {

    const char *msgReceived = (*env)->GetStringUTFChars(env, txt, NULL);
    char msg[25];
    memset(msg, '\0', sizeof(msg));
    strncpy(msg,msgReceived,sizeof(msg)-1);

    (*env)->ReleaseStringUTFChars(env, txt, msgReceived);

    encrypt(msg);

    return ((*env)->NewStringUTF(env, msg));
}

JNIEXPORT jint JNICALL
Java_com_commandersouza_sandbox_MainActivity_00024Companion_checksumText(JNIEnv *env, jobject thiz,
                                                                         jstring txt) {
    const char *msgReceived = (*env)->GetStringUTFChars(env, txt, NULL);
    char msg[25];
    memset(msg, '\0', sizeof(msg));
    strncpy(msg,msgReceived,sizeof(msg)-1);

    (*env)->ReleaseStringUTFChars(env, txt, msgReceived);

    int c = checksum(msg);

    return (c);
}