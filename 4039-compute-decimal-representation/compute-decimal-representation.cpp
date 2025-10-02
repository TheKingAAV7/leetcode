class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int tmp=n;
        vector<int>ans;
        long long cnt=1;
        while(tmp>0){
            int p=tmp%10;
            tmp/=10;
            if(p!=0)
            ans.push_back(p*cnt);
            cnt*=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};