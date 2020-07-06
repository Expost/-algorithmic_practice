#include <stdio.h>
#include <string>
using namespace std;

int myAtoi(string str) {
    int64_t ret = 0;
    int flag = 1;
    bool start_flag = true;
    for (int i = 0; i < str.size();i++) {
        if(str[i] == ' ' && start_flag)
            continue;
        
        if (str[i] == '-' && start_flag) {
            flag = -1;
        }
        else if (str[i] == '+' && start_flag) {
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            ret = ret * 10 + (str[i] - '0') * flag;
        }
        else{
            break;
        }

        if (ret > INT_MAX) {
            ret = INT_MAX;
            break;
        }
        if (ret < INT_MIN) {
            ret = INT_MIN;
            break;
        }

        start_flag = false;
    }

    return ret;
}

int main() {
    string s;
    int ret = 0;

    s = "-42";
    ret = myAtoi(s);
    printf("%d\n", ret);

    s = "-91283472332";
    ret = myAtoi(s);
    printf("%d\n", ret);

    s = "+1";
    ret = myAtoi(s);
    printf("%d\n", ret);

    s = "20000000000000000000";
    ret = myAtoi(s);
    printf("%d\n", ret);


    s = "-42";
    ret = myAtoi(s);
    printf("%d\n", ret);

    s = "         -42";
    ret = myAtoi(s);
    printf("%d\n", ret);

    s = "4193 with words";
    ret = myAtoi(s);
    printf("%d\n", ret);

    s = "words and 987";
    ret = myAtoi(s);
    printf("%d\n", ret);

    getchar();
    return 0;
}