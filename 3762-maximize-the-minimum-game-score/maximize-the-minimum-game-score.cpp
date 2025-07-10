#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& arr, int m) {
      ll lo=0,hi=5e14;
      ll ans=0;
      int n=arr.size();
      auto f=[&](ll mid)->bool{
        
        vector<ll>req(n,0);
        
        for(int i=0;i<n;i++){
            req[i]= ceil((1.0*mid)/(1.0*arr[i]));
        }
        
        
        int k=m;
        int pos=0;
        while(pos<n and k>0){
        //   if(mid==3){
        //  for(int i:req) cout<<i<<" ";
        //  cout<<endl;
        // }
           
          if(req[pos]<=1) {
            req[pos]=0;
            k--;
            pos++;
            continue;
          }
          if(pos+1<n){
            
            if(k>=2*req[pos]-1){
            k-=2*req[pos]-1;
            req[pos+1]-=req[pos]-1;
            req[pos]=0;
            pos++;
            
            }
            else return false;
            
          }
          else{
            
            if(k>=2*req[pos]-1){
                k-=2*req[pos]-1;
                req[pos]=0;
                pos++;
                
            }
            else return false;
          }
         
        }
        
         for(auto i:req){
            
            if(i>0)
             return false;
          }
          return true;
        
      };
      while(lo<=hi){
        ll mid= lo+(hi-lo)/2;
        if(f(mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
      }
      return ans;
    }
};


/*
   3 5


*/