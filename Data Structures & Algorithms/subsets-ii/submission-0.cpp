class Solution {
    void f(vector<int>& temp, vector<vector<int>>& ans, int n,
           int i, vector<int>& nums) {

        ans.push_back(temp);

        for(int j = i; j < n; j++) {

            // Skip duplicates at the same recursion level
            if(j > i && nums[j] == nums[j-1]) continue;

            temp.push_back(nums[j]);

            f(temp, ans, n, j+1, nums);

            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int>> ans;

        f(temp, ans, n, 0, nums);

        return ans;
    }
};