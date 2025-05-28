class Solution {
public:
    int maximumGroups(vector<int>& A) {
      return (int)(sqrt(A.size() * 2 + 0.25) - 0.5);
    }
};