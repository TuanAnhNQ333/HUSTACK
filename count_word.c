/*Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text
Input
The Text

Output
Write the number Q of words

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h> // for isspace

int countWords(char *s)
{
    int count = 0;
    int inWord = 0; // To track whether we are inside a word

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(!isspace(s[i])) // If the character is not a space
        {
            if(inWord == 0)
            {
                count++;  // Increment word count when we enter a new word
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;  // We are not in a word anymore
        }
    }
    return count;
}

int main()
{
   char s[4000];
   fgets(s, sizeof(s), stdin);
   int result = countWords(s);
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





