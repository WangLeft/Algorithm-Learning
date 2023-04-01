#include <iostream>
#include <stdio.h>
#include <vector>
#include <regex>
#include <unordered_set>
using namespace std;


string maskPII(string s) {
        regex re("[a-zA-Z]");
        bool isEmail = false;
        if (regex_search(s, re)) {
            isEmail = true;
        }
        if(isEmail){
            int index_a = 0;
            int index_d = 0;
            stack<char> char_stack;
            for (char ch : s) {
                 if (ch >= 'A' && ch <= 'Z') {  // 如果是大写字母，则转换为小写字母
                    ch = tolower(ch);
                }
                char_stack.push(ch);
            }

            string last = "";
            bool isg = false;
            int lastc = 0;
            while (!char_stack.empty()) {

                if(char_stack.top() != '@'){
                    if(!isg){
                        last = char_stack.top() + last;
                        char_stack.pop();
                    }
                    else{
                        if(char_stack.size() == lastc){
                            last = char_stack.top() + last;
                            char_stack.pop();
                        }
                        else if(char_stack.size() == 1) {
                            last = "*****" + last;
                            last = char_stack.top() + last;
                            char_stack.pop();
                        }
                        else{
                            char_stack.pop();

                        }
                    }
                }
                else{
                    last = char_stack.top() + last;
                    isg =true;
                    char_stack.pop();
                    lastc = char_stack.size();
                }
            }
            return last;
        }
        else{
            stack<int> nums_stack;
            vector<int> nums;
            for (int i = 0; i<s.size(); i++) {
                if (isdigit(s[i])) {
                    nums_stack.push(s[i] - '0');
                }
            }
            string last = "";
            for (int i = 0; i < 4; i++) {
                last = to_string(nums_stack.top()) + last;
                nums_stack.pop();
            }

            if(nums_stack.size() - 6 == 0){
                last = "***-***-" + last;
            }
            else if (nums_stack.size() - 6 == 1){
                last = "+*-***-***-" + last;
            }
            else if (nums_stack.size() - 6 == 2){
                last = "+**-***-***-" + last;
            }
            else{
                last = "+***-***-***-" + last;
            }

            return last;
        }

}

string maskPII_o(string s) {
    vector<string> country = {"", "+*-", "+**-", "+***-"};

    string results;
    // 查找 @ 第一次出现的位置，并返回该位置的下标
    int at = s.find('@');
    // string::npos 表示 string 类型中字符串的结尾位置
    if (at != string::npos) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // 用于获取字符串中的一个子串。它接受两个参数，
        // 第一个参数是子串的起始位置，第二个参数是子串的长度
        return s.substr(0, 1) + "*****" + s.substr(at - 1);
    }
    // 正则表达式，将字符串 s 中非数字的部分替换为空字符串。
    // [^0-9]" 表示匹配任何非数字字符
    s = regex_replace(s, regex("[^0-9]"), "");
    return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);

}

int main() {
    string str1 = "86-(10)12345678";
    string str2 = "dfg01code@Mail.com";
    string result1 = maskPII_o(str1);
    string result2 = maskPII_o(str2);
    cout<<result1<<endl;
    cout<<result2;
    return 0;
}