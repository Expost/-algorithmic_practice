// 替换空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

// 自己的代码
// 这个思路很简单，就是浪费了空间，需要重新开辟一块内存出来
// 看了下别人的思路，是再在原有的基础上，从前从后移动的实现
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

// 自己实现的从后移动的代码，从前移动的代码由于移动操作太多，因此不再考虑
// 看了下别人的实现，用指针更加简单一些，自己用下标偏复杂了😂
void ReplaceSpace(char *str, int length)
{
    int total_space_count = 0;
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == ' ')
            total_space_count++;
    }

    int new_str_len = str_len - total_space_count + total_space_count * 3;// 3为%20的长度

    // 以下到END0为下标实现
    //str[new_str_len] = 0;
    //int space_index = 0;
    //for (int i = 0; i < str_len; i++)
    //{
    //    int index = str_len - i - 1;
    //    int new_index = new_str_len - i - 1 - space_index * 2;
    //    if (str[index] != ' ')
    //    {
    //        str[new_index] = str[index];
    //    }
    //    else
    //    {
    //        space_index++;
    //        str[new_index] = '0';
    //        str[new_index - 1] = '2';
    //        str[new_index - 2] = '%';
    //    }
    //}
    // END0

    // 以下到END1用指针实现
    char *new_str_ptr = str + new_str_len;
    char *old_str_ptr = str + str_len;
    while (str_len >= 0)
    {
        if (*old_str_ptr == ' ')
        {
            *new_str_ptr-- = '0';
            *new_str_ptr-- = '2';
            *new_str_ptr-- = '%';
            old_str_ptr--;
        }
        else
        {
            *new_str_ptr-- = *old_str_ptr--;
        }

        str_len--;
    }
    // END1
}


int main()
{
    char str[1024] = " hellowo rld ";
    ReplaceSpace(str, strlen(str));
    printf("str is \"%s\"\n", str);

    getchar();
    return 0;
}

