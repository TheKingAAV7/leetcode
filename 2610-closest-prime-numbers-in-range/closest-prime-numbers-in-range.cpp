class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
    int n=right;
    vector<int>ans;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if(is_prime[i] and i>=left and i<=right) ans.push_back(i);
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
    }
    if(ans.size()<=1) return {-1,-1};
    int lef=-1,rig=-1;
    int mini=INT_MAX;
    for(int i=1;i<ans.size();i++){
      int   diff=ans[i]-ans[i-1];
        if(diff<mini){
            lef=ans[i-1];
            rig=ans[i];
            mini=diff;
        }
    }
    return {lef,rig};
    
    }
};