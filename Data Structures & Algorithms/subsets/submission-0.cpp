class Solution {
public:
    void f(vector<int>& a, int n, int i, vector<int>& temp, vector<vector<int>>& ans) {

        ans.push_back(temp);

        for(int j = i; j < n; j++) {

            if(j != i && a[j] == a[j-1]) continue;

            temp.push_back(a[j]);

            f(a, n, j+1, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        vector<int> temp;
        int n = nums.size();

        f(nums, n, 0, temp, ans);

        return ans;
    }
};
