class Solution {
public:
    int maxProduct(int n) {
        string s= to_string(n);
        sort(s.begin(),s.end());
        return (s.back()-'0')*(*prev(prev(s.end())) - '0');
    }
};