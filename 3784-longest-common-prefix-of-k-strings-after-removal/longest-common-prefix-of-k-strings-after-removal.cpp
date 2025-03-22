class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        int mxlen=0;
        for(auto &it:words){
            mxlen=max((int)it.length(),mxlen);
            string tmp="";
            for(auto c:it){
                tmp.push_back(c);
                mp[tmp]++;
            }
        }
        vector<int>mx_freq(mxlen+1,0),secmx_freq(mxlen+1,0);
        vector<string>mx_freqstr(mxlen+1,"");
        for(auto& [str,freq]:mp){
            int n=str.length();
            if(freq>mx_freq[n]){
                secmx_freq[n]=mx_freq[n];
                mx_freq[n]=freq;
                mx_freqstr[n]=str;
            }
            else if(freq>secmx_freq[n]){
                secmx_freq[n]=freq;
            }
        }
        
        int m=words.size();
        vector<int>ans(m,0);
        for(int i=0;i<m;i++){
            string curr=words[i];
            int lo=1,hi=mxlen;
            int tm=0;
            while(lo<=hi){
                int mid=(lo+hi)>>1;
                if(curr.size()>=mid and curr.substr(0,mid)==mx_freqstr[mid] ){
                    if(secmx_freq[mid]>=k){
                        tm=mid;
                        lo=mid+1;
                    }
                    else if((mx_freq[mid]-1)>=k){
                        tm=mid;
                        lo=mid+1;
                    }
                    else hi=mid-1;
                }
                else{
                    if(mx_freq[mid]>=k){
                    tm=mid;
                    lo=mid+1;
                    }
                    else hi=mid-1;
                }
            }
            ans[i]=tm;
        }

        return ans;
        
    }
};