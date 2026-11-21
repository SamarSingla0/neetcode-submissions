class Solution {
public:
    void f(vector<int>&nums, int t, vector<vector<int>>&ans, vector<int>temp, int n, int j) {

        if(t == 0) ans.push_back(temp);

        for(int i = j; i < n; i++) {
            if(nums[i] <= t) {
                temp.push_back(nums[i]);
                f(nums, t - nums[i], ans, temp, n, i);
                temp.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;

        f(nums, target, ans, temp, n, 0);
        return ans;
    }
};
