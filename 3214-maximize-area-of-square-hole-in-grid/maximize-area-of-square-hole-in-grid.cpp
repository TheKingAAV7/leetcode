class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        n+=2;
        m+=2;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        int MinN= min(n,m) - 1;
        int MinM= min(n,m) -1;
        int ans=1;
        int lo= 2, hi = MinN;
        //cout<<lo<<" "<<hi<<endl;

        auto f=[&]()->int{
            // for area of a square with side len= x try to find if we can remove x-1 continuos bars
            int mx1=1;
            int prev=-1;
            int cnt=1;
            for(int i:vBars){
                if(i==prev+1){
                    cnt++;
                    mx1= max(mx1,cnt);
                    prev=i;
                }
                else{
                    cnt=1;
                    prev= i;
                }

            }
            mx1= max(mx1,cnt);
            int mx2=0;
            prev=0;
            cnt=1;
            for(int i:hBars){
                if(i==prev+1){
                    cnt++;
                    mx2= max(mx2,cnt);
                    prev=i;
                }
                else{
                    cnt=1;
                    prev= i;
                }
            }
            mx2= max(mx2,cnt);

            int mxsq = min(mx1,mx2);
           // cout<<mx1<<" "<<mx2<<endl;
            int ans= (mxsq+1)* (mxsq+1);
        //   cout<<mid<<" "<<mx1<<" "<<mx2<<" "<<mxsq<<endl;
            return ans;


        };
        
        return f();
    }
};