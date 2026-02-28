class Solution {
public:
    string mergeCharacters(string s, int k) {

        while(true){
            int n=s.length();
            bool found=false;
            // cout<<s<<endl;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(j-i<=k){
                        //cout<<s[i]<<" "<<s[j]<<endl;
                        if(s[i]==s[j]){
                          //  cout<<"YES"<<endl;
                            found=true;
                            s.erase(j,1);
                            break;
                        }
                        // else break;
                    }
                    else break;
                }
                if(found) break;
            }
            //cout<<s<<endl;
            if(!found) break;

        }
        return s;
    }
};