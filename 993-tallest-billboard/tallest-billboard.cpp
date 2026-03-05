class Solution {
public:
    // {c,a1 b1}  {c,a2 b2 } st  a1+a2==b2+b1
    /*
        3   {3,6}  {7,4}
        R G R G
        2 1 3 4  1  -1
        there can be multiple values possesed by single -c


    */
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int len = n/2;
        map<int,array<int,3>>mp;
        int ans=0;
        function<void(int,int,int,int,int,int)>f=[&](int i,int sz, int sm, int a, int b, int flag)->void{
            if(i>=sz){
                if(!flag){
                    if(mp.find(sm)==mp.end()){
                        mp[sm]= {a+b,a,b};
                    }
                    else mp[sm]= max(mp[sm],{a+b,a,b});
                }
                else{
                    int req= -sm;
                    if(mp.find(req)!=mp.end()){
                        ans=max(ans,a+mp[req][1]);
                    }
                }
                return;
            }
            f(i+1,sz,sm,a,b,flag);
            f(i+1,sz,sm+rods[i],a+rods[i],b,flag);
            f(i+1,sz,sm-rods[i],a,b+rods[i],flag);
        };

        f(0,len,0,0,0,0);
        f(len,n,0,0,0,1);
        return ans;

    }
};