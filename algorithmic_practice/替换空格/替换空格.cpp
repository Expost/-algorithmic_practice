// 替换空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

// 自己的代码
// 这个思路很简单，就是浪费了空间，需要重新开辟一块内存出来
// 看了下别人的思路，是再在原有的基础上，向前向后移动的问题
void replaceSpace(char *str, int length) 
{
    char* tmp = new char[length + 1];
    strcpy(tmp, str);

    while (*tmp != 0)
    {
        if (*tmp == ' ')
        {
            *str++ = '%';
            *str++ = '2';
            *str++ = '0';
            tmp++;
        }
        else
        {
            *str = *tmp;
            str++;
            tmp++;
        }
    }

    *str = 0;
}

int main()
{
    char str[1024] = " helloworld";
    replaceSpace(str, strlen(str));
    printf("str is \"%s\"\n", str);

    getchar();
    return 0;
}

