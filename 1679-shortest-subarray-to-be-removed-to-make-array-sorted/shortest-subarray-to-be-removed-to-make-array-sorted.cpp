class Solution {
public:
    
    bool f(int k , vector<bool> &prefix , vector<bool> &suffix , vector<int> &arr){
       int n = arr.size();
       if(suffix[k] == true){
        return true;
       }
       for(int i = k; i < n; i++){
        if(i == n-1){
            if(prefix[i-k] == true){
                return true;
            }
        }
        if(i-k >= 0 && prefix[i-k] == true && suffix[i+1] == true && arr[i+1] >= arr[i-k]){
            return true;
        }
       }

       return false;



    }
 


    int findLengthOfShortestSubarray(vector<int>& arr){
        int n = arr.size();
        vector<bool> prefix(n,false) , suffix(n,false);
        int prev = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] >= prev){
                prefix[i] = true;
                prev = arr[i];
            }
            else{
                break;
            }
        }
        prev = INT_MAX;
        for(int i = n-1; i >= 0; i--){
           if(arr[i] <= prev){
            suffix[i] = true;
            prev = arr[i];
           }
           else{
            break;
           }
        }
        int low = 0;
        int high = n-1;
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            if(f(mid,prefix,suffix,arr)){
               ans = mid;
               high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};