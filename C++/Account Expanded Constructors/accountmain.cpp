#include <iostream>
#include "account.h"
using namespace std;
int main() {
    int choice = 0;
    int accountNum;
    float accountBalance;
    Account a;
    float amount;
    float interest;
    int year;
    while(choice!=7)
    {
        std::cout<<"\n1.Change the account balance"<<std::endl;
        std::cout<<"\n2.Get the current balance"<<std::endl;
        std::cout<<"\n3.Deposit"<<std::endl;
        std::cout<<"\n4.Withdrawal"<<std::endl;
        std::cout<<"\n5.Plan your future balance"<<std::endl;
        std::cout<<"\n6.Mortgage Plan"<<std::endl;
        std::cout<<"\n7.Exit"<<std::endl;
        std::cout<<"\nEnter a your selection: "<<std::endl;
        std::cin>>choice;

        if (choice == 1)
        {
          std::cout<<"\nEnter the account Number: "<<std::endl;
          std::cin>>accountNum;
          a.setaccountNumber(accountNum);

          std::cout<<"\nEnter a new account balance: "<<std::endl;
          std::cin>>accountBalance;
          a.setaccountBalance(accountBalance);

          std::cout<<"\nNew Account Balance is: "<<accountBalance<<" TL"<<std::endl;
        }
        if (choice == 2)
        {
            a.printBankAccount();

        }
        if (choice == 3)
        {
          std::cout<<"\nEnter an amount to deposit: "<<std::endl;
          std::cin>>amount;
          a.inputTransaction('D',amount);
        }
        if (choice == 4)
        {
          std::cout<<"\nEnter an amount to withdraw: "<<std::endl;
          std::cin>>amount;
          a.inputTransaction('W',amount);
        }
        if (choice == 5)
        {
          std::cout<<"\nEnter the annual interest rate: "<<std::endl;
          std::cin>>interest;

          std::cout<<"\nEnter the number of years: "<<std::endl;
          std::cin>>year;

          a.calculateFutureBalance(interest,year);
        }
        if (choice == 6)
        {
          float mortgageAmount;
          float mortgageInterest;
          float accountInterest;

          std::cout << "\nEnter the mortgage amount: " << std::endl;
          std::cin >> mortgageAmount;

          std::cout << "\nEnter the mortgage interest rate: " << std::endl;
          std::cin >> mortgageInterest;

          std::cout << "\nEnter the account interest rate: " << std::endl;
          std::cin >> accountInterest;

    a.mortgageYear(mortgageAmount, mortgageInterest, accountInterest);
        }
        if (choice == 7)
        {
           std::cout<<"\nGoodbye!"<<std::endl;
        }
    }
}
