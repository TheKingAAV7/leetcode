class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        // first element that occurs, od times, can't be replaced..
        string ans;
        int n=s.length();
        vector<set<int>>v(26);

        for(int i=0;i<n;i++){
            v[s[i]-'a'].insert(i);
        }
        int lstidx=-1;
        auto f=[&](int cur)->array<int,2>{
            // find the just next occurence..
            auto it= v[cur].upper_bound(lstidx);
            if(it==v[cur].end()){
                return {0,-1};
            }
            int curidx= *it;

           // cout<<char(cur+'a')<<" "<<curidx<<" "<<lstidx<<endl;
            for(int i=0;i<26;i++){
                if(i==cur) continue;
                if(v[i].size()>0){
                int lst= *v[i].rbegin();
                if(lst<curidx and lst>lstidx){
                    return {0,-1};
                }
                }
            }
            return {true,curidx};

        };
 
        
        while(true){
            // find the best character possible
            char c='.';
            for(int i=0;i<26;i++){

                  array<int,2>tmp= f(i);
                if(tmp[0]){
                    lstidx=tmp[1];
                    c=i+'a';
                   // cout<<"pos: "<<c<<endl;
                    break;
                }
            }
            if(c!='.') ans.push_back(c);
            else break;
        }

        vector<int>mp(26,0);
        for(int i=0;i<ans.length();i++){
            mp[ans[i]-'a']++;
        }
        string fin;
        for(int i=0;i<ans.length();i++){
            while(!fin.empty() and (ans[i]<fin.back() and mp[fin.back()-'a']>=2)){
                mp[fin.back()-'a']--;
                fin.pop_back();
            }
            fin.push_back(ans[i]);
        }
        cout<<ans<<endl;
        cout<<fin<<endl;
        char lst= fin.back();
        if(fin.size()==1) return fin;

        
        
        fill(mp.begin(),mp.end(),0);
        for(char c:fin) mp[c-'a']++;
        while( mp[fin.back()-'a']>=2) {
        mp[fin.back()-'a']--;
        fin.pop_back();
        }

        // bool poc=false;
        // for(char c:fin){
        //     if(c==lst) {
        //         poc=true;
        //         break;
        //     }
        // }

        // if(!poc || fin.size()==0 ) 
        // fin.push_back(lst);
        
        
        return fin;
    }


};