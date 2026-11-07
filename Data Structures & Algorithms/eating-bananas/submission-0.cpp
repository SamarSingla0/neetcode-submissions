class Solution {
public:
    bool check(vector<int>& a, int mid, int h) {
        long long cnt = 0;

        for(int i = 0; i < a.size(); i++) {
            cnt += (a[i] + mid - 1) / mid;
        }

        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();

        int low = 1;
        int high = *max_element(a.begin(), a.end());

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(a, mid, h)) {
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