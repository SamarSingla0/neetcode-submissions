
class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans = "";
        int n = a.size();
        int m = b.size();

        int i = 0, j = 0;
        int cnt = 0;

        while(i < n && j < m) {
            if(cnt == 0) {
                ans += a[i];
                i++;
                cnt++;
            }
            else {
                ans += b[j];
                j++;
                cnt--;
            }
        }

        while(i < n) {
            ans += a[i];
            i++;
        }

        while(j < m) {
            ans += b[j];
            j++;
        }

        return ans;
    }
};
