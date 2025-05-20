#include<bits/stdc++.h>
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
class ShoppingCart{
private:
    vector<Product> products;
public:

    void addProduct(Product p){
        products.push_back(p);
    }
    void removeProduct(string productName){
        for(auto it = products.begin(); it != products.end(); ++it){
            if(it->name == productName){
                products.erase(it);
                break;
            }
        }
    }
    const vector<Product>& getProducts(){
        return products;
    }
    double calculateTotal(){
        double total = 0;
        for(auto p : products){
            total += p.price;
        }
        return total;
    }
};
class ShoppingCartPrinter{
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* c){
        cart=c;
    }
    void printReceipt(){
        cout << "Receipt:" << endl;
        for(auto p : cart->getProducts()){
            cout << p.name << ": $" << p.price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};
// It violate Open Close Principle as it adds new methods to a previously defined class
class ShoppingCartDB{
private:
    ShoppingCart* cart;
public:
    ShoppingCartDB(ShoppingCart* c){
        cart=c;
    }
    void saveToSQLDB(){
        // Simulate saving to database
        cout << "Shopping cart saved to SQL database." << endl;
    }
    void saveToMongo(){
        // Simulate saving to MongoDB
        cout << "Shopping cart saved to MongoDB." << endl;
    }
    void saveToFile(){
        // Simulate saving to file
        cout << "Shopping cart saved to file." << endl;
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
    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printReceipt();
    ShoppingCartDB *db = new ShoppingCartDB(cart);
    db->saveToSQLDB();
    db->saveToMongo();
    db->saveToFile();
}