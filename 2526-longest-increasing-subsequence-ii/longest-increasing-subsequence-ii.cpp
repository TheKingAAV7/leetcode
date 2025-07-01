class Solution {
vector<int>segtree;

private:
// void bt(int idx, int lef , int rig){
//     if(lef==rig){
//         if(mp.find(lef)!=mp.end()) 
//         segtree[idx]=1;
        
//         return;
//     }
//     int mid=(lef+rig)/2;
//     bt(2*idx+1,lef,mid);
//     bt(2*idx+2,mid+1,rig);
//     segtree[idx]=max(segtree[2*idx+1],segtree[2*idx+2]);
   
//     return;
// }
int query(int idx, int lef, int rig, int l, int r){
    if(lef==l and rig==r) return segtree[idx];
    int mid=(lef+rig)/2;
    if(r<=mid){
        return query(2*idx+1,lef,mid,l,r);
    }
    if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r);
    
    int left=query(2*idx+1,lef,mid,l,mid);
    int right=query(2*idx+2,mid+1,rig,mid+1,r);
    return max(left,right);
}
void update(int idx, int lef, int rig, int x, int val){
    if(lef==rig){
        segtree[idx]=val;
        return;
    }
    int mid=(lef+rig)/2;
    if(x<=mid) update(2*idx+1,lef,mid,x,val);
    else update(2*idx+2,mid+1,rig,x,val);
    segtree[idx]=max(segtree[2*idx+1],segtree[2*idx+2]);
    return;
}
public:
    int lengthOfLIS(vector<int>& nums, int k) {
          int maxi=4e5;
          segtree.resize(4*maxi+1,0);
          vector<int>dp(maxi+1,0);
         
        //   bt(0,0,maxi);
          int n=nums.size();
        
        
        for(int i=n-1;i>=0;i--){
            int lo=nums[i]+1;
            int hi=nums[i]+k;
            int tmp=query(0,0,maxi,lo, hi);
            dp[nums[i]]=max(dp[nums[i]],1+tmp);
            update(0,0,maxi,nums[i],dp[nums[i]]);
        }

    
        return *max_element(dp.begin(),dp.end());

        
    }
};