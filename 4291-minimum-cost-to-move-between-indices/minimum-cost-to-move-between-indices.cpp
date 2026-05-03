class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        vector<int>p1(n,0),p2(n,0);
        int cost=0;
        for(int i=0;i<n-1;i++){
            if(i==0 || (nums[i+1]-nums[i])<(nums[i]-nums[i-1])){
                cost++;
                p1[i+1]=cost;
            }
            else{
                cost+= abs(nums[i]-nums[i+1]);
                p1[i+1]=cost;
            }
        }
        cost=0;
        for(int i=1;i<n;i++){
            if(i==n-1 || (nums[i]-nums[i-1])<=(nums[i+1]-nums[i])){
                cost++;
                p2[i]=cost;
            }
            else{
                cost+= abs(nums[i]-nums[i-1]);
                p2[i]=cost;
            }
        }
    
        for(int i:p2) cout<<i<<" ";
        cout<<endl;
        vector<int>ans;
        for(auto it:queries){
            int l= it[0];
            int r= it[1];
            if(l<r){
                int cost= p1[r] - p1[l];
                ans.push_back(cost);
            }
            else{
                int ost= p2[l]- p2[r];
                ans.push_back(ost);
            }
        }
        return ans;
    }
};