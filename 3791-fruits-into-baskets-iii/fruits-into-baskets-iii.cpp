class Solution {
public:
    vector<int>st;

   void bt(int idx, int lef, int rig,map<int,vector<int>>&pos){
        if(lef==rig){
            if(pos.find(lef)!=pos.end()){
                st[idx]=pos[lef].back();
            }
            return;
        }
        int mid=(lef+rig)/2;
        bt(2*idx+1,lef,mid,pos);
        bt(2*idx+2,mid+1,rig,pos);
        st[idx]=min(st[2*idx+1],st[2*idx+2]);
        return;
    }

    void up(int i, int lef, int rig, int idx,int val){
        if(lef==rig){
            st[i]=val;
            return;
        }
        int mid=(lef+rig)/2;
        if(idx<=mid){
            up(2*i+1,lef,mid,idx,val);
        }
        else up(2*i+2,mid+1,rig,idx,val);
        st[i]=min(st[2*i+1],st[2*i+2]);
        return ;
    }

    int que(int idx, int lef, int rig, int l, int r){
        if(lef==l and r==rig)  return st[idx];
        int mid=(lef+rig)/2;
        if(r<=mid){
            return que(2*idx+1,lef,mid,l,r);
        }
        if((mid+1)<=l) return que(2*idx+2,mid+1,rig,l,r);
       int left=que(2*idx+1,lef,mid,l,mid);
        int right=que(2*idx+2,mid+1,rig,mid+1,r);
        return min(left,right);
    }
    int numOfUnplacedFruits(vector<int>& fts, vector<int>& bts) {
        int n=fts.size();
        vector<int>tmp;
        for(int i:fts) tmp.push_back(i);
        for(int i:bts) tmp.push_back(i);
        set<int>unq(tmp.begin(),tmp.end());
        vector<int>sunq(unq.begin(),unq.end());
        map<int,int>mp;

        for(int i=0;i<sunq.size();i++){
            mp[sunq[i]]=i;
        }
        map<int,vector<int>>pos;
        for(int i=0;i<n;i++){
         fts[i]=mp[fts[i]];
         
        }
        int maxi=0;
        for(int i=n-1;i>=0;i--){
          bts[i]=mp[bts[i]];
          maxi=max(maxi,bts[i]);
          pos[bts[i]].push_back(i);
        }

        maxi++;
        st.resize(4*maxi,INT_MAX);
        bt(0,0,maxi,pos);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            // 2 3 4 5
            if(fts[i]<=maxi){
                
            int tans=que(0,0,maxi,fts[i],maxi);
           // cout<<tans<<endl;
            if(tans!=INT_MAX){
                cnt++;
                int x= bts[tans];
                
                pos[x].pop_back();
               // cout<<"EYS"<<endl;
               
                if(pos[x].size()==0){
                    pos.erase(x);
                    up(0,0,maxi,x,INT_MAX);
                }
                else{
                
                    up(0,0,maxi,x,pos[x].back());
                }
            }
            }
           
        }
        return n-cnt;

        
    }
};