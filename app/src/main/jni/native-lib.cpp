#include <jni.h>
#include <string>
#include <stdlib.h>

#include <android/log.h>



#define LOG_TAG "debug log"
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

//#define LOGI(...) ALOGI(__VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_water_nativeapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
   std::string hello = "Hello from Cccc++";
   // std::string hellocc = NULL;
    //int* p = 0; //空指针
    //*p = 1; //写空指针指向的内存，产生SIGSEGV信号，造成Crash
   char *p=NULL;
    p= (char *)malloc(3000);
    sprintf(p,"%s","Hello from Ccc++\n");
    int *ppp= (int *)malloc(4000);
    int *pp=  (int *)malloc(5000);
    *ppp=100;
    *pp=300;

//    free(ppp);
//    free(pp);

//    sprintf(p,"%s","Hello from Ccc++\n");//"Hello from C++\n"写入a指向的地址
//    sprintf(pp,"%s","Hello from Cccccc++\n");//"Hello from C++\n"写入a指向的地址
//    LOGI("test===========================");
//    LOGI("test======================= %s",n[5]);




    // Use after free：使用已释放的内存
//    int *array = new int[100];
//    delete [] array;
//    int a = array[2];
//    hello.operator+=(a);

    // Heap buffer overflow：使用超出了申请空间的堆内存
//    int *array = new int[1];
//    array[0] = 0;
//    int res = array[1100];  // BOOM
//    delete [] array;
//    hello.operator+=(res);

    // Stack buffer overflow：使用超出了申请空间的栈内存
//    int stack_array[100];
//    stack_array[1] = 0;
//    int s = stack_array[(rand() % (1000-100))+ 100];
//    hello.operator+=(s);

    // 不接入AddressSanitizer的情况下，模拟数组越界，因为"C++数组越界不检查"，
    // 一般来说，会打印出一个不确定的整数，直到在打印某个元素的时候，出现了 “segmentation fault”.
    // 所以这里循环的上限很大
//    int *ptr;
//    ptr = (int*) malloc(2);
//    for (int i=0; i< 10000000; i++)
//    {
//        ptr[i] = i;
//    }
//
//    int *ptr = (int*)malloc(sizeof(int) * 3);
//    ptr[4] = 6;

    return env->NewStringUTF(hello.c_str());
}
