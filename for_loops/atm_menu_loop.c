//Name:Madhav M
//Batch:26025A
//Date:05/10/2026
//Expected outputs:Balance,Deposit,Withdraw and Exit using ATM.

#include<stdio.h>
int main()
{
    float balance,deposit,withdraw;
    int option;
    do{
        balance=0+balance;   //pre-defining a balance amount
        printf("Enter the task to be performed:\n 1.Check Balance\n 2.Deposit Money\n 3.Withdraw Money\n 4.Exit\n"); //Giving choice to the user
        scanf("%d",&option); 
        switch(option)
        {
            case 1:
            printf("The balance amount in your account is Rs.%g/- \n",balance);
            break;
            case 2:
            printf("Enter the amount to be deposited \n");
            printf("Rs:");
            scanf("%f",&deposit);
            balance=balance+deposit;    //updating the current balance amount
            printf("Your balance amount after deposit is Rs.%g/- \n",balance);
            break;
            case 3:
            printf("Enter the amount to be withdrawn:\n");
            printf("Rs:");
            scanf("%f",&withdraw);
            if(balance>=withdraw)
            {
                balance=balance-withdraw;                    // if only withdraw amount is greater than balance amount update the balance 
                printf("The balance amount after withdraw is Rs.%g/-\n",balance);
            }
            else
            {
                printf("You have insufficient balance to withdraw the money!\n");
            }
            break;
            case 4:
            printf("Thankyou for using the ATM! \n");
            break;
            default:
            printf("Invalid input, Enter the correct input and try again!\n");
            break;  
    }
    
    
    }while(option!=4);   //exit from the do-while loop when option=4 which is the exit from the ATM.
    return 0;
}