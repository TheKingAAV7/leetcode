class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sm=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end());
        int cnt=0;
        int cur=0;
        for(int i=capacity.size()-1;i>=0;i--){
            cur+=capacity[i];
            cnt++;
            if(cur>=sm) return cnt;
        }
        return capacity.size();
    }

};