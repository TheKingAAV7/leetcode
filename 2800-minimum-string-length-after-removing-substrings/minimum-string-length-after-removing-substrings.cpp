class Solution {
public:
    int minLength(string s)
        {
            
           
     
           stack<char> st;

        

        // Traverse through the string

        for (char ch : s) {

            // Check for "AB" or "CD"

            if (!st.empty() && ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D'))) {

                // Pop the top of the stack if "AB" or "CD" is found

                st.pop();

            } else {

                // Otherwise, push the character onto the stack

                st.push(ch);

            }

        }

        

        // The remaining length of the stack is the minimum possible length

        return st.size();
        
        
    }
};