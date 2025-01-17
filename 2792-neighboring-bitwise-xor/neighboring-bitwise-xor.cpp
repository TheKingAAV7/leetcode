class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int cnt=0;

        int n=derived.size();
        if(n==1) {
        if(derived[0]==1) return false;
        return true;
        }
        for(int i=1;i<n;i++){
            if(derived[i]==1) cnt++;
        }
        if(derived[0]==0){
            if(cnt%2) return false;
            return true;
        }
        if(cnt%2) return true;
        return false;
    }
};