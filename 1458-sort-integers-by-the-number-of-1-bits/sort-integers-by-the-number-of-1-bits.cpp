class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        /*

        Bubble Sort
        */

        int n=arr.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int num1= arr[i];
                int num2= arr[j];
                int cnt1= __builtin_popcount(arr[i]);
                int cnt2= __builtin_popcount(arr[j]);
                if(cnt1>cnt2){
                    swap(arr[i],arr[j]);
                }
                else if(cnt1==cnt2){
                    if(arr[i]>arr[j]){
                        swap(arr[i],arr[j]);
                    }
                }
            }
        }
        return arr;
    }

};