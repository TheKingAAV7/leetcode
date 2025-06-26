class ATM {
public:
map<int,int>mp;
vector<int>arr;
    ATM() {
        arr.resize(5,0);
        mp[0]=20;
        mp[1]=50;
        mp[2]=100;
        mp[3]=200;
        mp[4]=500;
    }
    
    void deposit(vector<int> bk) {
        for(int i=0;i<5;i++)  arr[i]+=bk[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        vector<int>prev=arr;
     
        int pos=4;
        while(pos>=0 and arr[pos]==0) pos--;
        if(pos==-1){
            arr=prev;
            return {-1};
        }
       
        while(amount>0 and pos>=0){
            int cnt=amount/mp[pos];
           // cout<<amount<<" "<<mp[pos]<<endl;
          //  if(arr[pos]>cnt) return {-1};
            amount-=(mp[pos]*min(cnt,arr[pos]));
            ans[pos]+=min(cnt,arr[pos]);
            arr[pos]-=min(cnt,arr[pos]);
            
            pos--;
        }
        if(amount==0) return ans;
        arr=prev;
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */