#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    stack<int> signs;
    int result = 0;
    int sign = 1;
    int num = 0;

    signs.push(1);

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }

        else if (c == ' ') {
            continue;
        }

        else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = signs.top();
        }

        else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -signs.top();
        }

        else if (c == '(') {
            signs.push(sign);
        }

        else if (c == ')') {
            result += sign * num;
            num = 0;
            signs.pop();
        }
    }

    result += sign * num;
    return result;
}

int main() {
    string s;

    cout << "Enter expression: ";
    getline(cin, s);

    cout << calculate(s) << endl;

    return 0;
}