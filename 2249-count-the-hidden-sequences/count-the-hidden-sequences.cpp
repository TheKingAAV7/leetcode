class Solution {
public:
    
    bool solve(vector<int>& arr, vector<int>& d, int l, int r, int &ele)
    {
        for(int i=0;i<d.size();i++)
        {
            ele = d[i] + arr[i];
            if(ele>=l && ele<=r )
            {
                arr[i+1] = ele;
                
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        
        int n= d.size();
        int low =lower;
        int high = upper;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            vector<int>arr(n+1);
            arr[0]=mid;
            int ele=mid;
            if(solve(arr, d, lower, upper, ele))
            {
                int mx =INT_MIN;
                for(int j : arr)
                {
                    mx = max(mx, j);
                }
                ans = max(ans, upper- mx+1);
                //cout<<mx<<endl;
                high = mid - 1;
            }
            else if(ele > high)
            {
                high = mid -1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
};