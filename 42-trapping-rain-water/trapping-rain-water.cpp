class Solution {
public:
    int trap(vector<int>& ht) {
        int n=ht.size();
        vector<int>lef(n,-1),rig(n,-1);
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,ht[i]);
            lef[i]=mx;
        }
        mx=-1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,ht[i]);
            rig[i]=mx;
        }

        for(int i=1;i<n-1;i++){
            ans+=max(0,min(lef[i-1],rig[i+1])-ht[i]);
        }
        return ans;
    }
};