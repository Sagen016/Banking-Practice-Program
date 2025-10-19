#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
void withdraw(double &balance);

int main(){

  double balance = 0;
  int choice = 0;

  do{
    std::cout << "*******************************************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "*******************************************\n";
    std::cout << "1. Show Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit\n";
    std::cin >> choice;

    std::cin.clear();
    fflush(stdin);

    switch (choice){
      case 1: showBalance(balance);
        break;
      
      case 2: balance += deposit();
        showBalance(balance);
        break;

      case 3: withdraw(balance);
        showBalance(balance);
        break;

      case 4: std::cout << "Thanks for visiting!\n";
        break;
      
      default: std::cout << "Invalid choice!!!\n";
        break;
    }
  } while( choice != 4);

  return 0;
}

void showBalance(double balance){
  std::cout << "Your balance is: $" << std::setprecision(3) << std::fixed << balance <<'\n';
}

double deposit(){

  double amount = 0;

  std::cout << "Please enter the amount to be deposited: $ ";
  std::cin >> amount;

  if (amount > 0)
  {
    return amount;
  }
  else
  {
    std::cout << "That's not a valid amount!!!";

    return 0;
  }
  
}

void withdraw(double &balance){
      
  double amount = 0;

  std::cout << "Please enter the amount to withdraw: $";
  std::cin >> amount;

  if (amount <= balance && amount > 0){
    balance -= amount;
    std::cout << "Withdraw Successful!\n";
  }
  else{
    std::cout << "Insufficient Balance !!!!\n";
  }

}
