class Solution {
public:
    void f(int n, int k, int start, vector<int>& temp,
           vector<vector<int>>& ans) {

        if(k == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            f(n, k-1, i+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;

        f(n, k, 1, temp, ans);

        return ans;
    }
};