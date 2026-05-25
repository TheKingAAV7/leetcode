
class Solution {
public:
    vector<int>st;
    void update(int idx, int lef, int rig, int i, int val){
        if(lef==rig){
            st[idx]=val;
            return;
        }
        int mid= (lef+rig)>>1;
        if(i<=mid) update(2*idx+1,lef,mid,i,val);
        else update(2*idx+2,mid+1,rig,i,val);
        st[idx]= st[2*idx+1] | st[2*idx+2]; 
        return;
    }
    int query(int idx, int lef, int rig, int l, int r){
        if(lef>rig) return 0;
        if(lef==l and rig==r) return st[idx];
        int mid= (lef+rig)>>1;
        if(r<=mid) return query(2*idx+1,lef,mid,l,r);
        else if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r);
        int left= query(2*idx+1,lef,mid,l,mid);
        int right= query(2*idx+2,mid+1,rig,mid+1,r);
        return left|right;
    }
    bool canReach(string s, int minJ, int maxJ) {
        int n=s.length();
        vector<int>dp(n,0);
        if(s.back()=='1') return false;
        st.resize(4*n,0);
        dp[n-1]=1;
        update(0,0,n-1,n-1,1);
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1') continue;
            int l= i+minJ;
            int r= min(n-1,i+maxJ);
            
            if(l>r) continue;
            int cur= query(0,0,n-1,i+minJ,min(n-1,i+maxJ));
            update(0,0,n-1,i,cur);
            dp[i]=cur;
            

            // for(int j=i+minJ;j<=min(n-1,i+maxJ);j++){
            //     if(dp[j]) dp[i]=1;
            // }
        }
        
        return dp[0];
    }
};