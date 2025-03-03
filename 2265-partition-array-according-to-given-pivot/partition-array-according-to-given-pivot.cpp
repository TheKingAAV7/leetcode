class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>l,g;
        int p=0;
        for(int i:nums){
            if(i==pivot)p++;
            else if(i>pivot)g.push_back(i);
            else l.push_back(i);
        }
        vector<int>ans;
        for(int i:l) ans.push_back(i);
        while(p--) ans.push_back(pivot);
        for(int i:g)ans.push_back(i);
        return ans;
    }
};