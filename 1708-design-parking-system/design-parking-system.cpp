class ParkingSystem {
public:
    int spot[4];
    ParkingSystem(int big, int medium, int small) {
        spot[1]=big;
        spot[2]=medium;
        spot[3]=small;
    }
    
    bool addCar(int carType) {
        if(spot[carType]>0){
            spot[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */