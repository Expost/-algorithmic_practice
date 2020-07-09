#include <stdio.h>
#include <string>
using namespace std;

string multiply(string num1, string num2) {

}

int main() {
    string s1, s2, ret;
    
    s1 = "2";
    s2 = "3";
    ret = multiply(s1, s2);
    printf("%s\n", ret.c_str());
    

    s1 = "123";
    s2 = "456";
    ret = multiply(s1, s2);
    printf("%s\n", ret.c_str());

    getchar();
    return 0;
}