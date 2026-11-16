# Door Lock Simulation in C

A small C program that simulates a keypad door lock. The user enters a numeric key, and the program allows a limited number of attempts, adds a lockout delay after repeated failures, and finally locks the door permanently if every round of attempts is used up.

## Features

- Unlocks the door when the correct key is entered
- Limited attempts with a live "attempts remaining" message
- Lockout delay after a round of wrong attempts
- Each new round gives fewer attempts than the last
- Permanent lock after the final round, with a message to contact service

## How it works

The correct key is stored in the program (`org_key = 123`). The user has 3 rounds of attempts, and each round is shorter than the one before it.

| Round | Attempts allowed | After all attempts fail |
|---|---|---|
| 1 | 3 | Door locks, delay, then next round |
| 2 | 2 | Door locks, delay, then next round |
| 3 | 1 | Door is locked permanently |

A correct key at any point prints `Door is Unlocked!` and ends the program. In total, a user gets 6 attempts before the permanent lock.

### Logic flow

```
Enter key
   |
   +-- correct? --> Door is Unlocked --> exit
   |
   +-- wrong --> show attempts remaining
                    |
                    +-- attempts left? --> ask for key again
                    |
                    +-- none left --> lockout delay
                                         |
                                         +-- rounds left? --> fewer attempts, ask again
                                         |
                                         +-- no rounds left --> locked permanently
```

## Concepts used

- Conditional statements and `for` loops
- `goto` for jumping between the input, retry and lockout stages
- `scanf` / `printf` for input and output
- `sleep()` from `unistd.h` for the lockout delay
- Counters (`j`, `chance`) to track attempts and rounds

## Requirements

- A C compiler such as GCC
- Linux or macOS (the program uses `unistd.h`; on Windows, use WSL or MinGW, or replace `sleep()` with `Sleep()` from `windows.h`)

## Build and run

```bash
gcc door_lock.c -o door_lock
./door_lock
```

## Sample run

Correct key on the second try:

```
Enter the lock key:111
Try again! 2 attempts remaining
Enter the lock key:123
Door is Unlocked!
```

Wrong keys until the first lockout:

```
Enter the lock key:1
Try again! 2 attempts remaining
Enter the lock key:2
Try again! 1 attempts remaining
Enter the lock key:3
Try again! 0 attempts remaining
You are out of attempts!
The door is locked.Try again after 1 minute!
You now have only 2 attempts to unlock!
Enter the lock key:
```

After the last round fails:

```
Your door has been locked permanently.Please contact the service.
```

## Known limitations

- The key is hardcoded and the lock state is not saved, so restarting the program resets everything.
- The lockout message says 1 minute, but the delay in the code is `sleep(3)` to keep testing quick. Change it to `sleep(60)` for a real one-minute lockout.
- Input is not validated, so entering non-numeric text can make the program loop.

## Possible improvements

- Replace `goto` with functions and loops for cleaner structure
- Validate input and read the key as a string
- Store the lock state so a permanent lock survives a restart
- Port to a microcontroller: keypad for input, a hardware timer for the lockout, and a relay or servo for the lock

## Author

**Madhav M**
[LinkedIn](https://linkedin.com/in/madhav-m-5953a0225) | [GitHub](https://github.com/Madhav-M-6385)
