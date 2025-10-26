class Bank {
public:
    int size;
    vector<long long>curr;
    Bank(vector<long long>& balance) {
        size = balance.size();
        curr.resize(size + 1, 0);
        for(int i = 1; i <= size; i++){
            curr[i] = balance[i - 1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 >= 1 && account1 <= size && account2 >=1 && account2 <= size && curr[account1] >= money){
            curr[account1] -= money;
            curr[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account >= 1 && account <= size){
            curr[account] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account >= 1 && account <= size && curr[account] >= money){
            curr[account] -= money;
            return true;
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