/*
如果我们可以把所有数字分成两组，使得：
两个只出现一次的数字在不同的组中；
相同的数字会被分到相同的组中。
二进制相同位数相同必为0，则为一组，不同的则为另一组
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            res ^= nums[i];
        }
        int div = 1;
        while ((div & res) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i]&div)
                a ^= nums[i];
            else b ^= nums[i];
        }
        return vector<int>{a, b};
    }
};
