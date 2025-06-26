class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans=0;
        int num=0;
        int n=s.length();
        int lef=n,rig=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans++;
                lef=min(lef,i);
                rig=max(rig,i);
            }
        }
        
       
        int last=0;
       
        for(int i=rig+1;i<n;i++){

         
            int tmp=num|(1<<last);
            if(tmp<=k){
                ans++;
                num=tmp;
                last++;
            }
            else break;
        }
        
        if(rig==-1) return ans;
        
        for(int i=rig;i>=lef;i--){
           
            if(s[i]=='1'){
                int bit_to_set=(rig-i+last);
             //cout<<bit_to_set<<endl;
                if(bit_to_set<=29){
                    int tmp=num|(1<<bit_to_set);
                    if(tmp<=k){
                         //cout<<tmp<<endl;
                        // cout<<bit_to_set<<endl;
                        ans++;
                        num=tmp;
                      
                    }
                    else break;
                }
            }
        }
        if(ans>=29) return ans;
        int prev=ans;
        for(int i=lef-1;i>=0;i--){
            int tmp=(num|(1<<prev));
            if(tmp<=k){
                
                num=tmp;
                ans++;
                prev++;
            }
            else break;
        }
        return ans;
    }
};