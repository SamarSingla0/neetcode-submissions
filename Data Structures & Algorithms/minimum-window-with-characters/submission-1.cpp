class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        vector<int> hash(256, 0);

        int l = 0, r = 0;
        int minlen = 1e9;
        int cnt = 0;
        int sind = -1;

        for(int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }

        while(r < n) {

            if(hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            while(cnt == t.size()) {

                if(r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sind = l;
                }

                hash[s[l]]++;

                if(hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        return sind == -1 ? "" : s.substr(sind, minlen);
    }
};