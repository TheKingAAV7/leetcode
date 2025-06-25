class Solution {
public:
    int minSwaps(vector<int>& nums) {
        map<int,int>mp;
        vector<int>nums1(nums.begin(),nums.end());
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int a, int b){
            int x=a,y=b;
            int sm1=0, sm2=0;
            while(x>0){
                sm1+=(x%10);
                x/=10;
            }
            while(y>0){
                sm2+=(y%10);y/=10;
            }
            if(sm1==sm2) return a<b;
            return sm1<sm2;
        });
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        set<int>vis;
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis.find(nums1[i])!=vis.end()) continue;
            int tmp=0;
            int ele=nums1[i];
            int idx=i;
            while(vis.find(ele)==vis.end()){
                
                vis.insert(ele);
                tmp++;
                ele=nums1[mp[ele]];
            }

            ans+=(tmp-1);
        }
        return ans;
        
    }
};