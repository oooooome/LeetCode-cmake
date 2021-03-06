#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        set<char> it;
//        int start = 0;
//        int end = 0;
//        int max = 0;
//        for(int i = 0; i<s.length();++i)
//        {
//            end = i;
//	        if(it.find(s[i]) == it.end())
//	        {
//                it.insert(s[i]);
//	        }else
//	        {
//                max = (max > (end - start)) ? max : (end - start);
//                i = start;
//                start = start + 1;
//                it.clear();
//
//
//	        }
//        }
//        max = (max > it.size()) ? max : it.size();
//        return max;
//    }
//};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};


int main()
{
    Solution s{};
    int ret = s.lengthOfLongestSubstring(" ");
    cout << ret;

}