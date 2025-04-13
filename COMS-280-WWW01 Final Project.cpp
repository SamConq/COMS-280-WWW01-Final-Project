// COMS-280-WWW01 Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>              // text file library

void createAccount();           // function declarations
void login();


void homePage() {               // landing page for the program, user can choose to login or signup, user MUST login to an account before continuing
    
    int userChoice = 0;

    do {
        std::cout << "=================================================\n"; 
        std::cout << "      Welcome to Conquest Banking!\n";                
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
        createAccount();
    }
    
}

class Account {             // class for handling account information

private:
    std::string username;
    std::string password;
    
    

public:
    Account(const std::string& user, const std::string& pass)
        : username(user), password(pass) {
    }

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }

    void saveToFile() const {
        std::ofstream outFile("accounts.txt", std::ios::app);               // save login information to text file
        if (outFile.is_open()) {
            outFile << username << " " << password << "\n";
            outFile.close();
        }
    }

    static bool usernameExists(const std::string& username) {               // check if username already exists 
        std::ifstream inFile("accounts.txt");
        std::string existingUsername, existingPassword;
        while (inFile >> existingUsername >> existingPassword) {
            if (existingUsername == username) {
                inFile.close();
                return true;
            }
        }
        return false;
    }


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



void createAccount() {          // user can create a brand new account, creating login credentials that are saved to a text file
    
    std::string username;           
    std::string password;           
    std::string verifyPassword;
    
    std::cout << "=================================================\n";
    std::cout << "      Please enter a username\n";
    std::cout << "=================================================\n";

    std::cin >> username;                                                               // user creates username

    
    while (Account::usernameExists(username)) {                                         // prompt user to choose a different username if username already exists
        std::cout << "=================================================\n";
        std::cout << "      Username already exists! Try another.\n";
        std::cout << "=================================================\n";
        std::cin >> username;
    }


    std::cout << "=================================================\n";
    std::cout << "      Please enter a password\n";
    std::cout << "=================================================\n";

    std::cin >> password;                                                               // user creates password

    std::cout << "=================================================\n";
    std::cout << "      Please confirm your password\n";
    std::cout << "=================================================\n";

    std::cin >> verifyPassword;                                                         // user must confirm their password
    if (password != verifyPassword) {
        do {
            std::cout << "=================================================\n";
            std::cout << "      Incorrect password, please try again\n";
            std::cout << "=================================================\n";
            std::cin >> verifyPassword;
        } while (password != verifyPassword);
    }

    Account newAccount(username, password);                                             // save login info to text file
    newAccount.saveToFile();
    std::cout << "=================================================\n";
    std::cout << "      Account successfully created!\n";
    std::cout << "=================================================\n";
    

}
void login() {                  // user can attempt to login to an existing account; if a matching account is found within the accounts text file, they are loggin in successfully

    std::string usernameLog;
    std::string passwordLog;

    std::cout << "=================================================\n";
    std::cout << "      Please enter your username\n";
    std::cout << "=================================================\n";

    std::cin >> usernameLog;                                                   // user enters existing username

    std::cout << "=================================================\n";
    std::cout << "      Please enter your password\n";
    std::cout << "=================================================\n";

    std::cin >> passwordLog;                                                   // user enters existing password

}




int main()
{
    homePage();
}


