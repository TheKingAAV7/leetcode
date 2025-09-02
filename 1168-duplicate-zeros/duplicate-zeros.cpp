class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int cnt=count(arr.begin(),arr.end(),0);
        int src=n-1,dest=n+cnt-1;
        for(int i=n-1;i>=0;i--,dest--){
            if(arr[i]!=0){
                if(dest<n)
                arr[dest]=arr[i];
            }
            else{
                
                if(dest<n)
                arr[dest]=arr[i];
                dest--;
                if(dest<n) arr[dest]=arr[i];
            }
           
            
        }
        
        return ;
    }
};