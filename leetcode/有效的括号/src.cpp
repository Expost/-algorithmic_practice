#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (auto &itr : s) {
        if (itr == '(' || itr == '[' || itr == '{') {
            st.push(itr);
        }
        else if (!st.empty() &&
         ((itr == ')' && st.top() == '(') ||
          (itr == ']' && st.top() == '[') ||
          (itr == '}' && st.top() == '{'))){
            st.pop();
        }
        else {
            return false;
        }
    }

    return st.empty();
}

int main() {
    string s;
    bool ret;

    s = "]";
    ret = isValid(s);
    printf("%d\n", ret);


    s = "[";
    ret = isValid(s);
    printf("%d\n", ret);

    s = "()[]{}";
    ret = isValid(s);
    printf("%d\n", ret);

    s = "(]";
    ret = isValid(s);
    printf("%d\n", ret);

    s = "([)]";
    ret = isValid(s);
    printf("%d\n", ret);

    s = "{[]}";
    ret = isValid(s);
    printf("%d\n", ret);

    getchar();
    return 0;
}