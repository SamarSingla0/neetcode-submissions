
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (int x : st) {
            // Start only at the beginning of a sequence
            if (!st.count(x - 1)) {
                int cnt = 1;
                int curr = x;

                while (st.count(curr + 1)) {
                    curr++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
