#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
typedef struct {
    int stt;
    char id[20];
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    float score;
} Student;
void readFromFile(const char *fn, Student s[], int *cnt) {
    FILE *file = fopen(fn, "r");
    if (file == NULL) {
        printf("Cannot open file %s.\n", fn);
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (fscanf(file, "%d %s %s %s", &s[i].stt, s[i].id, s[i].name, s[i].phone) != EOF) {
        i++;
    }
    *cnt = i;
    fclose(file);
}
void inputScores(Student s[], int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("Nhap diem cho sinh vien %s (%s): ", s[i].name, s[i].id);
        scanf("%f", &s[i].score);
    }
}
void writeToFile(const char *fn, Student s[], int cnt) {
    FILE *file = fopen(fn, "w");
    if (file == NULL) {
        printf("Cannot open file %s.\n", fn);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < cnt; i++) {
        fprintf(file, "%d %s %s %s %.2f\n", s[i].stt, s[i].id, s[i].name, s[i].phone, s[i].score);
    }
 
    fclose(file);
}
void printStudents(Student s[], int cnt) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < cnt; i++) {
        printf("%d %s %s %s %.2f\n", s[i].stt, s[i].id, s[i].name, s[i].phone, s[i].score);
    }
}
int main() {
    Student s[MAX_STUDENTS];
    int cnt = 0;
    readFromFile("students.txt", s, &cnt);
    inputScores(s, cnt);
    writeToFile("bangdiem.txt", s, cnt);
    printStudents(s, cnt);
    return 0;
}