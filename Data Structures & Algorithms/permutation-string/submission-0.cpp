class Solution {
public:
    bool checkInclusion(string a, string b) {
        int n = a.size();
        int m = b.size();

        if(n > m) return false;

        vector<int>ahash(26, 0);
        vector<int>bhash(26, 0);

        for(auto it : a) {
            ahash[it - 'a']++;
        }

        int i = 0, j = 0;

        while(j < m) {
            bhash[b[j] - 'a']++;

            if(j-i+1 > n) {
                bhash[b[i] - 'a']--;
                i++;
            }

            if(ahash == bhash) {
                return true;
            }

            j++;
        }

        return false;
    }
};
