class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        int mini= *min_element(nums.begin(),nums.end());
        int maxi= *max_element(nums.begin(),nums.end());
        int p1,p2,p3,p4;
        p1=p3=INT_MIN;
        p2=p4=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                p1=max(p1,i);
                p2=min(p2,i);
            }
            if(nums[i]==maxi){
                p3=max(p3,i);
                p4=min(p4,i);
            }
        }

        // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;

        return min({n - max(abs(p1-p4)-1,abs(p3-p2)-1),max(p1,p3)+1,n-min(p2,p4)});
    }
};