class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto f=[&](int num)->bool{
            string tmp=to_string(num);
            if(tmp.find('0')!=string::npos) return false;
            return true;
        };
        for(int i=1;i<n;i++){
            int req=n-i;
            if(f(req) and f(i)){
                return {i,req};
            }
        }
        return {-1,-1};
    }
};