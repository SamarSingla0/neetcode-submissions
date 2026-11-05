class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();

        int ans = 0;
        int minprice = a[0];
        for(int i = 1; i < n; i++) {
            int diff = a[i] - minprice;
            ans = max(diff, ans);
            minprice = min(minprice, a[i]);
        }

        return ans;
    }
};
