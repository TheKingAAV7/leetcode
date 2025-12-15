class Solution {
int N;
vector<int>st;

void build(int idx, int lef, int rig, string &s){
    if(lef==rig){
        st[idx]=0;
        return;
    }

    int mid=(lef+rig)>>1;
    build(2*idx+1,lef,mid,s);
    build(2*idx+2,mid+1,rig,s);
    // left last right first
    int cur=0;
    if(mid+1<N and s[mid]==s[mid+1]) cur=1;
    
    st[idx]= cur + st[2*idx+1] + st[2*idx+2];
   
    return;
}

void up(int idx, int lef, int rig, int i,string &s){
    if(lef==rig){
        if(s[lef]=='A') s[lef]='B';
        else s[lef]='A';
        st[idx]=0;
        return;
    }

    int mid=(lef+rig)>>1;
    if(i<=mid)
    up(2*idx+1,lef,mid,i,s);
    else
    up(2*idx+2,mid+1,rig,i,s);
    int cur=0;
    if(mid+1<N and s[mid]==s[mid+1]) cur=1;
    
    st[idx]= cur + st[2*idx+1] + st[2*idx+2];
   
    return;
    
}
int query(int idx, int lef, int rig, int l, int r,string &s){
    if(lef==l and rig==r) return st[idx];
    int mid=(lef+rig)>>1;
    if(r<=mid) return query(2*idx+1,lef,mid,l,r,s);
    if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r,s);
    int left=query(2*idx+1,lef,mid,l,mid,s);
    int right=query(2*idx+2,mid+1,rig,mid+1,r,s);
    int cur=0;
    if(mid+1<N and s[mid]==s[mid+1]) cur=1;
    int res= left+right+cur;
    return res;
}
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n=s.length();
        N=n;
        st.resize(4*n);
        vector<int>ans;
        build(0,0,n-1,s);
        

        for(auto it:queries){
          if(it[0]==2){
            int l=it[1];
            int r=it[2];
            int tmp= query(0,0,n-1,l,r,s);
            ans.push_back(tmp);
          }
          else{
            up(0,0,n-1,it[1],s);
          }  
        }
        return ans;
        
    }
};