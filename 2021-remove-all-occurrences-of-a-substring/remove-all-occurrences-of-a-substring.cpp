class Solution {
public:
    string removeOccurrences(string s, string t) {
        stack<char> st;
        int n = s.length();
        int m = t.length();

        for (int i = 0; i < n; i++) {
            st.push(s[i]);

            // Check if last m characters match t
            if (st.size() >= m) {
                string tmp = "";
                stack<char> tempStack;
                
                // Extract last m characters without modifying order
                for (int j = 0; j < m; j++) {
                    tempStack.push(st.top());
                    st.pop();
                }

                // Construct string for comparison
                while (!tempStack.empty()) {
                    tmp += tempStack.top();
                    st.push(tempStack.top()); // Push elements back to stack
                    tempStack.pop();
                }

                // If a match is found, remove last m characters
                if (tmp == t) {
                    for (int j = 0; j < m; j++) {
                        st.pop();
                    }
                }
            }
        }

        // Construct final result from stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
