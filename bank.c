#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TRANSACTIONS 1000
#define MAX_LENGTH 21
typedef struct 
{
    char from_account[MAX_LENGTH];
    char to_account[MAX_LENGTH];
    int amount;
    char time_point[MAX_LENGTH];
    char ATM[MAX_LENGTH];
} Transaction;

int read_transactions(Transaction transaction[])
{
    int count = 0;
    while(1)
    {
        Transaction t;
        if(scanf("%s", t.from_account) != 1 || strcmp(t.from_account, "#") == 0)
        {
            break;
        }
        scanf("%s %d %s %s", t.to_account, &t.amount, t.time_point, t.ATM);
        transaction[count++] = t;
    }
    return count;
}
int total_money_transaction_from(Transaction transaction[], int num_transaction, const char *account)
{
    int total = 0;
    for(int i = 0; i < num_transaction; i ++)
    {
        if(strcmp(transaction[i].from_account, account) == 0)
        {
            total += transaction[i].amount;
        }
    }
    return total;
}
int main()
{
    Transaction transaction[MAX_TRANSACTIONS];
    int num_transaction = read_transactions(transaction);
    while(1)
    {
        char query[50];
        char account[MAX_LENGTH];
        if(scanf("%s", query) != 1 || strcmp(query, "#") == 0)
        {
            break;
        }
        if(strncmp(query, "?total_money_transaction_from ", 29) == 0)
        {
            scanf("%s", account);
            int result = total_money_transaction_from(transaction, num_transaction, account);
            printf("%d\n", result);
        }

    }
    return 0;

}
/*
Example
Input
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?total_money_transaction_from T000010010
?total_money_transaction_from T000010030
#
Output
4500
4000

*/