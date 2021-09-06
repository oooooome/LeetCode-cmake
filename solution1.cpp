#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i1 = 0, i2 = 0;
		int l = nums.size();
		for(i1 = 0; i1< l; ++i1)
		{
			for(i2 = 0; i2 < l; ++i2)
			{
				if (nums[i1] + nums[i2] == target && i1 != i2)
				{
					return vector<int>{i1, i2};
				}
			}
			
			
		}

		return vector<int>{-1, -1};
	}
};


int main()
{
	vector<int> nums{ 3,2,4 };
	int target = 6;
	Solution1 s{};
	auto ret = s.twoSum(nums, target);
	cout << ret[0] << " " << ret[1];
	return 0;
}