class Solution {
public:
    int minAnagramLength(string s) {
        int n= s.length();
        vector<vector<int>>pref(n+1);
        vector<int>mp(26,0);
        pref[0]=mp;
        for(int i=0;i<n;i++){   
            mp[s[i]-'a']++;
            pref[i+1]=mp;
        }
        // cout<<pref[0].size()<<endl;
        vector<int>divs;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                divs.push_back(i);
                if(n/i != i){
                    divs.push_back(n/i);
                }
            }
        }
        set<char>st(s.begin(),s.end());
        if((int)st.size()  == 1) return 1;
        int ans=n;
        sort(divs.begin(),divs.end());
        
        auto f=[&](int l, int r,vector<int>&v)->bool{
            bool psh=false;
            if(v.empty()){
                psh=true;
            }
            for(int i=0;i<26;i++){
                // cout<<r+1<<" "<<l<<endl;
                int cur= pref[r+1][i]-pref[l][i];
                
                if(psh) v.push_back(cur);
                else {
                    if(cur!=v[i]) return false;
                }
            }
            return true;
        };

        for(int &p:divs){
            int turns= n/p;
            int rig=p-1;
            int lef=0;
            bool ok=true;
            vector<int>v;
            for(int i=0;i<turns;i++){
             
             if(f(lef,rig,v)==false){
                ok=false;
                break;
             } 
             lef+=p;
             rig+=p;
            }
            if(ok) return p;

        }
        return n;
    }
};