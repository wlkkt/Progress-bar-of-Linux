#include  "Processbar.h"

double bandwidth = (1024 * 1024) / 8 * 1.0;//规定当前下载网速为:1Mb/s
//文件下载场景
void download(double filesize, callback_t cb)//cb是callback_t类型的一个函数指针变量，它指向具有callback_t类型的函数
{//传入函数指针，便于当在其它环境下打印字符串时（图形化界面）只需要重新编符合条件的进度条的实现方法就行
    double current = 0.0; //累计下载的数据量
    printf("download begin.current: %lf\n", current);
    while (current <= filesize)//累计下载数据量小于文件大小就继续下载
    {
        cb(filesize, current);//根据目标文件大小和当前下载大小动态形成进程条
        usleep(10000);//充当网络中获取数据时的延迟,0.5秒
        //从网络中获取数据
        current += bandwidth;//根据带宽得到下载量并累加
    }
    printf("\ndownload done,filesize: %lf\n", filesize);//最终下载文件大小

}

int main()
{
    //Procbar();
    download(100 * 1024 * 1024, Procbar);//传入要下载文件的大小和相应的打印进度条的方式
    download(2 * 1024 * 1024, Procbar);//传入要下载文件的大小和相应的打印进度条的方式
    download(200 * 1024 * 1024, Procbar);//传入要下载文件的大小和相应的打印进度条的方式
    download(400 * 1024 * 1024, Procbar);//传入要下载文件的大小和相应的打印进度条的方式
    download(50 * 1024 * 1024, Procbar);//传入要下载文件的大小和相应的打印进度条的方式
    download(10 * 1024 * 1024, Procbar);//传入要下载文件的大小和相应的打印进度条的方式
    return 0;
}
