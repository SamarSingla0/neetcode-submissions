class Solution {
    bool check(int mid, vector<int>& a, int days) {
        int cnt = 1;
        int sum = 0;

        for(int i = 0; i < a.size(); i++) {
            if(sum + a[i] > mid) {
                cnt++;
                sum = a[i];
            }
            else {
                sum += a[i];
            }
        }

        return cnt <= days;
    }

public:
    int shipWithinDays(vector<int>& a, int days) {
        int n = a.size();

        int left = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        int ans = high;

        while(left <= high) {
            int mid = left + (high - left) / 2;

            if(check(mid, a, days)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};