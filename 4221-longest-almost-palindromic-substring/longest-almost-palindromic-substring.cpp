class Solution {
public:
    int almostPalindromic(string s) {
        int n=s.length();
       /*

        try to treat every element as mid and expand till the cost<=1

       */
       string rev=s;
       reverse(rev.begin(),rev.end());
       if(rev==s) return n;
       string s1= s.substr(1);
       string s2= s.substr(0,n-1);
       string rs1= s1;
       string rs2= s2;
       reverse(rs1.begin(),rs1.end());
       reverse(rs2.begin(),rs2.end());
       if(s1==rs1) return n;
       if(s2==rs2) return n;



       function<array<int,2>(int,int,int)>check=[&](int lef, int rig, int cost)->array<int,2>{
        int ans=0;
        int idxl=lef;
        int idxr=rig;
        while(lef>=0 and rig<n ){
            if(s[lef]==s[rig]){
                lef--;
                rig++;
                ans++;
            }
            else{
                if(cost==1) break;
                cost++;
                //del lef
                int l1= 1+ check(lef-1,rig,1)[0];
                int l2= 1+ check(lef,rig+1,1)[0];
                //if(lef==1) cout<<l1<<" s "<<lef-1<<" "<<rig<<endl;
                ans+=max(l1,l2);
                break;
            }
        }
     //   if(idxl==0 and idxr==1) cout<<lef<<" "<<ans<<" "<<rig<<endl;
        return {ans,cost>=1};
        
       };
       int ans=1;
       for(int i=0;i<n;i++){
        auto t11=check(i-1,i+1,1);
        auto t41= check(i-1,i+1,0);
        
        auto t21=check(i,i+1,0);
        auto t31=check(i-1,i+2,1);
        int t1=t11[0];
        int t2=t21[0];
        int t3=t31[0];
        int t4=t41[0];
        t1*=2;
        if(t21[1]==1){
         t2= (t2-1)*2 + 1;
        }
        else
        t2*=2;
        t3*=2;

        if(t41[1]==1){
         t4= (t4-1)*2 + 1;
        }
        else t4*=2;
       
       t4++;
        
        t1++;
        if(t21[1]==0)
        t2++;
        if(t41[1]==0) t4++;
        t3+=2;
        // if(i==0) cout<<t2<<endl;
        ans=max({ans,t1,t2,t3,t4});
       // if(ans==4) cout<<t1<<" "<<t2<<' '<<t3<<endl;
       }
       return ans;
    }

};