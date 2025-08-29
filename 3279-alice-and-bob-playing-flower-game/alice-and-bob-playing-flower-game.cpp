#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll od1= (n+1)/2;
        ll ev1=n-od1;
        ll od2=(m+1)/2;
        ll ev2=(m-od2);

        ll ans=od1*ev2 + ev1*od2;
        return ans;
        
    }
};