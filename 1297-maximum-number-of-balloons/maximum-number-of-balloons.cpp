class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int b,a,l,o,n;
        b=a=l=o=n=0;
        for(char &c:s){
            if(c=='b') b++;
            else if(c=='a') a++;
            else if(c=='o') o++;
            else if(c=='l') l++;
            else if(c=='n') n++;
        }

        return min({b,a,l/2,o/2,n});
    }
};