class Solution {
public:
    int maxIceCream(vector<int>& arr, int coins) {
        sort(arr.begin(),arr.end());
        int cnt=0;
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(coins>=arr[i]){
                cnt++;
                coins-=arr[i];
            }
            else break;
        }
        return cnt;
    }
};