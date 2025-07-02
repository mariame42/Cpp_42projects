Key Steps to Solve ex02:
1. Understand the Task
You need to recreate the missing Account.cpp file
The output must match the log file exactly (except timestamps)
You have: Account.hpp (header), tests.cpp (test program), and the log file
2. Analyze the Header File
Look at Account.hpp to understand:
Static members that track global bank statistics
Instance members for each account
Public methods you need to implement
Private methods like _displayTimestamp()
3. Study the Log File Pattern
The log shows specific output formats:
[timestamp] index:X;amount:Y;created (constructor)
[timestamp] accounts:X;total:Y;deposits:Z;withdrawals:W (global info)
[timestamp] index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N (deposits)
[timestamp] index:X;p_amount:Y;withdrawal:Z;amount:W;nb_withdrawals:N (withdrawals)
[timestamp] index:X;amount:Y;closed (destructor)
4. Key Implementation Points
Static variables need to be defined in Account.cpp
Timestamp format must match the log pattern
Withdrawal logic - some withdrawals are "refused" (insufficient funds)
Global tracking - all operations update static counters
5. Critical Understanding
The log shows exact sequence of operations
Static members track totals across all accounts
Each operation logs its details
Withdrawal refusal happens when amount > current balance
The main challenge is implementing the logging system to match the exact output format shown in the log file.
