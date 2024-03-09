class Cashier {
    int i, N, disc;
    unordered_map<int,int> prod;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        i = 0;
        N = n;
        disc = discount;
        for(int i=0; i<products.size(); i++){
            int id = products[i];
            int price = prices[i];
            prod[id] = price;
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        i++;
        double bill = 0;
        for(int i=0; i<product.size(); i++){
            int id = product[i];
            int amt = amount[i];
            bill += prod[id] * amt;
        }
        if(i % N == 0){ // disc
            bill = bill * ((100-disc) * 0.01);
        }
        return bill;
        
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */