#define ll long long
class Bank {
public:
    vector<ll>arr;
    int n;
    Bank(vector<ll>& balance) {
        arr=balance;  
        n=arr.size();      
    }
    
    bool transfer(int a1, int a2, long long money) {
        a1--;a2--;
        if(a1>=0 and a1<n and a2>=0 and a2<n){
        if(arr[a1]>=money){
            arr[a1]-=money;
            arr[a2]+=money;
            return true;
        }
        }
        return false;
    }
    
    bool deposit(int a, long long money) {
        if(a>=1 and a<=n){
        arr[a-1]+=money;
        return true;
        }
        return false;
    }
    
    bool withdraw(int a, long long money) {
        a--;
       if(a>=0 and a<n){
        if(arr[a]>=money) {
            arr[a]-=money;
            return true;
        }
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