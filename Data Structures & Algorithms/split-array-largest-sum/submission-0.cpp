class Solution {
    bool guess(vector<int>& a, int k, int mid) {
        int n = a.size();
        int cnt = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(sum + a[i] > mid) {
                sum = a[i];
                cnt++;
            }
            else {
                sum += a[i];
            }
        }

        return cnt <= k;
    }

public:
    int splitArray(vector<int>& a, int k) {
        int n = a.size();

        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(guess(a, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};