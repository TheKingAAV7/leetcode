class Solution {
public:
    string f(vector<int>&arr){
        int n=arr.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(arr[i]);
            if(i!=n-1){
                ans+=",";
            }
        }
        return ans;
    }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a=nums1;
        vector<int>b=nums2;
        unordered_set<string>vis;

        if(a==b) return 0;
        queue<pair<vector<int>,int>>q;
        string sa=f(a);
        vis.insert(sa);
        q.push({a,0});
        while(!q.empty()){
            vector<int>cur=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(cur==b) {
                return cnt;
            }
            int n=cur.size();
            for(int lef=0;lef<n;lef++){
                for(int rig=lef;rig<n;rig++){
                    if(lef==0 and rig==n-1) continue;
                    vector<int>tmp;
                    vector<int>rem;
                    for(int i=0;i<n;i++){
                       if(i>=lef and i<=rig) tmp.push_back(cur[i]);
                       else rem.push_back(cur[i]);
                    }
                    int m=tmp.size();
                    vector<int>st;
                    for(int i=0;i<m;i++){
                        st.push_back(tmp[i]);
                    }
                    for(int i=0;i<rem.size();i++){
                        st.push_back(rem[i]);
                    }
                    string s_st=f(st);
                    if(!vis.count(s_st)){
                    vis.insert(s_st);
                    q.push({st,cnt+1});
                    }
                    int sz=rem.size();
                    for(int i=1;i<=sz;i++){
                        vector<int>bt;
                        for(int j=0;j<i;j++){
                            bt.push_back(rem[j]);
                        }
                        for(int j=0;j<m;j++){
                            bt.push_back(tmp[j]);
                        }
                        for(int j=i;j<sz;j++){
                            bt.push_back(rem[j]);
                        }
                        string s_bt=f(bt);
                        if(!vis.count(s_bt)){
                        vis.insert(s_bt);
                        q.push({bt,cnt+1});
                        }
                    }
                }
            }
            
        }
        
        return -1;
    }
};