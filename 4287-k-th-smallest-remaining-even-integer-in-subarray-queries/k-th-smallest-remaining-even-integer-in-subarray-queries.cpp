class Solution {
public:
    vector<vector<int>>st;
    void build(int idx, int lef, int rig, vector<int>&arr){
        if(lef==rig){
            if(arr[lef]%2==0) st[idx].push_back(arr[lef]);
            return;
        }
        int mid= (lef+rig)>>1;
        build(2*idx+1,lef,mid,arr);
        build(2*idx+2,mid+1,rig,arr);
        
        merge(st[2 * idx+1].begin(), st[2 * idx+1].end(),
          st[2 * idx + 2].begin(), st[2 * idx + 2].end(),
          back_inserter(st[idx]));
        // cout<<lef<<" "<<rig<<endl;
        // for(int i:st[idx]) cout<<i<<" ";
        // cout<<endl;
        return;
    }
    int query(int idx, int lef, int rig, int l, int r, long long &k){
        
        if(lef==l and rig==r){
            auto it= upper_bound(st[idx].begin(),st[idx].end(),k);
            int index= it-st[idx].begin();
            return index;
        }
        int mid=(lef+rig)>>1;
        if(r<=mid) return query(2*idx+1,lef,mid,l,r,k);
        if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r,k);
        return query(2*idx+1,lef,mid,l,mid,k) + query(2*idx+2,mid+1,rig,mid+1,r,k);
    }
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        st.resize(4*n);
        vector<int>fans;
        build(0,0,n-1,nums);
        for(auto &it:queries){
            int l= it[0];
            int r= it[1];
            int k= it[2];
            int ans=-1;
            long long lo=2, hi= 3e9;
            // cout<<l<<" "<<r<<" "<<k<<endl;
            while(lo<=hi){
                long long mid= lo+(hi-lo)/2;
                int cnt= query(0,0,n-1,l,r,mid);
                int totalev= mid/2;
                int left= totalev-cnt;
                int req= k-1;
                // cout<<mid<<" "<<cnt<<" "<<left<<endl;
                if(left>req){
                    ans= mid;
                    hi=mid-1;
                }
                else{
                    lo= mid+1;
                }
            }
            fans.push_back(ans);

        }
        return fans;
    }
};