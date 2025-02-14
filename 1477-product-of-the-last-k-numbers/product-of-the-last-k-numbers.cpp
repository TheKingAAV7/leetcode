class ProductOfNumbers {
public:
    int prod=1;
    int zero=-1;
    vector<int>tmp;
    vector<int>arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       if(num==0){
        zero=tmp.size();
        prod=1;
        tmp.push_back(-1);
        arr.push_back(0);
       }
       else{
        prod*=num;
        tmp.push_back(prod);
        arr.push_back(num);
       }
    }
    
    int getProduct(int k) {
        int pos=tmp.size()-k;
        if(pos<=zero){
            return 0;
        }
        return (prod/tmp[pos])*arr[pos];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */