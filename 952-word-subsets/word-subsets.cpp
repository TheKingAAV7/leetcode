class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>v(26,0);
        
        vector<string>ans;
        int n=words1.size();
        for(auto it:words2){
            vector<int>tmp(26,0);
            for(auto c:it){
                tmp[c-'a']++;
                v[c-'a']=max(v[c-'a'],tmp[c-'a']);
            }
        }
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        for(auto it:words1){
            vector<int>tmp(v.begin(),v.end());
            for(auto c:it){
                tmp[c-'a']--;
            }
            bool f=true;
            for(int i:tmp){
                if(i>0){
                    f=false;
                    break;
                }
            }
            if(f) ans.push_back(it);
        }
        return ans;
    }
};