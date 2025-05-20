#include <bits/stdc++.h>
using namespace std;
//Product representing a item in shopping cart
class Product{
public:
    string name;
    double price;
    Product(string n, double p){
        name = n;
        price = p;
    }
};
// SRP violated: hndling multiple resp. together
class ShoppingCart{
private:
    vector<Product> products;
public:

    void addProduct(Product p){
        products.push_back(p);
    }
    // SRP violation
    void removeProduct(string productName){
        for(auto it = products.begin(); it != products.end(); ++it){
            if(it->name == productName){
                products.erase(it);
                break;
            }
        }
    }
    // SRP violation
    const vector<Product>& getProducts(){
        return products;
    }
    // SRP violation
    double calculateTotal(){
        double total = 0;
        for(auto p : products){
            total += p.price;
        }
        return total;
    }
    // SRP violation
    void printReceipt(){
        cout << "Receipt:" << endl;
        for(auto p : products){
            cout << p.name << ": $" << p.price << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }
    // SRP violation
    void saveToDB(){
        // Simulate saving to database
        cout << "Shopping cart saved to database." << endl;
    }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(Product("PS5", 60000));
    cart->addProduct(Product("GTA6(PS5 Edition)", 20000));
    cart->addProduct(Product("PS5 Controller", 5000));
    cart->addProduct(Product("PS5 Headset", 3000));
    cart->removeProduct("PS5 Controller");
    cout<<"Products in cart:" << endl;
    for(auto p : cart->getProducts()){
        cout << p.name << ": $" << p.price << endl;
    }
    cart->printReceipt();
    cart->saveToDB();
    return 0;
}
