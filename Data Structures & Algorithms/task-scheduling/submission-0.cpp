class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        vector<int> freq(26, 0);

        for(auto it : a) {
            freq[it - 'A']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int maxf = freq[0];
        int idle = (maxf - 1) * n;

        for(int i = 1; i < 26; i++) {
            idle -= min(maxf - 1, freq[i]);
        }

        return max(0, idle) + a.size();
    }
};