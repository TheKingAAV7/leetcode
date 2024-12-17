class Solution {
public:
    string repeatLimitedString(string s, int rL) {
       vector<int>v(26,0);
       priority_queue<pair<char, int>>pq;
       for(char c:s) v[c-'a']++;
       for(int i=0;i<26;i++){
        if(v[i]!=0) {
           // cout<<char(i+'a')<<" "<<v[i]<<endl;
        pq.push({i+'a',v[i]});
        }
       }
       string ans="";
       pair<char,int>store={'A',0};
        int cnt=0;
        while(!pq.empty()){
            auto [x,y]=pq.top();
            
        // cout<<x<<" "<<y<<endl;
            
            pq.pop();
            if(ans.empty() || (!ans.empty() and ans.back()!=x)){
                if(store.first!='A') {
               
                pq.push(store);
                store={'A',0};
            }
                cnt=1;
                ans.push_back(x);
                y=y-1;
              
                if(cnt==rL){
                    if(y>0){
                    store={x,y};
                    continue;
                    }
                }
                else {
                    if(y>0)
                pq.push({x,y});
                }
                
            }
            else{
                cnt++;
                ans.push_back(x);
            
                y=y-1;
                
                if(cnt==rL){
                    if(y>0){
                    store={x,y};
                  //  cout<<x<<" "<<y<<endl;
                  continue;
                    }
                    
                    
                }
                else{
                    if(y>0)
                 pq.push({x,y});
                }

            }
             
           

            }

        
       
       return ans;
    }
};