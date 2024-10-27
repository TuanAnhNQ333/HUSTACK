// dung hash table 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21
#define MAX_TRANSACTIONS 1000
#define HASH_SIZE 10007 // Kích thước hash table để giảm va chạm

typedef struct Transaction {
    char from_account[MAX_LENGTH];
    char to_account[MAX_LENGTH];
    int amount;
    char time_point[MAX_LENGTH];
    char ATM[MAX_LENGTH];
} Transaction;

// Cấu trúc để lưu thông tin tổng tiền giao dịch theo tài khoản trong hash table
typedef struct HashEntry {
    char account[MAX_LENGTH];
    int total_amount;
    struct HashEntry* next;
} HashEntry;

HashEntry* hash_table[HASH_SIZE];

// Hàm băm tài khoản để gán vào hash table
unsigned int hash(const char* account) {
    unsigned int hash = 0;
    for (int i = 0; account[i] != '\0'; i++) {
        hash = (hash * 31 + account[i]) % HASH_SIZE;
    }
    return hash;
}

// Hàm cập nhật tổng tiền vào hash table
void update_hash_table(const char* account, int amount) {
    unsigned int idx = hash(account);
    HashEntry* entry = hash_table[idx];
    while (entry != NULL) {
        if (strcmp(entry->account, account) == 0) {
            entry->total_amount += amount;
            return;
        }
        entry = entry->next;
    }
    // Nếu không tìm thấy entry phù hợp, tạo mới
    entry = (HashEntry*)malloc(sizeof(HashEntry));
    strcpy(entry->account, account);
    entry->total_amount = amount;
    entry->next = hash_table[idx];
    hash_table[idx] = entry;
}

// Hàm tìm tổng tiền giao dịch từ một tài khoản
int total_money_transaction_from(const char* account) {
    unsigned int idx = hash(account);
    HashEntry* entry = hash_table[idx];
    while (entry != NULL) {
        if (strcmp(entry->account, account) == 0) {
            return entry->total_amount;
        }
        entry = entry->next;
    }
    return 0;
}

// Đọc giao dịch và cập nhật tổng tiền
int read_transactions() {
    int count = 0;
    while (1) {
        Transaction t;
        if (scanf("%s", t.from_account) != 1 || strcmp(t.from_account, "#") == 0) {
            break;
        }
        scanf("%s %d %s %s", t.to_account, &t.amount, t.time_point, t.ATM);
        update_hash_table(t.from_account, t.amount);
        count++;
    }
    return count;
}

int main() {
    int num_transaction = read_transactions();
    while (1) {
        char query[50];
        char account[MAX_LENGTH];
        if (scanf("%s", query) != 1 || strcmp(query, "#") == 0) {
            break;
        }
        if (strncmp(query, "?total_money_transaction_from ", 29) == 0) {
            scanf("%s", account);
            int result = total_money_transaction_from(account);
            printf("%d\n", result);
        }
    }
    return 0;
}
