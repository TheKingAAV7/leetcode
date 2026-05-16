class Solution {
public:
    int findMin(vector<int>& arr) {
        /*


         increasing (dec point) increasing
         if(arr[mid]<=arr[hi]) -> hi= mid-1
         

       */
       return *min_element(arr.begin(),arr.end());
    }
};