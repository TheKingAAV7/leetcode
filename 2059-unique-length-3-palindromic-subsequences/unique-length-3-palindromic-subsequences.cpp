class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record first and last occurrences of each character
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        set<string> st;

        // Iterate over all characters to count palindromic subsequences
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && first[i] < last[i]) {
                // Use a boolean array to track characters between first and last occurrences
                vector<bool> seen(26, false);
                for (int j = first[i] + 1; j < last[i]; j++) {
                    seen[s[j] - 'a'] = true;
                }
                // Construct palindromic subsequences
                for (int j = 0; j < 26; j++) {
                    if (seen[j]) {
                        string l = "";
                        l += (i + 'a');
                        l += (j + 'a');
                        l += (i + 'a');
                        st.insert(l);
                    }
                }
            }
        }

        return st.size();
    }
};
