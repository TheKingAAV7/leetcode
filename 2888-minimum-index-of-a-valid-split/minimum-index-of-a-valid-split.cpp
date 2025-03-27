class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        
        int ele=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ele==-1){
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else {
                cnt--;
                if(cnt==0) {
                    ele=nums[i];
                    cnt=1;
                }
            }

        }
       
        
        if(ele==-1) return -1;
        map<int,int>mp;
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