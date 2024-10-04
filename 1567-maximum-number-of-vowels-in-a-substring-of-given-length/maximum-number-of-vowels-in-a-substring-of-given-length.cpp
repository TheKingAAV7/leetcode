class Solution {
public:
    int maxVowels(string s, int k) {
            set<char>st;
            st.insert('a');
            st.insert('e');
            st.insert('o');
            st.insert('i');
            st.insert('u');

            int ans=0;
            int cnt=0;
            for(int i=0;i<k;i++){
                if(st.find(s[i])!=st.end()){
                    cnt++;
                }
            }
           // cout<<cnt<<endl;
            ans=max(ans,cnt);
            int j=0;
            for(int i=k;i<s.length();i++){
                if(st.find(s[j])!=st.end()) cnt--;
                j++;
                if(st.find(s[i])!=st.end()) cnt++;
                ans=max(ans,cnt);
            }
            return ans;

    }
};