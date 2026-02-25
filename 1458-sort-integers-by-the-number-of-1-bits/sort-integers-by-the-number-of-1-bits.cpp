class Solution {
public:

static int f(int num){
    int cnt=0;
    while(num>0){
     if( (num&1) == 1){
      cnt++;
     } 
     num=num>>1;
    }
    return cnt;

}
// __builtin_popcount returns no. of set bits..
    static bool comp(int &a, int &b ){
        // index of a > index of b
        int cnt1= f(a);
        int cnt2= f(b);
        if(cnt1<cnt2) return true;
        if(cnt1==cnt2) return a<b;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        /*

        Bubble Sort
        Custom sorting
        */

        int n=arr.size();

        sort(arr.begin(),arr.end(),comp);

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int num1= arr[i];
        //         int num2= arr[j];
        //         int cnt1= __builtin_popcount(arr[i]);
        //         int cnt2= __builtin_popcount(arr[j]);
        //         if(cnt1>cnt2){
        //             swap(arr[i],arr[j]);
        //         }
        //         else if(cnt1==cnt2){
        //             if(arr[i]>arr[j]){
        //                 swap(arr[i],arr[j]);
        //             }
        //         }
        //     }
        // }

        return arr;
    }

};