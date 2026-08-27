class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();
        string ans="";
        string stmp=s;
        sort(stmp.begin(),stmp.end());
        reverse(stmp.begin(),stmp.end());
        if(stmp<=target) return "";
        vector<int>mp(26,0),mp1(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        string pref="";
        for(int i=-1;i<n-1;i++){
            if(i>=0){
            pref.push_back(target[i]);
            mp1[target[i]-'a']++;
            }
            // find if this pref is possible..
            bool pos=true;
            for(int j=0;j<26;j++){
                if(mp1[j]>mp[j]){pos=false;break;}
            }
            if(!pos) continue;
            string cur=pref;
            char req=target[i+1];
            vector<int>tv=mp;
            for(int j=0;j<26;j++){
                tv[j]-=mp1[j];
            }
            char lst='.';
            for(int j=0;j<26;j++){
                if(j>(req-'a') and tv[j]>0){
                    lst=j+'a';
                    tv[j]--;
                    break;
                }
            }
            if(lst!='.') cur.push_back(lst);
            else continue;
            
            for(int j=0;j<26;j++){
                while(tv[j]>0){
                    cur.push_back(j+'a');
                    tv[j]--;
                }
            }
            if(ans=="" || cur<ans) ans=cur;
            
        }
        return ans;
        
    }
};