#include <iostream>
#include <stdio.h>
#include <vector>
#include <regex>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //可以通过比较迭代器和 .end() 来判断迭代器是否遍历到了集合的尾部，从而结束循环
        unordered_set<int> s;;
        for(int i : nums){
            if (s.find(i) != s.end()) {
                // num已经存在于哈希表中
                return true;
            } else {
                // num不存在于哈希表中
                s.insert(i);
            }
        }
        return false;
    }

    bool containsDuplicate_o(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {0,1,2,6,8,3,4,5,6};
    bool result = sol.containsDuplicate(vec);
    bool result1 = sol.containsDuplicate_o(vec);
    cout<<result<<endl;
    cout<<result1<<endl;
    return 0;
}

/*
      %d 十进制有符号整数

      %u 十进制无符号整数

      %f 浮点数

      %s 字符串

      %c 单个字符

      %p 指针的值

      %e 指数形式的浮点数

      %x,%X 无符号以十六进制表示的整数

      %o 无符号以八进制表示的整数

      %g 自动选择合适的表示法

     注意：acm用的最多的当是  %lf    double类型           %lld       long long 类型

3、

(1). 可以在"%"和字母之间插进数字表示最大场宽。

      例如: %3d 表示输出3位整型数, 不够3位右对齐。

            %9.2f 表示输出场宽为9的浮点数, 其中小数位为2, 整数位为6,    小数点占一位, 不够9位右对齐。

            %8s 表示输出8个字符的字符串, 不够8个字符右对齐。


*/