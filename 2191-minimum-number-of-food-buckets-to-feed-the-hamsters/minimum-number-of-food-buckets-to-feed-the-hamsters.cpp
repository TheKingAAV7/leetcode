class Solution {
public:   
    int minimumBuckets(string ham) {
        int n=ham.size();
     
        int cnt=0;
        vector<int>ind;
        for(int i=0;i<n;i++){
            if(ham[i]=='H') ind.push_back(i);
        }
        for(auto idx:ind){
            if(idx-1>=0 and ham[idx-1]=='@') continue;
            if(idx<n and ham[idx+1]=='@') continue;
            if(idx+1<n and ham[idx+1]=='.'){
                ham[idx+1]='@';
                cnt++;
            }
            else if(idx-1 >=0 and ham[idx-1]=='.'){
                ham[idx-1]='@';
                cnt++;
            }
            else return -1;
        }
       
        return cnt;
    }
};