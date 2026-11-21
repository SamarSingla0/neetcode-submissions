class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, ans, 0, "");
        return ans;
    }

    void f(int n, vector<string>& ans, int m, string temp) {
        if(n == 0 && m == 0) {
            ans.push_back(temp);
            return;
        }

        if(m > 0)
            f(n, ans, m-1, temp + ")");

        if(n > 0)
            f(n-1, ans, m+1, temp + "(");
    }
};