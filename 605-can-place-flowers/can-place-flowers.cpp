class Solution {
public:
    bool canPlaceFlowers(vector<int>& flo, int m) {
        int n=flo.size();
        if(n==1) {
            if(flo[0]==1)
            return m==0;
            else{
                return n>=m;
            }
        }
        int cnt=0;
        if(flo[0]==0 and flo[1]==0){
            flo[0]=1;
            cnt++;
        }
        for(int i=1;i<n-1;i++){
            if(flo[i]==0 and flo[i-1]==0 and flo[i+1]==0){
                cnt++;
                flo[i]=1;
            }
        }
        if(flo[n-2]==0 and flo[n-1]==0){
            cnt++;
            
        }
        return cnt>=m;
    }
};