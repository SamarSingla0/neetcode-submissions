class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(a[mid] == target) return mid;

            // Left half is sorted
            if(a[low] <= a[mid]) {

                if(a[low] <= target && target < a[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if(a[mid] < target && target <= a[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};