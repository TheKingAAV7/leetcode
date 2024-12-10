class Solution {
public:
    int maximumLength(string s) {
        int ans=-1;
            int n=s.length();

            
            unordered_map<string,int>mp;
            for(int i=0;i<n;i++){
                string tmp1="";
                for(int j=i;j<n;j++){
                    tmp1+=s[j];
                    mp[tmp1]++;
                }
            }
            for(int i=0;i<n;i++){
                string tmp="";
                char c='A';
                for(int j=i;j<n;j++){
                    if(tmp.size()==0 || s[j]==c){
                    tmp+=s[j];
                    if(tmp.size()==1) c=tmp[0];
                    if(mp.find(tmp)!=mp.end() and mp[tmp]>=3){
                        // if(tmp.size()>=ans){
                        //     cout<<tmp<<endl;
                        // }
                        ans=max(ans,(int)tmp.size());
                    }
                    }
                    else{
                        break;
                    }
                   

                }
            }
            return ans;
    }
};