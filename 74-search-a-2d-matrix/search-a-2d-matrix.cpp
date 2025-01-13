class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
            int m=mat[0].size();
            int n=mat.size();
            int rl=0,rh=n-1;
            auto f=[&](int row)->bool{
                int cl=0,ch=m-1;
                while(cl<=ch){
                    int md=(cl+ch)>>1;
                    if(mat[row][md]==target) return true;
                    if(mat[row][md]>target){
                        ch=md-1;
                    }
                    else cl=md+1;
                }
                return false;
            };
            
            while(rl<=rh){
                int mid=(rl+rh)>>1;
                if(mat[mid][0]<=target and target<=mat[mid].back()){
                    if(f(mid)){
                        return true;
                    }
                    return false;
                }
                if(mat[mid][0]>=target){
                    rh=mid-1;
                }
                else rl=mid+1;
            }
            return false;
    }
};