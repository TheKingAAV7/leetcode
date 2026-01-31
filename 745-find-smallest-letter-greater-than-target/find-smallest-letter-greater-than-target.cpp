class Solution {
public:
    char nextGreatestLetter(vector<char>& str, char target) {
        auto it=upper_bound(str.begin(),str.end(),target);
        if(it==str.end()) return str[0];
        return *it;
    }
};