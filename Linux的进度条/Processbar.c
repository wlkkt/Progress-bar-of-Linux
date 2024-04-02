#include "Processbar.h"

#define Length 101 //定义进度条长度
#define Style '~' //选择进度条符号

const char* lable = "|/-\\";//添加旋转动态效果

//版本一:
//void Procbar()
//{
//  char bar[Length];//创建
//  memset(bar,'\0',sizeof(bar));//将字符数组中填满\0
//  int len = strlen(lable);//计算
//
//  int cnt = 0;
//  while(cnt <= 100)
//  {       //[留出一百个位置打印bar数组中的字符][留出三个位置打印字符打印进度同时显示出%]
//          //[打印动态旋转字符]
//    printf("[%-100s][%3d%%][%c]\r",bar,cnt,lable[cnt%len]);//防止打印旋转字符时越界
//    fflush(stdout);//强制覆盖
//    bar[cnt++] = Style;//向bar数组中不断地加入字符
//    usleep(20000);//每次覆盖休眠0.02秒
//  }
//printf("\n");
//}

//版本二:（只是用来接收download函数传来的数据并根据数据打印不会更改数据）
void Procbar(double filesize, double current)
{

    char bar[Length];
    memset(bar, '\0', sizeof(bar));
    int len = strlen(lable);

    int cnt = 0;
    double rate = (current * 100) / filesize;//下载进度,将右侧运算结果强转为整型,*100是因为强制类型转换时会将浮点数0.5变为0
    int loop_count = (int)rate;//本应当循环的次数
    while (cnt <= loop_count)
    {
        bar[cnt++] = Style;//向bar数组中不断地加入字符
    }
    //[留出一百个位置正向打印bar数组中的字符][留出三个位置打印字符打印进度同时显示出%][打印动态旋转字符]     
    printf("[%-100s][%.1lf%%][%c]\r", bar, rate, lable[cnt % len]);//防止打印旋转字符时越界,放完之后再覆盖打印
    fflush(stdout);//强制覆盖
}
