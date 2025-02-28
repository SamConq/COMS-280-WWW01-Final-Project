// COMS-280-WWW01 Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void homePage() {               // landing page for the program, user can choose to login or signup, user MUST login to an account before continuing
    
    int userChoice = 0;

    do {
        std::cout << "=================================================\n"; // Landing page for the program
        std::cout << "      Welcome to Conquest Banking!\n";                // User MUST login to an account before they can continue
        std::cout << "Please login or create an account to get started\n";  
        std::cout << "=================================================\n";
        std::cout << "\n";
        std::cout << "[1] Press 1 to login using an existing account\n";
        std::cout << "[2] Press 2 to create a new account\n";
        std::cout << "\n";

        std::cin >> userChoice;
        
    } while (userChoice != 1 && userChoice != 2);

    if (userChoice == 1) {
        std::cout << "Login";
    }
    if (userChoice == 2) {
        std::cout << "Signup";
    }
    
}

void createAccount() {          // user can create a brand new account, creating login credentials that are saved to a text file

}
void login() {                  // user can attempt to login to an existing account; if a matching account is found within the accounts text file, they are loggin in successfully

}

class AccountInfo {             // class for handling account information

private:
    std::string username;
    std::string password;
    double checkingsBalance;
    double savingsBalance;

    void checkBalance() {       // user can view balances of their checkings and savings accounts

    }

    void withdrawFunds() {      // user can withdraw money from checkings or savings account

    }

    void depositFunds() {       // user can deposit money to checkings or savings account

    }

    void transactionHistory() { // user can view history of transactions on their account (transactions will be saved to a text file)

    }

    void accountManagement() {  // user can change their login information, logout of their account and return to the home page, or delete their account

    }

};


int main()
{
    homePage();
}


