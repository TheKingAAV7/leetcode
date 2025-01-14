class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>v1(n+1,0);
        vector<int>v2(n+1,0);
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            v1[A[i]]=1;
            v2[B[i]]=1;
            if(v2[A[i]]) cnt++;
            if(v1[B[i]]) cnt++;
            if(A[i]==B[i]) cnt--;
            ans.push_back(cnt);
        }
        return ans;
    }
};