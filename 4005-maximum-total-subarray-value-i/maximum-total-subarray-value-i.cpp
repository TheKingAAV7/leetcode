#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mn= *min_element(nums.begin(),nums.end());
        ll mx= *max_element(nums.begin(),nums.end());
        return 1ll*k*(mx-mn);
    }
};