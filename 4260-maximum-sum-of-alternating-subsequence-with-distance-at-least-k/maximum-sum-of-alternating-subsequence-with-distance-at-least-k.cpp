#define ll long long


class Solution {
public:
    vector<ll>st1,st2;
    int MX=1e5+1;

    void update(int idx, int lef, int rig, int i, ll val,vector<ll>&st){
        if(lef==rig){
            st[idx]=val;
            return;
        }
        int mid= (lef+rig)>>1;
        if(i<=mid) update(2*idx+1,lef,mid,i,val,st);
        else update(2*idx+2,mid+1,rig,i,val,st);
        st[idx]=max(st[2*idx+1],st[2*idx+2]);
        return ;
    }
    ll query(int idx, int lef, int rig, int l, int r,vector<ll>&st){
        if(lef==l and rig==r) return st[idx];
        int mid= (lef+rig)>>1;
        if((r<=mid)) return query(2*idx+1,lef,mid,l,r,st);
        if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r,st);
        ll left= query(2*idx+1,lef,mid,l,mid,st);
        ll right= query(2*idx+2,mid+1,rig,mid+1,r,st);
        return max(left,right);
    }
    long long maxAlternatingSum(vector<int>& nums, int k) {
    MX= *max_element(nums.begin(),nums.end())+1ll;
    st1.resize(4*MX,0ll);
    st2.resize(4*MX,0ll);
    int n= nums.size();
    vector<vector<ll>>dp(n+1,vector<ll>(2,0));
    int rig=n-1;
    for(int i=n-1;i>=0;i--){
     if(rig-i>=k){
        update(0,0,MX,nums[rig],dp[rig][0],st1);
        update(0,0,MX,nums[rig],dp[rig][1],st2);
        rig--;
     }
     // increasing dp[i][0]
     int cur= nums[i];
     ll nxt= query(0,0,MX,cur+1,MX,st2);
     dp[i][0]=nums[i]+nxt;

     ll nxtmn= query(0,0,MX,0,cur-1,st1);
     dp[i][1]= nums[i]+nxtmn;
     
    }
    ll ans=0;
    for(auto it:dp){
        ans= max(ans,(ll)it[0]);
        ans=max(ans,(ll)it[1]);
    }
    return (ll)ans;
    }
};