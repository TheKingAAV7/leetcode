class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        
            string a= to_string(low);
            string b= to_string(high);
            string tmp="";
            for(int j=a.length();j<=b.length();j++){
               
                for(char c='1';c<'9';c++){
                tmp="";
                bool f=1;
                for(int i=0;i<j  ;i++){
                    if((c+i)<='9')
                   tmp+=(c+i);
                   else {
                    f=0;
                    break;
                   }

                }

                cout<<tmp<<endl;
                if(f and stoi(tmp)>=low and stoi(tmp)<=high and b.length()>=tmp.length()){
                    ans.push_back(stoi(tmp));
                }
                }

            }
            return ans;


        
        
    }
};