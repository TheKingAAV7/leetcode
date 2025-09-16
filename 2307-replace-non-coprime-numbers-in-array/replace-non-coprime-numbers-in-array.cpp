class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // Copied -> It was just a fuckin brute force
       
        int n=nums.size();
        int st[n];
        vector<int>ans;
        int top=-1;
        for(int x:nums){
            int cur=x;
            while(top!=-1){
                int gc=gcd(st[top],cur);
                if(gc==1) break;
                cur=lcm(st[top],cur);
                top--;
            }
            st[++top]=cur;
        }
        
        
        return vector<int>(st,st+top+1);
    }
};