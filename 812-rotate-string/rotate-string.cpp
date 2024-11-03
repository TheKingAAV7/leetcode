class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string compare = s+s;
        if(compare.find(goal) != string::npos) return true;
        else return false;
    }
};