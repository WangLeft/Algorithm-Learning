#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

// 个人解
int arithmeticTriplets_s(vector<int>& nums, int diff) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            bool tp = false;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] == nums[i] + diff){
                    tp = true;
                }
            }
            if(tp){
                for(int j=i+2; j<nums.size(); j++){
                    if(nums[j] == nums[i] + 2*diff){
                        count += 1;
                    }
                }
            }

        }

        return count;
    }

/*
    ## 哈希集合
    给定的数组nums严格递增的，因此数组中不存在重复元素
    算术三元组：分别是 x、x+diff 和 x+2×diff；
    => 问题转换成计算数组nums中有多少个元素可作为算术三元组的最小元素

    unordered_set 是 C++ STL（标准模板库）中的一个容器，它提供了一个无序、不重复的集合实现。
    它是通过哈希表实现的，因此查找元素的时间复杂度是 O(1)。

    unordered_set 中的元素存储在桶（bucket）中，桶是哈希表中的一个槽，
    每个元素都有一个对应的哈希值，该哈希值用于确定它应该存储在哪个桶中。
    当查找元素时，首先计算元素的哈希值，然后只需在对应的桶中搜索即可。
*/
int arithmeticTriplets_h(vector<int>& nums, int diff) {
        int count = 0;
        // size():元素的个数  empty():是否为空  find():若找到，返回元素的迭代器  insert()/erase():增删
        unordered_set<int> hashSet;
        // emplace()：与 insert() 类似，但是 emplace() 可以直接通过构造函数来创建新的元素
        for (int x : nums) {
            hashSet.emplace(x);
        }
        // count()：返回 unordered_set 中与指定值相等的元素数量。如果没有找到，则返回 0
        // for (int x : nums)一种新的 for 循环语法，也被称为范围for循环，可遍历任何实现了迭代器的容器类型，包括数组、向量、列表等等。
        for (int x : nums) {
            if (hashSet.count(x + diff) && hashSet.count(x + 2 * diff)) {
                count++;
            }
        }
        return count;
    }
// 以数组模拟hash
int arithmeticTriplets_hm(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        bool exists[201] = {};
        for (int num : nums)
            exists[num] = true;
        for (int i = 0; i < n-2; i++) {
            int b = nums[i] + diff, c = b + diff;
            if (b <= 200 && c <= 200 && exists[b] && exists[c]) count++;
        }
        return count;
    }

/*
    ## 三指针


*/
int arithmeticTriplets_t(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        for (int i = 0, j = 1, k = 2; i < n - 2 && j < n - 1 && k < n; i++) {
            j = max(j, i + 1);
            while (j < n - 1 && nums[j] - nums[i] < diff) {
                j++;
            }
            if (j >= n - 1 || nums[j] - nums[i] > diff) {
                continue;
            }
            k = max(k, j + 1);
            while (k < n && nums[k] - nums[j] < diff) {
                k++;
            }
            if (k < n && nums[k] - nums[j] == diff) {
                count++;
            }
        }
        return count;
    }


int main() {
    vector<int> vec = {0,1,2,3,4,5,6};
    int dif = 2;
    int num = arithmeticTriplets_t(vec, dif);
    printf("%d", num);
    return 0;
}