class Solution {
public:
    vector<int> countMentions(int nusers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),[&](vector<string>&a,vector<string>&b)->bool{
            int num1=0;
            int num2=0;
            
            for(int i=0;i<a[1].length();i++){
                num1=num1*10 + (a[1][i]-'0');   
            }
            for(int i=0;i<b[1].length();i++){
                num2=num2*10 + (b[1][i]-'0');   
            }
            if(num1!=num2)
            return num1<num2;

            if(a[0]==b[0]) return num1<num2;
            
            return a[0]=="OFFLINE";
            });
        vector<int>ans(nusers,0);
        vector<int>isonline(nusers);
        // for(auto it:events){
        //     for(auto i:it) cout<<i<<" ";
        //     cout<<endl;
        // }
        for(auto &it:events){
            if(it[0]=="MESSAGE"){
               
                int ts=0;
                for(int i=0;i<it[1].length();i++) ts=(ts*10 + it[1][i]-'0');
                // cout<<"YES " <<ts<<endl;
                if(it[2]=="ALL"){
                    for(int i=0;i<nusers;i++){
                        ans[i]++;
                    }
                }
                else if(it[2]=="HERE"){
                    for(int i=0;i<nusers;i++){
                       if(isonline[i]<=ts)
                         ans[i]++;
                    }
                }
                else{
                    vector<int>ids;
                   int len= it[2].length();
                   int i=2;
                   while(i<len){
                    int cur_id=0;
                    while(i<len and it[2][i]!=' '){
                        cur_id=(cur_id*10 + it[2][i]-'0');
                        i++;
                    }
                    
                    ids.push_back(cur_id);
                    i+=3;
                }
                for(auto id:ids){
                   // cout<<id<<" d";
                   ans[id]++;
                }
                //cout<<endl;
               
                }
            }
            else{
                int id=0;
                int ts=0;
                for(int i=0;i<it[1].length();i++) ts=(ts*10 + it[1][i]-'0');
                for(int i=0;i<it[2].length();i++){
                    id=(id*10 + it[2][i]-'0' );
                }
                isonline[id]= ts+60;
            }

            // for(int i=0;i<nusers;i++) cout<<ans[i]<<" ";
            // cout<<endl;
        }
        
        return ans;
    }
};