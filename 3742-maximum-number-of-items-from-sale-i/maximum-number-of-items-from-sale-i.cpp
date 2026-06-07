class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n= items.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            int cur=items[i][0];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%cur==0) cnt++;
            }
            v[i]=cnt;
        }


    int dp[1001][1501][2];
    fill(&dp[0][0][0], &dp[0][0][0]+(1001*1501*2) , -1);

    // for(int i:v) cout<<i<<" ";
    //     cout<<endl;
    auto f=[&](auto &&self, int i, int b,int flag)->int{
      if(i>=n || b<=0) return 0;  
      if(dp[i][b][flag]!=-1) return dp[i][b][flag];
      int ntake= self(self,i+1,b,0);


      int take=0;
      int req=items[i][1];
      if(b>=req){
    //   int nxt= 
      if(!flag)
      take=v[i]+1+self(self,i,b-req,1);
      else take=1+self(self,i,b-req,1);;
      }
      return dp[i][b][flag]=max(take,ntake);
    };


        int ans= f(f,0,budget,0); // i, budget

        return ans;
        
    }
};