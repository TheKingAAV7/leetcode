class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n=prices.size();
        for(int i=0;i<n;i++){
            // if(st.empty() || prices[st.top()]<prices[i]){
            //     st.push(i);
            // }
            while(!st.empty() and prices[i]<=prices[st.top()]){
                prices[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        } // 8 9 9 9 9
        return prices;
    }
};