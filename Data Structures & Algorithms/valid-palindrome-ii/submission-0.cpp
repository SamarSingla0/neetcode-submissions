class Solution {
public:
    int f(string& s, string& temp, vector<vector<int>>&dp, int i, int j) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == temp[j]) {
            dp[i][j] = 1 + f(s, temp, dp, i-1, j-1);
        }else {
            dp[i][j] = max(f(s, temp, dp, i-1, j), f(s, temp, dp, i, j-1));
        }

        return dp[i][j];
    }
    bool validPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int ans = f(s, temp, dp, n-1, n-1);
        if(ans == s.size() || ans == s.size() - 1) return   true;
        return false;
    }
};