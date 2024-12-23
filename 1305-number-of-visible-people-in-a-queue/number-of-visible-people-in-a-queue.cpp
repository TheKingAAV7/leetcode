class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& hts) {
        stack<int>st;     //         11 
        int n=hts.size();
        vector<int>ans(n,0);
        ans[n-1]=0;
        st.push(hts[n-1]);
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!st.empty() and hts[i]>st.top()){
                cnt++;
                st.pop();
            }
            if(st.empty()) ans[i]=cnt;
            else
            ans[i]=(cnt+1);
            st.push(hts[i]);
        }
        return ans;
    }
};