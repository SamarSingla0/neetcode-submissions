class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        int n = a.size();

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            mpp[a[i]].push_back(i);
        }

        for(auto it : mpp) {
            if(it.second.size() >= 2) {
                for(int i = 1; i < it.second.size(); i++) {
                    if(abs(it.second[i] - it.second[i-1]) <= k)
                        return true;
                }
            }
        }

        return false;
    }
};