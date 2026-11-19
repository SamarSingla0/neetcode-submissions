class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        int n = a.size();
        priority_queue<int>pq(a.begin(), a.end());

        while(!pq.empty()) {

            if(pq.size() == 1) return pq.top();

            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x == y) continue;
            else if(x > y) pq.push(x - y);
            else pq.push(y - x);

        }

        return 0;
    }
};
