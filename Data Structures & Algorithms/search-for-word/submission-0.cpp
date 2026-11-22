class Solution {
    void f(vector<vector<char>>& a, string& word,
           int i, int j, int ind, bool& check) {

        int n = a.size();
        int m = a[0].size();

        if(ind == word.size()) {
            check = true;
            return;
        }

        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        if(a[i][j] != word[ind])
            return;

        char ch = a[i][j];
        a[i][j] = '#';

        f(a, word, i+1, j, ind+1, check);
        f(a, word, i-1, j, ind+1, check);
        f(a, word, i, j+1, ind+1, check);
        f(a, word, i, j-1, ind+1, check);

        a[i][j] = ch;
    }

public:
    bool exist(vector<vector<char>>& a, string word) {
        int n = a.size();

        if(n == 0) return false;

        int m = a[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(a[i][j] == word[0]) {
                    bool check = false;

                    f(a, word, i, j, 0, check);

                    if(check) return true;
                }
            }
        }

        return false;
    }
};