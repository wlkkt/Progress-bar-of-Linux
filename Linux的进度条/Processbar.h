#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef void(*callback_t)(double, double);//重命名函数指针类型为callback_t,它表示具有同一特征的函数
void Procbar(double filesize, double current);
