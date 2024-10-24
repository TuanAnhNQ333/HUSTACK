/*FILE fgets fputs Bài 2
Bài tập 2. Viết chương trình nhận đối số dòng lệnh là đường dẫn đến một file văn bản (nội dung dưới 80 dòng). 
Chương trình thêm một dòng mới vào cuối file nói trên với nội dung chứa các ký tự đầu tiên của các dòng trong file ban đầu.

 */

#include <stdio.h>
#include <stdlib.h>
 
void addline(const char *filePath) {
    FILE *file = fopen(filePath, "r+");
    if (file == NULL) {
        perror("Cannot open");
        return;
    }
 
    char fchar[256] = {0}; 
    char line[256];
    int index = 0;
 
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] != '\n') { 
            fchar[index++] = line[0];
        }
    }
    fchar[index] = '\0';
 
    fseek(file, 0, SEEK_END);
    fprintf(file, "\n%s", fchar);
 
    fclose(file);
}
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s <file_path>\n", argv[0]);
        return 1;
    }
 
    addline(argv[1]);
    return 0;
}