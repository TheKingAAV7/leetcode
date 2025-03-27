class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int ele=-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n/2) ele=nums[i];
        }
        
        if(ele==-1) return -1;
        mp.clear();
        int pos=0;
        for(int i=0;i<n;i++ ){
           if(nums[i]==ele){
            mp[ele]++;
            if(mp[ele]>(i+1)/2){
                pos=i;
                break;
            }
           }
        }
        if(pos==n-1) return -1;
        mp.clear();
        for(int i=pos+1;i<n;i++){
            if(nums[i]==ele){
                mp[ele]++;
            }
        }
        return mp[ele]>((n-pos-1)/2)?pos:-1;
        
    }
};