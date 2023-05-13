#include <stdio.h>

struct Bank_Account 
{
    char name[200];
    int account_no;
    float balance;
};

void createAccount(struct Bank_Account *account) 
{
    printf("Enter your full name: ");
    scanf("%s", account->name);
    printf("Enter 5 digit account number: ");
    scanf("%d", &account->account_no);
    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
    printf("\nAccount has been  created !\n\n");
}

void deposit(struct Bank_Account *account) 
{
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposited %.2f and updated balance is %.2f\n\n", amount, account->balance);
}

void withdraw(struct Bank_Account *account) 
{
    float amount;
    printf("Enter withdraw amount: ");
    scanf("%f", &amount);
    if (account->balance >= amount) 
    {
        account->balance -= amount;
        printf("Withdrawn %.2f and updated balance is %.2f\n\n", amount, account->balance);
    } else 
    {
        printf("Insufficient balance! Current balance is %.2f\n\n", account->balance);
    }
}

void displayBalance(struct Bank_Account *account) 
{
    printf("Account holder name: %s\n", account->name);
    printf("Account number: %d\n", account->account_no);
    printf("Current balance: %.2f\n\n", account->balance);
}

int main() 
{
    struct Bank_Account account;
    int choice;
    do {
        printf("Enter 1 to create account\n");
        printf("Enter 2 to deposit\n");
        printf("Enter 3 to withdraw\n");
        printf("Enter 4 to display balance\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                createAccount(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                withdraw(&account);
                break;
            case 4:
                displayBalance(&account);
                break;
            case 0:
                printf("Thank you for using our service!\n");
                break;
            default:
                printf("Invalid input! Try again.\n\n");
        }
    } while (choice != 0);
    return 0;
}
