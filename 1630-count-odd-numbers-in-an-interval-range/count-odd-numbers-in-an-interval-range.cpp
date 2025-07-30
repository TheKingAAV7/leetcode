class Solution {
public:
    int countOdds(int low, int high) {
        int odl=(low%2==0)?(low/2):(low/2 + 1);
        int odr=(high%2==0)?(high/2):(high/2)+1;
        return (odr-odl+(low&1));
    }
};