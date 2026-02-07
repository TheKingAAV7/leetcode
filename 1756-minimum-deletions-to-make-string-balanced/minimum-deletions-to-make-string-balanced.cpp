class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;    // number of 'b's seen so far
        int deletions = 0;  // minimum deletions to make prefix balanced

        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else { // c == 'a'
                // either delete this 'a' (deletions + 1) or delete all previous 'b's (b_count)
                deletions = min(deletions + 1, b_count);
            }
        }
        return deletions;
    }
};
