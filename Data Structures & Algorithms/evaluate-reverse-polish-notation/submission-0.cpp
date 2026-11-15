
class Solution {
public:
    int evalRPN(vector<string>& a) {
        int n = a.size();
        stack<int>st;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] == "+") {
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();

                ans = b + c;
                st.push(ans);
            }
            else if(a[i] == "-") {
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();

                ans = c - b;
                st.push(ans);
            }
            else if(a[i] == "*") {
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();

                ans = b * c;
                st.push(ans);
            }
            else if(a[i] == "/") {
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();

                ans = c / b;
                st.push(ans);
            }
            else {
                st.push(stoi(a[i]));
            }
        }

        return st.top();
    }
};
