class Solution {
private:
void f(int i, vector<int>&nums,int &maxi, int cur, int &cnt){
    if(i>=nums.size()){
        if(cur==maxi) cnt++;
        return;
    }
    f(i+1,nums,maxi, cur|nums[i],cnt);
    f(i+1,nums,maxi,cur,cnt);
    return ;
}
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int i:nums) maxi|=i;
        int cnt=0;
        f(0,nums,maxi,0,cnt);
        return cnt;
    }
};