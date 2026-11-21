class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& temp,
           vector<int>& a, int t, int ind) {

        if(t == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < a.size(); i++) {

            if(i > ind && a[i] == a[i-1]) continue;

            if(a[i] > t) break;

            temp.push_back(a[i]);

            f(ans, temp, a, t - a[i], i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(), a.end());

        vector<vector<int>> ans;
        vector<int> temp;

        f(ans, temp, a, target, 0);

        return ans;
    }
};