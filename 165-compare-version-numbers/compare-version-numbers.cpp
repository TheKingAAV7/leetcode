class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size();
        int m=v2.size();
        int i=0,j=0;
        int a=0,b=0;
        while(i<n and j<m){
            if(v1[i]=='.' ){
                while(j<m and v2[j]!='.'){
                    b=b*10+(v2[j]-'0');
                    j++;
                }
              
                if(a>b) return 1;
                if(a<b) return -1;
                a=0;
                b=0;
                i++;
                j++;
            }
            else if(v2[j]=='.'){
                while(i<n and v1[i]!='.'){
                    a=a*10+(v1[i]-'0');
                    i++;
                }
                if(a>b) return 1;
                if(a<b) return -1;
                a=0;
                b=0;
                i++;
                j++;
            }
            else{
                a=a*10+(v1[i]-'0');
                b=b*10+(v2[j]-'0');
                i++;
                j++;
            }
        }
        
         if(i==n){
         while(j<m and v2[j]!='.'){
                    b=b*10+(v2[j]-'0');
                    j++;
                }
              
                if(a>b) return 1;
                if(a<b) return -1;
            
         }

        
        if(j==m){
        while(i<n and v1[i]!='.'){
                    a=a*10+(v1[i]-'0');
                    i++;
                }
                if(a>b) return 1;
                if(a<b) return -1;

        }
        
        if(i==n and j==m){
            return 0;
        }
      
        a=0;
        b=0;
        // if(v1[i]=='.') i++;
        // if(v2[j]=='.') j++;
       //cout<<i<<" "<<j<<endl;
        while(i<n){
            if(v1[i]=='.'){
               // cout<<a<<endl;
                if(a>0) return 1;
                a=0;
            }
            else{
                a=a*10+(v1[i]-'0');
            }
            i++;
        }

        while(j<m){
            if(v2[j]=='.'){
                if(b>0) return -1;
                b=0;
            }
            else{
                b=b*10+(v2[j]-'0');
            }
            j++;
        }
          if(a>b) return 1;
                if(a<b) return -1;

        return 0;
        

    }
};