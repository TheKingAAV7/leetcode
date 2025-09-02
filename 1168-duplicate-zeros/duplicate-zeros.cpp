class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int>tmp;  // 4 5
        // 1 0 0 2 3 0 0 4
        for(int i:arr){
            if(i==0) tmp.push_back(0);
            tmp.push_back(i);
        }
        while(tmp.size()>n) tmp.pop_back();
        arr=tmp;
        return ;
    }
};