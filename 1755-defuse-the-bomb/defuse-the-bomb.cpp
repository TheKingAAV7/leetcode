class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int sm=0;
            if(k==0) ans.push_back(0);
            else if(k>0){
            for(int j=i+1;j<i+1+k;j++){
                sm+=(code[j%n]);
            }
            ans.push_back(sm);
            }
            else{
              //  cout<<"YES"<<endl;
                for(int j=1;j<=abs(k);j++){
                    sm+=(code[(i-j+n)%n]);
                }
                ans.push_back(sm);
            }

        }
            return ans;
    }
};