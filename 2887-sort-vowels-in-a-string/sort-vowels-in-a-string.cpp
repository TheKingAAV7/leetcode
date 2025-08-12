class Solution {
public:
    string sortVowels(string s) {
        //EeOe
        vector<char>vow;
        set<char>vowels={'a','e','i','o','u','A','E','I','O','U'};
        for(char c:s){
            if(vowels.find(c)!=vowels.end()){
                vow.push_back(c);
            }
        }
        sort(vow.begin(),vow.end());
        int pos=0;
        for(char &c:s){
            if(vowels.find(c)!=vowels.end()){
                c=vow[pos];
                pos++;
            }
        }
        return s;
    }
};