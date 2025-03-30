class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(26,503);
        vector<int>ans;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(v[s[i]-'a']==503){
                v[s[i]-'a']=i;
            }
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi==-1) maxi=v[s[i]-'a'];
            if(i==maxi){
             ans.push_back(i);
             maxi=-1;
            }
            else maxi=max(maxi,v[s[i]-'a']);
        }
        if(maxi!=-1) ans.push_back(maxi);
        vector<int>res;
        res.push_back(ans[0]+1);
        for(int i=1;i<ans.size();i++){
            res.push_back(ans[i]-ans[i-1]);
        }
        return res;



    }
};