# ATM Simulation in C

A menu-driven ATM program written in C. The user can check the balance, deposit money, withdraw money, or exit. The menu keeps repeating until the user chooses to exit.

## Features

- Check the current balance
- Deposit money and see the updated balance
- Withdraw money, with a check that blocks withdrawals larger than the balance
- Error message for invalid menu options
- Runs in a loop until the user selects Exit

## Menu

```
Enter the task to be performed:
 1.Check Balance
 2.Deposit Money
 3.Withdraw Money
 4.Exit
```

| Option | Action |
|---|---|
| 1 | Shows the current balance |
| 2 | Asks for an amount and adds it to the balance |
| 3 | Asks for an amount and subtracts it, only if the balance is enough |
| 4 | Prints a thank-you message and exits |
| Anything else | Prints an invalid input message and shows the menu again |

## How it works

The program starts with a balance of Rs.0 and runs inside a `do-while` loop, so the menu is always shown at least once. A `switch` statement handles each option. For a withdrawal, the program compares the requested amount with the balance. If the balance is enough, it subtracts the amount. Otherwise it prints `You have insufficient balance to withdraw the money!` and leaves the balance unchanged. The loop ends when the user enters `4`.

## Concepts used

- `do-while` loop for the repeating menu
- `switch-case` for option handling
- `if-else` for the withdrawal check
- `float` variables for money
- `scanf` / `printf` for input and output, with `%g` to print amounts cleanly

## Build and run

```bash
gcc atm.c -o atm
./atm
```

## Sample run

The menu is shown before every input and is left out below to keep it short.

```
1 (Check Balance)
The balance amount in your account is Rs.0/-

2 (Deposit Money)
Enter the amount to be deposited
Rs:1000
Your balance amount after deposit is Rs.1000/-

3 (Withdraw Money)
Enter the amount to be withdrawn:
Rs:400
The balance amount after withdraw is Rs.600/-

3 (Withdraw Money)
Enter the amount to be withdrawn:
Rs:2000
You have insufficient balance to withdraw the money!

4 (Exit)
Thankyou for using the ATM!
```

## Known limitations

- Negative deposit or withdrawal amounts are not rejected.
- Money is stored as `float`, which can introduce small rounding errors. Real systems use integers (for example paise) or fixed-point values.
- There is no PIN or login, and the balance is not saved when the program closes.
- Entering text instead of a number at a prompt can make the program loop.

## Possible improvements

- Validate amounts so they must be greater than zero
- Add a PIN check with limited attempts
- Save the balance to a file so it persists between runs
- Add a mini statement that lists recent transactions

## Author

**Madhav M**
[LinkedIn](https://linkedin.com/in/madhav-m-5953a0225) | [GitHub](https://github.com/Madhav-M-6385)
