#include <iostream>
#include <mutex>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    int balance;
    bool isOpen;
    mutex mtx;

public:
    BankAccount() {
        balance = 0;
        isOpen = false;
    }

    void open() {
        lock_guard<mutex> lock(mtx);
        if (isOpen) throw runtime_error("Account already open");
        isOpen = true;
        balance = 0;
    }

    void close() {
        lock_guard<mutex> lock(mtx);
        if (!isOpen) throw runtime_error("Account not open");
        isOpen = false;
    }

    void deposit(int amount) {
        lock_guard<mutex> lock(mtx);
        if (!isOpen) throw runtime_error("Account closed");
        if (amount < 0) throw runtime_error("Invalid amount");
        balance += amount;
    }

    void withdraw(int amount) {
        lock_guard<mutex> lock(mtx);
        if (!isOpen) throw runtime_error("Account closed");
        if (amount < 0 || balance < amount) throw runtime_error("Invalid operation");
        balance -= amount;
    }

    int getBalance() {
        lock_guard<mutex> lock(mtx);
        if (!isOpen) throw runtime_error("Account closed");
        return balance;
    }
};

int main() {
    BankAccount acc;
    int option, amount;

    acc.open();

    while (true) {
        cout << "1. Depositar\n2. Retirar\n3. Ver saldo\n4. Salir\nOpcion: ";
        cin >> option;

        if (option == 1) {
            cout << "Monto: ";
            cin >> amount;
            acc.deposit(amount);
        } 
        else if (option == 2) {
            cout << "Monto: ";
            cin >> amount;
            acc.withdraw(amount);
        } 
        else if (option == 3) {
            cout << "Saldo: " << acc.getBalance() << endl;
        } 
        else {
            break;
        }
    }

    acc.close();
}
