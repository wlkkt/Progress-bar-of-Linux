#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef void(*callback_t)(double, double);//����������ָ������Ϊcallback_t,����ʾ����ͬһ�����ĺ���
void Procbar(double filesize, double current);
