/*FILE fgets fputs Bài 1
Bài tập 1. Viết chương trình mycat đọc và hiển thị nội dung một tập tin văn bản trên màn hình. Chương trình hỗ trợ hai cú pháp sử dụng như sau:

cat <filename> : Hiển thị một lần toàn bộ nội dung

cat <filename> -p : Hiển thị theo từng trang. Người dùng chạm một phím để xem trang tiếp theo.

 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
enum { SUCCESS, FAIL };
#define MAX_LEN 81
 
void LineReadWrite(FILE *fin,int mode){
    char buff[MAX_LEN];
    int count=0;
    while(fgets(buff,MAX_LEN,fin) != NULL){
        printf("%s", buff);
        count++;
        if(count >= 25 && mode == 1) return;
    }
}
 
int main(int argc, char *argv[]){
   FILE *f;
 
    int reval = SUCCESS;
    if(argc == 2){
        if ((f = fopen(argv[1], "r")) == NULL) {
            printf("Cannot open %s.\n", argv[1]);
            reval = FAIL;
        }
        else{
            LineReadWrite(f,0);
            fclose(f);
        }
        return reval;
    }
    if(argc == 3 && strcmp("-p",argv[2]) == 0){
        if ((f = fopen(argv[1], "r")) == NULL) {
            printf("Cannot open %s.\n", argv[1]);
            reval = FAIL;
        }
        else{
            char c;
            do
            {
                LineReadWrite(f,1);
                if(feof(f)) return 0;
            } while ((c=getc(stdin)) != 'q');
           
            fclose(f);
        }
        return reval;
    }
}