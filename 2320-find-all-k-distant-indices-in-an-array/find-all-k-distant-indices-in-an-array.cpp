class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    
    int n=nums.size();
    set<int>st;
    int cnt=0;
    for(int i=0;i<n;i++){
       if(nums[i]==key){
        cnt=k;
        st.insert(i);
       }
       else{
        if(cnt>0){

            st.insert(i);
            cnt--;
        }
       }
    }
    cnt=0;
    for(int i=n-1;i>=0;i--){
        if(nums[i]==key){
            cnt=k;
            st.insert(i);
        }
        else{
            if(cnt>0) {
                st.insert(i);
                cnt--;
            }
        }
    }
    vector<int>ans(st.begin(),st.end());
    return ans;
    
    
    }
};