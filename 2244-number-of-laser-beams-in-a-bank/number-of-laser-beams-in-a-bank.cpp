class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        stack<int>st;
        for(auto row : bank){
            int cnt=0;
            for(char c:row){
                if(c=='1') cnt++; 
            }
            //cout<<cnt<<endl;
            if(!st.empty()){
                //cout<<cnt<<" "<<st.top()<<endl;
             ans+=(cnt*st.top());
            }
            if(cnt!=0)
            st.push(cnt);
        }
        return ans;
    }
};