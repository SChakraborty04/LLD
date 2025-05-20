//Liskov substitution principle violated
#include<bits/stdc++.h>
using namespace std;

class Account {
public:
  virtual void deposit(double amount) = 0;
  virtual void withdraw(double amount) = 0;
};
class SavingAccount : public Account {
private:
  double balance;
public:
  SavingAccount(){
    balance = 0;
  }
  void deposit(double amount) {
    balance += amount;
    cout << "Deposited " << amount << " to Saving Account." << endl;
  }
  void withdraw(double amount) {
    if (amount > balance) {
      cout << "Insufficient funds in Saving Account." << endl;
      return;
    }
    else{
      balance -= amount;
      cout << "Withdrew " << amount << " from Saving Account." << endl;
    }

  }
};
class CurrentAccount : public Account {
private:
  double balance;
public:
  CurrentAccount() {
    balance = 0;
  }
  void deposit(double amount) {
    balance += amount;
    cout << "Deposited " << amount << " to Current Account." << endl;
  }
  void withdraw(double amount) {
    if (amount > balance) {
      cout << "Insufficient funds in Current Account." << endl;
      return;
    }
    else{
      balance -= amount;
      cout << "Withdrew " << amount << " from Current Account." << endl;
    }

  }
};
class FixedDepositAccount : public Account {
public:
  void deposit(double amount) {
    cout << "Deposited " << amount << " to Fixed Deposit Account." << endl;
  }
  //Cant withdraw
  void withdraw(double amount) {
    throw logic_error("Cannot withdraw from Fixed Deposit Account.");
  }
};

class BankClient {
private:
  vector<Account*> accounts;
public:
  BankClient(vector<Account*>accounts){
    this->accounts = accounts;
  }
  void processTransactions(){
    for(auto account : accounts){
      account->deposit(1000); //All accounts allow deposits
      //Asuming all account allow withdrawal
      try{
        account->withdraw(500);
      }
      catch(logic_error& e){
        cout << "Exception: "<< e.what() << endl;
      }
    }
  }
};

int main(){
  SavingAccount sa;
  CurrentAccount ca;
  FixedDepositAccount fda;

  vector<Account*> accounts = {&sa, &ca, &fda};
  BankClient client(accounts);
  client.processTransactions(); //Throw exception while withdrawing from Fixed Deposit Account
  return 0;
}