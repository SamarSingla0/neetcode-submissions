class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        int low = 2;
        int high = x;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long req = static_cast<long long>(mid) * mid;
            if(req < x) low = mid + 1;
            else if(req == x) return mid;
            else high = mid - 1;
        }

        return high;
    }
};