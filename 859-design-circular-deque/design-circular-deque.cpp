class MyCircularDeque {
    deque<int>dq;
    int size;
   
public:
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(dq.size()==size) return false;
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(dq.size()==size) return false;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(dq.size()){
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(dq.size()){
            dq.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(dq.size()) return dq.front();
        return -1;
        
    }
    
    int getRear() {
        if(dq.size()) return dq.back();
        return -1;
        
    }
    
    bool isEmpty() {
        return dq.size()==0;
        
    }
    
    bool isFull() {
        return dq.size()==size;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */