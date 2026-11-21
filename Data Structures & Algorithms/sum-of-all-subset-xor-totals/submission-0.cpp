class Solution {
public:
    int f(vector<int>& nums, int sum, int n, int i) {

        if(i == n) {
            return sum;
        }

        int notpick = f(nums, sum, n, i+1);
        int pick = f(nums, sum ^ nums[i], n, i+1);

        return pick + notpick;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        return f(nums, 0, n, 0);
    }
};