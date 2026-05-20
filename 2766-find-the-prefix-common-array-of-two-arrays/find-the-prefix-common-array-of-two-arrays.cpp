class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n= a.size();
        vector<int>ans(n,0);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]==2){
                ans[i]++;
            }
            mp[b[i]]++;
            if(mp[b[i]]==2) ans[i]++;
            ans[i]+=(i-1>=0? ans[i-1]: 0);
        }
        return ans;
    }
};