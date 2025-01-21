class Solution {
public:
    long long gridGame(vector<vector<int>>& arr) {
        int n=arr[0].size();
        vector<long long>pt(n,0);
        vector<long long>pb(n,0);
        long long sm1=0;
        long long sm2=0;
        for(int i=0;i<n;i++){
            
            sm2+=arr[1][i];
           
            pb[i]=sm2;
        }
        for(int i=n-1;i>=0;i--){
            sm1+=arr[0][i];
            pt[i]=sm1;
        }
        // for(int i:pt) cout<<i<<" ";
        // cout<<endl;
        // for(int i:pb) cout<<i<<" ";
        // cout<<endl;
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long tmp1=0,tmp2=0;
            if(i-1>=0) tmp1=pb[i-1];
            if(i+1<n) tmp2=pt[i+1];
          
            ans=min(ans,max(tmp1,tmp2));

        }
        return ans;
    }
};