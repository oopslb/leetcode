/*
对nums数组建图，边为i指向nums[i]，这题等价于找环的入口
用快慢指针找环的入口
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast =0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
