#include "Processbar.h"

#define Length 101 //�������������
#define Style '~' //ѡ�����������

const char* lable = "|/-\\";//�����ת��̬Ч��

//�汾һ:
//void Procbar()
//{
//  char bar[Length];//����
//  memset(bar,'\0',sizeof(bar));//���ַ�����������\0
//  int len = strlen(lable);//����
//
//  int cnt = 0;
//  while(cnt <= 100)
//  {       //[����һ�ٸ�λ�ô�ӡbar�����е��ַ�][��������λ�ô�ӡ�ַ���ӡ����ͬʱ��ʾ��%]
//          //[��ӡ��̬��ת�ַ�]
//    printf("[%-100s][%3d%%][%c]\r",bar,cnt,lable[cnt%len]);//��ֹ��ӡ��ת�ַ�ʱԽ��
//    fflush(stdout);//ǿ�Ƹ���
//    bar[cnt++] = Style;//��bar�����в��ϵؼ����ַ�
//    usleep(20000);//ÿ�θ�������0.02��
//  }
//printf("\n");
//}

//�汾��:��ֻ����������download�������������ݲ��������ݴ�ӡ����������ݣ�
void Procbar(double filesize, double current)
{

    char bar[Length];
    memset(bar, '\0', sizeof(bar));
    int len = strlen(lable);

    int cnt = 0;
    double rate = (current * 100) / filesize;//���ؽ���,���Ҳ�������ǿתΪ����,*100����Ϊǿ������ת��ʱ�Ὣ������0.5��Ϊ0
    int loop_count = (int)rate;//��Ӧ��ѭ���Ĵ���
    while (cnt <= loop_count)
    {
        bar[cnt++] = Style;//��bar�����в��ϵؼ����ַ�
    }
    //[����һ�ٸ�λ�������ӡbar�����е��ַ�][��������λ�ô�ӡ�ַ���ӡ����ͬʱ��ʾ��%][��ӡ��̬��ת�ַ�]     
    printf("[%-100s][%.1lf%%][%c]\r", bar, rate, lable[cnt % len]);//��ֹ��ӡ��ת�ַ�ʱԽ��,����֮���ٸ��Ǵ�ӡ
    fflush(stdout);//ǿ�Ƹ���
}
