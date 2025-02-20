class Solution {
private:
void f(string &tmp,unordered_map<string,int>&mp,int n,string &ans){
    if(tmp.length()==n){
        if(mp.find(tmp)==mp.end()){
            ans=tmp;
          
        }
          return;
    }
    for(char c='0';c<='1';c++){
        tmp.push_back(c);
        f(tmp,mp,n,ans);
        tmp.pop_back();
    }
    return;
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mp;
        for(auto i:nums) mp[i]++;
        
        string tmp="";
        int n=nums[0].length();
        string ans="";
        f(tmp,mp,n,ans);
        return ans;

    }
};