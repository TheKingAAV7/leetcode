class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        vector<int>lef(n,0),rig(n,0);
        int sm1=0;
        int mx1=0;
        for(int i=0;i<n;i++){
            sm1+=arr[i];
            if(sm1<0) sm1=0;   
            rig[i]=sm1;
        }
        sm1=0,mx1=0;
        for(int i=n-1;i>=0;i--){
            sm1+=arr[i];
            if(sm1<0) sm1=0;
            lef[i]=sm1;
        }
        // for(int i:rig) cout<<i<<" ";
        // cout<<endl;
        // for(int i:lef) cout<<i<<" ";
        // cout<<endl;

        int ans=max({lef[0],lef[1],rig[n-1],rig[n-2]});
        for(int i=1;i<n-1;i++){
          
            ans=max({rig[i-1]+lef[i+1]+arr[i],rig[i-1]+lef[i+1],ans});
        }
        if(ans==0) return *max_element(arr.begin(),arr.end());
        return ans;

    }
};