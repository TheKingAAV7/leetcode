class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        
        int tmp_cnt=0;
        for(int i=0;i<=1e9;i++){
            tmp_cnt+=1;
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int cur=i;
                int lef=1;
                vector<int>tmp(nums.begin(),nums.end());
                while(cur>=0 and cur<n){
                    if(tmp[cur]==0){
                        if(lef) cur--;
                        else cur++;
                    }
                    else if(tmp[cur]>0){
                        tmp[cur]--;
                        lef=!lef;
                        if(lef) cur--;
                        else cur++;
                        
                    }
                }
                sort(tmp.begin(),tmp.end());
                if(tmp[0]==tmp.back() and tmp[0]==0) cnt++;
                tmp=nums;
               
                
                lef=0;
                 cur=i;
                while(cur>=0 and cur<n){
                    
                    if(tmp[cur]==0){
                        // cout<<cur<<" "<<lef<<endl;
                        if(lef) cur--;
                        else cur++;
                        // cout<<cur<<"v0"<<endl;
                    }
                    else if(tmp[cur]>0){
                        // cout<<tmp[cur]<<"@"<<endl;
                        // cout<<tmp[cur]<<endl;
                        tmp[cur]--;
                        
                        lef= !lef;
                        if(lef) cur--;
                        else cur++;
                        //cout<<cur<<" "<<lef<<endl;
                    }
                }
                
                sort(tmp.begin(),tmp.end());
                if(tmp[0]==tmp.back() and tmp[0]==0)
                 cnt++;
            }
        }
        return cnt;
    }
};