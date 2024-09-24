class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(auto i: arr1){
            string tmp=to_string(i);
            string s="";
            for(char c:tmp){
                s+=c;
                mp[stoi(s)]=1;
                }
            
            }
        int ans=0;
        for(int i: arr2){
            string tmp=to_string(i);
            string s="";
            for(char c:tmp){
                s+=c;
                if(mp.find(stoi(s))!=mp.end()){
                    int tmp=s.size();
                    ans=max(ans,tmp);
                    }
                else break;
                }
           }
        return ans;
        
    }
};