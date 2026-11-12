class Solution {
public:
    int calPoints(vector<string>& a) {
        int n = a.size();

        int ans = 0;
        stack<int>st;
        for(int i = 0; i < n; i++) {
            if(a[i] != "C" && a[i] != "D" && a[i] != "+") {
                st.push(stoi(a[i]));
            }else if(a[i] == "+") {
                int b = st.top();
                st.pop();
                int c = st.top() + b;
                st.push(b);
                st.push(c);
            }else if(a[i] == "D") {
                st.push(st.top() * 2);
            }else {
                st.pop();
            }
        }


        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};