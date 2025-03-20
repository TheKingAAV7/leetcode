class Solution {
private:
unordered_map<string,int>mp;
int f(string &num,int i,int sum, int prd,int tight,int leadZ){
    if(i>=num.length()){
        return (sum!=0 and prd%sum==0);
    }
     string tmp=to_string(i)+'-'+ to_string(sum) + '-' + to_string(prd) + '-' + to_string(tight) +'-' + to_string(leadZ);
     if(mp.find(tmp)!=mp.end()) return mp[tmp];
     int digit=num[i]-'0';
    int  upperBound=((tight==1)?num[i]:'9')-'0';
    int ans=0;
    for(int c=0;c<=upperBound;c++){
        if(c==0){
            ans+=f(num,i+1,sum,(leadZ?1:0),tight&&(c==digit),leadZ);
        }
        else{
            ans+=f(num,i+1,sum+c,prd*c,tight&&(c==digit),0);
        }
    }
   
    
    return mp[tmp]=ans;
}
public:
    int beautifulNumbers(int l, int r) {
        /* Approach 1 */
        /*
            STATES:
            1) Idx
            2) Sum
            3) Product
            4) Tight
            5) LeadZ
        */
        
        string s=to_string(r);
      
        string t=to_string(l-1);
        int ans1= f(s,0,0,1,1,1) ;
          mp.clear();
         int ans2= f(t,0,0,1,1,1);
        return ans1-ans2;

    }
};