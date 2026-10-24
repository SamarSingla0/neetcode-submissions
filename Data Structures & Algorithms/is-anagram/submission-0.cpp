class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        unordered_map<char, int>mpp;
        for(auto it : s) {
            mpp[it]++;
        }

        for(int i = 0; i < m; i++) {
            mpp[t[i]]--;
            if(mpp[t[i]] == 0) mpp.erase(t[i]);
        }

        return mpp.size() == 0 ? true : false;
    }
};
