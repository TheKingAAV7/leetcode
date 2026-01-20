class Solution {
public:
    int maximumAND(vector<int>& nums, int K, int m) {
        int n=nums.size();
        int ans=0;
        multiset<int>st(nums.begin(),nums.end());
        int leftmost=-1;
        for(int b=30;b>=0;b--){
            // try to set this bit..
            int curval= ans | (1<<b);
           // cout<<curval<<endl;
            vector<array<int,2>>pq;
            for(int i:st){
                if(curval>=i){
                    pq.push_back({curval-i,i});
                }
                else{
                    // 0 if already, set , otherwise difference between the last bits               // 101   100    1001
                    
                        // curval and i , i>curval   1011  100
                        if((curval&i)==(curval)){
                            pq.push_back({0,i});
                            continue;
                        }
                        int tmp1=0;
                        int tmp2=0;
                        // find the leftmost index where, curval is set and i is not

                        int lefbit=-1;
                        for(int bit=30;bit>=0;bit--){
                            if((curval>>bit)&1){
                                if(((i>>bit)&1) == 0){
                                    lefbit=bit;
                                    break;
                                }
                            }
                        }
                        for(int bit=lefbit;bit>=0;bit--){
                            if((curval>>bit)&1){
                                tmp1|=(1<<bit);
                            }
                            if((i>>bit)&1){
                                tmp2|=(1<<bit);
                            }
                        }
                        int cost= tmp1-tmp2;






                        // if(curval==21 and i==26){
                        //     cout<<"val: "<<cost<<endl;
                        // } 
                    
                        pq.push_back({cost,i});
                        
                }
            }

            sort(pq.begin(),pq.end());

            // if(curval<=21){
            // cout<<curval<<endl;
            // for(auto it:pq) cout<<it[0]<<"->"<<it[1]<<" ";
            // cout<<endl;
            // }
            


            int req_no=m;
            long long totalcost=0;
            for(int kl=0;kl<m;kl++){
                totalcost+=pq[kl][0];
            }
            if(totalcost<=K){


            

               // cout<<"Yes"<<endl;
                // K-=totalcost;
               
                if(leftmost==-1) leftmost= b;
                ans|=(1<<b);

                
            }
        }
        return ans;
    }
};