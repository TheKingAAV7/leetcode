class Bank {
private:
vector<long long>b;
int n;
public:
    Bank(vector<long long>& balance) {
      n=balance.size();
      b=balance;  
    }
    
    bool transfer(int a1, int a2, long long money) {
        a1--;
        a2--;
        if(a1>=0 and a1<n and a2>=0 and a2<=n){
            if(b[a1]>=money){
                b[a1]-=money;
                b[a2]+=money;
                return true;
            }
            return false;
        }
        return false;
    }
    
    bool deposit(int ac, long long money) {
        ac--;
        if(ac>=0 and ac<n){
        b[ac]+=money;
        return true;
        }
        return false;
    }
    
    bool withdraw(int ac, long long money) {
        ac--;
        if(ac>=0 and ac<n){
        if(b[ac]>=money){
            b[ac]-=money;
            return true;
        }
        return false;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */