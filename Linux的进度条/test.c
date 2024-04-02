#include  "Processbar.h"

double bandwidth = (1024 * 1024) / 8 * 1.0;//�涨��ǰ��������Ϊ:1Mb/s
//�ļ����س���
void download(double filesize, callback_t cb)//cb��callback_t���͵�һ������ָ���������ָ�����callback_t���͵ĺ���
{//���뺯��ָ�룬���ڵ������������´�ӡ�ַ���ʱ��ͼ�λ����棩ֻ��Ҫ���±���������Ľ�������ʵ�ַ�������
    double current = 0.0; //�ۼ����ص�������
    printf("download begin.current: %lf\n", current);
    while (current <= filesize)//�ۼ�����������С���ļ���С�ͼ�������
    {
        cb(filesize, current);//����Ŀ���ļ���С�͵�ǰ���ش�С��̬�γɽ�����
        usleep(10000);//�䵱�����л�ȡ����ʱ���ӳ�,0.5��
        //�������л�ȡ����
        current += bandwidth;//���ݴ���õ����������ۼ�
    }
    printf("\ndownload done,filesize: %lf\n", filesize);//���������ļ���С

}

int main()
{
    //Procbar();
    download(100 * 1024 * 1024, Procbar);//����Ҫ�����ļ��Ĵ�С����Ӧ�Ĵ�ӡ�������ķ�ʽ
    download(2 * 1024 * 1024, Procbar);//����Ҫ�����ļ��Ĵ�С����Ӧ�Ĵ�ӡ�������ķ�ʽ
    download(200 * 1024 * 1024, Procbar);//����Ҫ�����ļ��Ĵ�С����Ӧ�Ĵ�ӡ�������ķ�ʽ
    download(400 * 1024 * 1024, Procbar);//����Ҫ�����ļ��Ĵ�С����Ӧ�Ĵ�ӡ�������ķ�ʽ
    download(50 * 1024 * 1024, Procbar);//����Ҫ�����ļ��Ĵ�С����Ӧ�Ĵ�ӡ�������ķ�ʽ
    download(10 * 1024 * 1024, Procbar);//����Ҫ�����ļ��Ĵ�С����Ӧ�Ĵ�ӡ�������ķ�ʽ
    return 0;
}
