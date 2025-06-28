class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        int prev=arr[0];
        if(prev>=arr[1]) return false;
        bool lef=true;
        for(int i=1;i<n-1;i++){
           // cout<<prev<<endl;
            if(arr[i]>prev and lef){
                prev=arr[i];
            }   
            else if(arr[i]<prev and lef){
                lef=false;
                prev=arr[i];
            }
            else if(!lef and arr[i]<prev){
                prev=arr[i];
            }
            else {
             //   cout<<i<<endl;
            return false;
            }
        }
        if( arr.back()<prev) 
        return true;
        return false;
    }
};