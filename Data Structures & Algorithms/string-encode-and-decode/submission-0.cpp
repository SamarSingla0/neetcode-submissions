class Solution {
public:
    int n, m;
    string encode(vector<string>& st) {
        n = st.size();
        string ans;
        for(auto it : st) {
            int len = it.size();
            ans += (unsigned char) len;
            ans += it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        m = s.size();
        vector<string>ans;
        for(int i = 0; i < m;) {
            unsigned char len = s[i];
            i++;
            ans.push_back(s.substr(i, (int)len));
            i+=len;
        }
        return ans;
    }
};
