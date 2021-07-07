/*
  a b
0 0 0
1 x 0
2 0 x
3 0 0
首先我们会定义两个变量a和b，当遍历nums的时候，对于重复元素x，第一次碰到x的时候，我们会将x赋给a，第二次碰到后再赋给b，第三次碰到就全部消除。赋值和消除的动作可以通过xor很简单的实现。
a = (a^num)
b = (b^num)
但是上面写法忽略了，只有当a是x的时候，我们会将0赋给b，那要怎么做呢？我们知道如果b=0，那么b^num就变成了x，而x&~x就完成了消除操作，而此时a=x，所以第二行写为b = (b^num) & ~a
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ones = ones ^ nums[i] & ~twos;
            twos = twos ^ nums[i] & ~ones;
        }
        return ones;
    }
};
