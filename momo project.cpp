#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


bool authenticate();
void resetPin();
void checkBalance();
void sendMoney();
void momoUser();
void token();
void nonMomo();

void display(){
    // Display welcome message and menu
    cout << "Welcome to Mobile Money Service!" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Send Money" << endl;
    cout << "3. Reset/Change PIN" << endl;
    cout << "4. Exit" << endl;
}
// public variables
string userPin = "0000";
string newPin1;
string newPin2;
float userBalance = 4000.0;
string pin;
int choice;


int main() {
    display();
    // Loop until exit option is selected

    do {
        // Get user's menu choice
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        // Perform the selected action
        switch (choice) {
            case 1:
                checkBalance();
                system("pause");
                system("cls");
                display();
                break;
            case 2:
                sendMoney();
                system("pause");
                system("cls");
                display();
                break;
            case 3:
                resetPin();
                system("pause");
                system("cls");
                display();
                break;
            case 4:
                cout << "Exiting Mobile Money Service..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

bool authenticate() {
    // Function implementation
    int attempts = 3;
    for(int i= attempts;i > 0; i--){
        cout << "Enter your pin "<<endl;
        cin >> pin;
        if(pin == userPin){
                return true;
        }
            else{
                cout << "you have entered the wrong pin"<<endl;
                if(i == 1){
                    return false;
                }
        }
    }
}

void resetPin() {
    // Function implementation
    if(authenticate() == true){
    cout << "Please enter your new password" << endl;
    cin >> newPin1;
    cout << "Please enter the password again "<< endl;
    cin >> newPin2;
    if(newPin1 == newPin2){
        userPin = newPin1;
    }
    else{
        cout << "Pin code mismatch."<< endl;
        choice = 4;
    }
}
    else{
        choice = 4;
    }
}

void checkBalance() {
    // Function implementation
    if(authenticate() == true){
    cout << "your balance is GHS:" << userBalance<< endl;
    }
    else{
        cout << " you have entered the wrong pin 3 times, you cannot perform this operation. "<<endl;
        choice = 4;
    }
}
void momoUser(){

        float amount;
        float charges;
        float total;
        string number;
        string number2;
        string refer;
        cout << "Enter mobile number "<<endl;
        cin >> number;
        cout << "Confirm number "<<endl;
        cin >> number2;
        if(number != number2){
            cout<<"Number mismatch "<<endl;
            choice = 4;
            }
        else{
            cout<<"amount "<<endl;
            cin >> amount;
            charges = amount/100;
            total = amount + charges;
            if(total > userBalance){
                cout << "Insufficient balance "<<endl;
                choice = 4;
            }
            else{
                cout << "Enter reference "<<endl ;
                cin >> refer;
                 if(authenticate() == true){
                        userBalance = userBalance - total;
                 cout << "Payment made for GHS"<< amount<<" to "<< number<<". Reference: "<< refer<<
                 " Charges: GHS"<<charges<< ". Your new balance is GHS"<<userBalance<<endl;
            }
            else{
                choice = 4;
            }
        }
    }
}
void token(){

        float amount;
        float charges;
        float total;
        string number;
        string number2;
        string token;
        cout << "Enter mobile number " <<endl;
        cin >> number;
        cout << "Confirm number " <<endl;
        cin >> number2;
        if(number != number2){
            cout<<"Number mismatch " <<endl;
            choice = 4;
            }
        else{
            cout<<"amount " <<endl;
            cin >> amount;
            charges = amount/100;
            total = amount + charges;
            if(total > userBalance){
                cout << "Insufficient balance " <<endl ;
                choice = 4;
            }
            else{
                cout << "Enter token code " <<endl;
                cin >> token;
                 if(authenticate() == true){
                        userBalance = userBalance - total;
                 cout << "Payment made for GHS"<< amount<<" to "<< number<<". Token code: "<< token<<
                 " Charges: GHS"<<charges<< ". Your new balance is GHS"<<userBalance<<endl;
            }
            else{
                choice = 4;
            }
        }
    }
}
void nonMomo(){
    cout << "Choose Network" << endl;
    cout << "1. AirtelTigo" << endl;
    cout << "2. Vodafone" << endl;
    cout << "3. Glo" << endl;
    cout << "4. Ezwich" << endl;

        int select;

        cin >> select;

        // Perform the selected action
        switch (select) {
            case 1:
                momoUser();
                break;
            case 2:
                momoUser();
                break;
            case 3:
                momoUser();
                break;
            case 4:
                momoUser();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

}


void sendMoney() {
    system("cls");
    // switch case for momo user, non momo user, send with care, favorite, other networks, bank account, back (0)
    cout << "Transfer Money" << endl;
    cout << "1. Momo User" << endl;
    cout << "2. Non Momo User" << endl;
    cout << "3. Other Networks" << endl;
    cout << "0. Back" << endl;

        // Get user's menu choice
        int select;

        cin >> select;

        // Perform the selected action
        switch (select) {
            case 1:
                momoUser();
                system("pause");
                system("cls");
                display();
                break;
            case 2:
                token();
                system("pause");
                system("cls");
                display();
                break;
            case 3:
                nonMomo();
                system("pause");
                system("cls");
                display();
                break;
            case 0:
                system("cls");
                display();
                cout << "4. Exit" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
}

