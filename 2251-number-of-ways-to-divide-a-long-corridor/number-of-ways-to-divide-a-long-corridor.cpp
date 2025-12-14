class Solution {
public:
    int MOD=1e9+7;
    int numberOfWays(string arr) {
        int n=arr.size();
        vector<int>pos;
        for(int i=0;i<n;i++){
            if(arr[i]=='S') pos.push_back(i);
        }
        int m=pos.size();
        if(m%2 || m==0) return 0;
        long long cnt=1;
        // for(int i:pos) cout<<i<<" ";
        // cout<<endl;
        for(int i=1;i<m-1;i+=2){
            int diff= (pos[i+1]-pos[i]+MOD)%MOD;
            cnt=(cnt%MOD*diff%MOD)%MOD;
        }
        return cnt;
        
    }
};