class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const int p1 = 31;  // First prime base
        const int p2 = 53;  // Second prime base
        const int m1 = 1e9 + 7;  // First modulus
        const int m2 = 1e9 + 9;  // Second modulus

        // A map to count occurrences of each prefix with double hashes (hash1, hash2)
        unordered_map<long long, int> mp;

        // Process each word and its prefixes
        for (const string& s : words) {
            long long hash1 = 0, hash2 = 0;
            long long p_pow1 = 1, p_pow2 = 1;

            for (char c : s) {
                int val = c - 'a' + 1;
                
                // Update hash1 and hash2 using their respective bases and moduli
                hash1 = (hash1 + val * p_pow1) % m1;
                hash2 = (hash2 + val * p_pow2) % m2;

                // Update powers of p1 and p2
                p_pow1 = (p_pow1 * p1) % m1;
                p_pow2 = (p_pow2 * p2) % m2;

                // Combine the two hashes into a single key (concatenation of hashes)
                long long combined_hash = hash1 * m2 + hash2;
                mp[combined_hash]++;  // Count the prefix
            }
        }

        // Calculate the prefix scores for each word
        vector<int> ans;
        for (const string& s : words) {
            long long hash1 = 0, hash2 = 0;
            long long p_pow1 = 1, p_pow2 = 1;
            int score = 0;

            for (char c : s) {
                int val = c - 'a' + 1;

                // Update hash1 and hash2 using their respective bases and moduli
                hash1 = (hash1 + val * p_pow1) % m1;
                hash2 = (hash2 + val * p_pow2) % m2;

                // Update powers of p1 and p2
                p_pow1 = (p_pow1 * p1) % m1;
                p_pow2 = (p_pow2 * p2) % m2;

                // Combine the two hashes into a single key (concatenation of hashes)
                long long combined_hash = hash1 * m2 + hash2;

                // Add the score of this prefix (number of words with this prefix)
                score += mp[combined_hash];
            }

            // Store the score for the current word
            ans.push_back(score);
        }

        return ans;
    }
};
