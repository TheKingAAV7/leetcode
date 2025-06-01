class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int pos1=0;
        
        int n=nums.size();
        while(pos1<n and nums[pos1]==0){
            pos1++;
        }
        if(pos1==n) return 0;
        int pos2=n-1;
        while(pos2>=0 and nums[pos2]==0){
            pos2--;
        }
        int cnt=0;
        for(int i=pos1;i<=pos2;i++){
           if(st.empty()){
            st.push(nums[i]);
            cnt++;
            continue;
           }
           while(!st.empty() and nums[i]<st.top()){
            st.pop();
           }
           if(!st.empty() and st.top()!=nums[i]){
            st.push(nums[i]);
            if(nums[i]>0)
           cnt++;
           }
           else if(st.empty()){
            st.push(nums[i]);
            if(nums[i]>0)
            cnt++;
           }
            
        }
        return cnt;
    }
};