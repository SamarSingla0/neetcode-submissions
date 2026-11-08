class Solution {
public:
    int findMin(vector<int>& a) {
        int low = 0, high = a.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(a[mid] > a[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return a[low];
    }
};