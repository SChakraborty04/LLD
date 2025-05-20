//In correct LSP implementation, we will not change the client side code(business logic).
#include<bits/stdc++.h>
using namespace std;

class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};
class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};
class SavingAccount : public WithdrawableAccount {
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
class CurrentAccount : public WithdrawableAccount {
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
class FixedDepositAccount : public DepositOnlyAccount {
  private:
    double balance;
public:
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " to Fixed Deposit Account." << endl;
    }
    //Cant withdraw
};
class BankClient {
private:
    vector<DepositOnlyAccount*> depositeOnlyAccounts;
    vector<WithdrawableAccount*> withdrawableAccounts;
public:
  BankClient(vector<DepositOnlyAccount*> d, vector<WithdrawableAccount*> w){
    depositeOnlyAccounts=d;
    withdrawableAccounts=w;
  }
  void processTransactions(){
    for(auto account:depositeOnlyAccounts){
      account->deposit(1000);
    }
    for(auto account:withdrawableAccounts){
      account->deposit(1000);
      account->withdraw(500);
    }
  }
};

int main(){
    vector<DepositOnlyAccount*> depositeOnlyAccounts;
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    depositeOnlyAccounts.push_back(new FixedDepositAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    BankClient *client = new BankClient(depositeOnlyAccounts, withdrawableAccounts);
    client->processTransactions();
    return 0;
}