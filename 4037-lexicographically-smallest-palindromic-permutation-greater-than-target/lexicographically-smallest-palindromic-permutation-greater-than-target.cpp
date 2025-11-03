class Solution {
public:
    string lexPalindromicPermutation(string s, string tar) {
        /*


        1) check if the  palindrome can be made
        1) Even length  :
            Go till half, try if each prefix can be made, choose the next index assing 

        2) oD len:
          Note: We can never use that od character.. as a differentiator


          we have to just check for od character..
          if that character is greater than the middle char of tar

          if the differentiator index is od.. Then we can use odchar as well

          s= aaacaaa
          tar = aaabaaa
          aac 

            
        */

        string ans="";
        int n= s.length();

        vector<int>mp(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }   
        int odcnt=0;
        char odchar='.';
        for(int i=0;i<26;i++){
            if(mp[i]%2){
             odcnt++;
             odchar=i+'a';
            }
            else mp[i]/=2;
        }
        if(odcnt>=2) return "";

        if(odcnt==0){

            string ss="";
           
            vector<int>ssmp(mp.begin(),mp.end());
            for(int j=25;j>=0;j--){
                while(ssmp[j]>0){
                    ss.push_back(j+'a');
                    ssmp[j]--;
                }
            }
            string fin=ss;
            reverse(fin.begin(),fin.end());
            ss= ss+fin;
            if(ss<=tar) return "";
            ans=ss;

           
            vector<int>req(26,0);
            int len= n/2;
            string pref="";

            for(int i=-1;i<len-1;i++){
                
                if(i>=0) {
                 req[tar[i]-'a']++;
                 pref.push_back(tar[i]);
                }
                

                // check if we can make this pref;
                vector<int>cur(mp.begin(),mp.end());
                bool ispossible=true;
                for(int j=0;j<26;j++){
                    if(cur[j]>=req[j]){
                        cur[j]-=req[j];
                    }
                    else{
                        ispossible=false;
                        break;
                    }
                }
                if(!ispossible) continue;
               
               


               

                // find differentiater
                int req_pos= tar[i+1] - 'a';
                char req_chr='.';
                for(int j=req_pos+1;j<26;j++){
                    if(cur[j]>=1){
                        req_chr= j+'a';
                        cur[j]--;
                        break;
                    }
                }
                if(req_chr=='.') continue;
                string tmp= pref;
                tmp.push_back(req_chr);
                for(int j=0;j<26;j++){
                    while(cur[j]>0){
                        tmp.push_back(j+'a');
                        cur[j]--;
                    }
                }
                string bac= tmp;
                reverse(bac.begin(),bac.end());
                string candidate= tmp+bac;
                if(ans=="" || candidate<ans){
                    ans=candidate;
                }
                
            }

            {
                string half = tar.substr(0, len);
                vector<int> cur(mp.begin(), mp.end());
                bool ok = true;
                for(char c: half){
                    if(cur[c - 'a'] > 0) cur[c - 'a']--;
                    else { ok = false; break; }
                }
                if(ok){
                    string tmp = half;
                    string bac = tmp;
                    reverse(bac.begin(), bac.end());
                    string candidate = tmp + bac;
                    if(candidate > tar && (ans == "" || candidate < ans)) ans = candidate;
                }
            }
            
            return ans;

        }


        
        
      

        mp[odchar-'a']--;
        mp[odchar-'a']/=2;


        string ss="";
           
            vector<int>ssmp(mp.begin(),mp.end());
            for(int j=25;j>=0;j--){
                while(ssmp[j]>0){
                    ss.push_back(j+'a');
                    ssmp[j]--;
                }
            }
            string fin=ss;
            reverse(fin.begin(),fin.end());
            ss= ss+odchar+fin;
            if(ss<=tar) return "";
            ans=ss;
        
        
        for(int i:mp) cout<<i<<" ";
        cout<<endl;



            vector<int>req(26,0);
            int len= n/2;
            string pref="";
          
            for(int i=-1;i<len-1;i++){
                if(i>=0) {
                 req[tar[i]-'a']++;
                 pref.push_back(tar[i]);
                }
                

                // check if we can make this pref;
                vector<int>cur(mp.begin(),mp.end());
                bool ispossible=true;
                for(int j=0;j<26;j++){
                    if(cur[j]>=req[j]){
                        cur[j]-=req[j];
                    }
                    else{
                        ispossible=false;
                        break;
                    }
                }
                if(!ispossible) continue;

               

                // find differentiater
                int req_pos= tar[i+1] - 'a';
                char req_chr='.';
                for(int j=req_pos+1;j<26;j++){
                    if(cur[j]>=1){
                        req_chr= j+'a';
                        cur[j]--;
                        break;
                    }
                }
                if(req_chr=='.') continue;
                string tmp= pref;
                tmp.push_back(req_chr);
                for(int j=0;j<26;j++){
                    while(cur[j]>0){
                        tmp.push_back(j+'a');
                        cur[j]--;
                    }
                }
                string bac= tmp;
                reverse(bac.begin(),bac.end());
                string candidate= tmp+odchar+bac;
                if(ans=="" || candidate<ans){
                    ans=candidate;
                }
                
            }


             {
                string half = tar.substr(0, len);
                vector<int> cur(mp.begin(), mp.end());
                bool ok = true;
                for(char c: half){
                    if(cur[c - 'a'] > 0) cur[c - 'a']--;
                    else { ok = false; break; }
                }
                if(ok){
                    string tmp = half;
                    string bac = tmp;
                    reverse(bac.begin(), bac.end());
                    string candidate = tmp + odchar + bac;
                    if(candidate > tar && (ans == "" || candidate < ans)) ans = candidate;
                }
            }
            

            if(odchar>tar[len]){
               
                
                vector<int>req(26,0);
                vector<int>cur(mp.begin(),mp.end());
                string pref="";
                for(int i=0;i<len;i++) {
                    pref.push_back(tar[i]);
                    req[tar[i]-'a']++;
                }

                for(int i:req) cout<<i<<" ";
                cout<<endl;
                bool ispossible=true;
                for(int j=0;j<26;j++){
                    if(cur[j]>=req[j]){
                        cur[j]-=req[j];
                    }
                    else{
                        ispossible=false;
                        break;
                    }
                }
                if(!ispossible) return ans;
                
                string tmp1=pref;
                reverse(tmp1.begin(),tmp1.end());

                pref.push_back(odchar);
                pref=pref+tmp1;

                
                if(ans=="" || pref<ans){
                    ans=pref;
                }
                
            }
            return ans;




        return "";


    }

};