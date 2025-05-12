class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        int n=digits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                for(int k=0;k<n;k++){
                    if(k!=i and k!=j){
                    if(digits[i]!=0){
                        int num=digits[i]*100+digits[j]*10+digits[k];
                       // cout<<num<<" ";
                        if(num%2==0) st.insert(num);
                    }
                    }
                }
                }
            }
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};