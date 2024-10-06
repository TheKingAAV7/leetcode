class Solution {
public:
    bool areSentencesSimilar(string s, string t) {
        if(s==t) return true;
        vector<int>v1,v2;
        string tmp,tmp1;
        int n=s.length();
        int m=t.length();
        if(n==m) return false;
        if(n<m){
            tmp=s;
            tmp1=t;
        }
        else{
            tmp=t;
            tmp1=s;
        }

        unordered_map<string, int>mp;
        int cnt=1;
        for(int i=0;i<min(n, m);i++){
            string st="";
            while(i<min(n, m) and tmp[i]!=' '){
                st+=tmp[i];
                i++;
            }
            if(mp.find(st)!=mp.end()){
                v1.push_back(mp[st]);
            }
            else{
             mp[st]=cnt;
             v1.push_back(cnt++);
            }
        }

        for(int i=0;i<max(n, m);i++){
            string st="";
            while(i<max(n, m) and tmp1[i]!=' '){
                st+=tmp1[i];
                i++;
            }
            
            if(mp.find(st)!=mp.end()){
             //   cout<<"yse"<<endl;
                v2.push_back(mp[st]);
            }
            else v2.push_back(cnt++);

        }
        for(int i:v1) cout<<i<<" ";
        cout<<endl;
         for(int i:v2) cout<<i<<" ";
        cout<<endl;

        cout<<"********"<<endl;
       int l=v1.size(),k=v2.size();
       int i1=0,i2=0;
       int j1=l-1,j2=k-1;
       while(i1<l  and i2<k and v1[i1]==v2[i2]){
        i1++;
        i2++;
       }
       while(j1>=0 and j2>=0 and v1[j1]==v2[j2]){
        j1--;
        j2--;
       }

       vector<int>ans1, ans2;
       for(int i=i1;i<=j1;i++)
       ans1.push_back(v1[i]);
       for(int i=i2;i<=j2;i++)
       ans2.push_back(v2[i]);

        if(ans1.empty() || ans2.empty()) return true;

        return ans1==ans2;

       
       

        

        
    }
};