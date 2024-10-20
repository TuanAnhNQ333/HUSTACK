/*Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text
Input
The Text

Output
Write the number Q of words

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h> // dùng cho hàm isspace()

// Hàm đếm số từ trong chuỗi
int countWords(char *s)
{
    int wordCount = 0;  // Biến đếm số từ
    int inWord = 0;     // Biến kiểm tra trạng thái: đang ở trong từ hay không

    // Duyệt qua từng ký tự trong chuỗi
    for(int i = 0; s[i] != '\0'; i++)
    {
        // Kiểm tra nếu ký tự hiện tại không phải là khoảng trắng (space, tab, newline)
        if(!isspace(s[i])) 
        {
            // Nếu trước đó không phải trong từ, thì bây giờ bắt đầu một từ mới
            if(inWord == 0)
            {
                wordCount++;  // Tăng số từ lên
                inWord = 1;   // Đánh dấu đang ở trong một từ
            }
        }
        else
        {
            inWord = 0;  // Khi gặp khoảng trắng, kết thúc từ
        }
    }
    return wordCount;  // Trả về tổng số từ đếm được
}

int main()
{
    char text[5000];  // Chuỗi lớn chứa nhiều dòng văn bản
    char line[1000];  // Biến tạm chứa từng dòng nhập

    // Khởi tạo chuỗi văn bản rỗng
    text[0] = '\0';

    // Đọc nhiều dòng văn bản từ người dùng
    while(1)
    {
        fgets(line, sizeof(line), stdin);  // Đọc một dòng nhập từ người dùng
        
        // Nếu dòng vừa nhập chỉ là dấu xuống dòng (người dùng nhấn Enter mà không nhập gì)
        if(strcmp(line, "\n") == 0)  
        {
            break;  // Thoát khỏi vòng lặp, kết thúc nhập
        }
        
        strcat(text, line);  // Nối dòng vừa nhập vào chuỗi văn bản
    }

    // Gọi hàm đếm từ và in ra kết quả
    int result = countWords(text);
    printf("%d\n", result);

    return 0;
}


/*
Example
Input
Hanoi University Of Science and Technology
School of Information and Communication Technology


Output
12
*/





