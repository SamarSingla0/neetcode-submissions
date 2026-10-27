class Solution {
public:
    int f(vector<int>&arr, vector<vector<int>>&dp, int i, int n, int buy) {
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy == 0) {
            profit = max(f(arr, dp, i+1, n, buy), -arr[i] + f(arr, dp, i+1, n, 1));
        }
        if(buy == 1) {
            profit = max(f(arr, dp, i+1, n, buy), arr[i] + f(arr, dp, i+1, n, 0));
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(arr, dp, 0, n, 0);
    }
};