class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char c:word) mp[c-'a']++;

        vector<int>st;
        for(int i:mp){
            if(i>0) st.push_back(i);
        }
        int n= st.size();
        int cur=1;
        int ans=0;
        sort(st.rbegin(),st.rend());
        for(int cc:st){
            // cout<<(c)<<" "<<(cur/9)+1<<endl;
            if(cur%8==0){
                ans+=cc*(cur/8);
            }
            else{
                ans+= cc*((cur/8)+1);
            }

            cur++;
        }
        return ans;
    }
};