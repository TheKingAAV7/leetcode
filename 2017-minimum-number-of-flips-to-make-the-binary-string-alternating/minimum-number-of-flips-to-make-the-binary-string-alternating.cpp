class Solution {
public:
    int minFlips(string s) {
        // 1 1 1 0 1 0 1 0
        /// 0 0 0 0 1 0 1 0 1 0 0 0 0  1 0 1 0 1
        /// 1 1 2 2 2 2 2 2 2 2 3
        //  0 1 1 2 3 4 5 6 7 8 8 
        /*
            Find the longest alternate string starting from index i..
            if s[i]=='0'  

        */
        int n=s.length();
        int c1,c2;   //010   101
        c1=c2=0;
        for(int i=0;i<n;i++) s.push_back(s[i]);
        int l=0;
        int ans=n;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                if(s[i]=='1') c1++;
                else c2++;
            }
            else{
                if(s[i]=='0') c1++;
                else c2++;
            }
            if(i-l+1>n){
                if(l%2==0){
                if(s[i]=='1') c1--;
                else c2--;
            }
            else{
                if(s[i]=='0') c1--;
                else c2--;
            }
            // swap(c1,c2);
            l++;
            }
            if(i-l+1==n){
             
             
            //  cout<<l<<" "<<i<<" "<<c1<<" "<<c2<<endl;
              ans=min({ans,c1,c2});
            //  if(ans==-2) cout<<l<<" "<<i<<endl; 
            }
        }
        return ans;
    }

};