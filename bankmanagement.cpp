
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Customer
{
private:
    int account_number;
    string name;
    float balance;

public:
    Customer(int acc_num, const string &customer_name, float initial_balance) : account_number(acc_num), name(customer_name), balance(initial_balance) {}

    int getAccountNumber() const
    {
        return account_number;
    }

    string getName() const
    {
        return name;
    }

    float getBalance() const
    {
        return balance;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << "Amount deposited successfully. Updated balance: " << balance << endl;
    }

    void withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Amount withdrawn successfully. Updated balance: " << balance << endl;
        }
    }

    void updateCustomer(const string &new_name)
    {
        name = new_name;
        cout << "Customer details updated successfully." << endl;
    }
};

class Bank
{
private:
    vector<Customer> customers;

public:
    void addCustomer()
    {
        int acc_num;
        string name;
        float initial_balance;

        cout << "Enter account number: ";
        cin >> acc_num;
        cout << "Enter name: ";
        cin.ignore(); // To handle getline after cin
        getline(cin, name);
        cout << "Enter initial balance: ";
        cin >> initial_balance;

        Customer newCustomer(acc_num, name, initial_balance);
        customers.push_back(newCustomer);
        cout << "Customer added successfully." << endl;
    }

    void deposit()
    {
        int acc_num;
        float amount;
        cout << "Enter account number: ";
        cin >> acc_num;

        for (auto &customer : customers)
        {
            if (customer.getAccountNumber() == acc_num)
            {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                customer.deposit(amount);
                return;
            }
        }

        cout << "Account number not found." << endl;
    }

    void withdraw()
    {
        int acc_num;
        float amount;
        cout << "Enter account number: ";
        cin >> acc_num;

        for (auto &customer : customers)
        {
            if (customer.getAccountNumber() == acc_num)
            {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                customer.withdraw(amount);
                return;
            }
        }

        cout << "Account number not found." << endl;
    }

    void update()
    {
        int acc_num;
        string new_name;
        cout << "Enter account number to update: ";
        cin >> acc_num;

        for (auto &customer : customers)
        {
            if (customer.getAccountNumber() == acc_num)
            {
                cout << "Enter new name :  ";
                cin.ignore(); // To handle getline after cin
                getline(cin, new_name);
                customer.updateCustomer(new_name);
                return;
            }
            //   update :->
        }

        cout << "Account number not found." << endl;
    }

    void show()
    {
        cout << "\n--- Customer Details ---\n";
        for (const auto &customer : customers)
        {
            cout << "Account Number: " << customer.getAccountNumber() << endl;
            cout << "Name: " << customer.getName() << endl;
            cout << "Balance: " << customer.getBalance() << endl
                 << endl;
        }
    }
};

int main()
{
    Bank bank;
    int choice;

    do
    {
        cout << "\nBank Management System\n";
        cout << "1. Add Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Update Customer\n";
        cout << "5. Show All Customers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.addCustomer();
            break;
        case 2:
            bank.deposit();
            break;
        case 3:
            bank.withdraw();
            break;
        case 4:
            bank.update();
            break;
        case 5:
            bank.show();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
