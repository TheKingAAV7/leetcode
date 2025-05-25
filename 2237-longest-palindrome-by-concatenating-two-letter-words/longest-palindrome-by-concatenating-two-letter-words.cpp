class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        map<string,int>mp,mp1;
        bool flag=false;
        int maxi=-1;
        for(auto it:words) mp[it]++;
        for(char c='a';c<='z';c++){
            for(char d='a';d<='z';d++){
                string tmp="";
                tmp.push_back(c);
                tmp.push_back(d);
               
                string rev=tmp;
                reverse(rev.begin(),rev.end());
                if(mp1.find(rev)!=mp1.end()) continue;
                if(c!=d){
                    if(mp.find(tmp)!=mp.end() and mp.find(rev)!=mp.end()){
                      //  cout<<tmp<<endl;
                        ans+=(min(mp[tmp],mp[rev]) *4);
                    }
                }
                else{
                    if(mp.find(tmp)!=mp.end() ){
                      //  cout<<"UES"<<endl;
                        if(mp[tmp]%2==0) ans+=(mp[tmp]/2)*4;
                        else{
                         ans+=(mp[tmp]/2)*4;
                         if(!flag){
                         ans+=2;
                         flag=true;
                         }
                        }
                        
                    }
                }
                 mp1[tmp]=1;
            }
        }
        return ans;
    }
};