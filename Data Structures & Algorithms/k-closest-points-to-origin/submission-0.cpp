class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {

        priority_queue<pair<long long, vector<int>>> pq;

        for(auto &it : a) {
            long long dist = 1LL * it[0] * it[0] + 1LL * it[1] * it[1];

            pq.push({dist, it});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};