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
        // ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
        unordered_set<char> occ;
        int n = s.size();
        // ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
        int rk = -1, ans = 0;
        // ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // ��ָ�������ƶ�һ���Ƴ�һ���ַ�
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // ���ϵ��ƶ���ָ��
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
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