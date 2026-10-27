class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int cnt = 0;
        int prefixsum = 0;
        for(int i = 0; i < n; i++) {
            prefixsum += nums[i];
            int remove = prefixsum - k;
            cnt += mpp[remove];
            mpp[prefixsum] += 1;
        }

        return cnt;
    }
};