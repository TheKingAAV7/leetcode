class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n= arr1.size();
        int m= arr2.size();
        int ans=0;
        unordered_map<string,int>mp;
        for(int &x:arr1){
            string s= to_string(x);
            string cur;
            for(char &c:s){
                cur.push_back(c);
                mp[cur]++;
            }
        }
        for(int &x: arr2){
            string s= to_string(x);
            string cur;
            for(char &c:s){
                cur.push_back(c);
                if(mp.find(cur)!=mp.end()){
                    ans= max(ans,(int)cur.length());
                }
            }
        }
        return ans;
    }
};