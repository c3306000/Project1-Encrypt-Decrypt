#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char word[100];
    int key;
    int i = 0;
    printf("Enter text: \n");
    scanf("%c", )
    printf("Enter a key between 0 and 26: /n");
    scanf("%d", &key);
    
    for(i = 0; i < strlen(word); i++)
    {
        if(word[i] >= 'Z')
        {
            word[i] = word[i] - 32;
        }
    }
    
    printf("String in upper case is %s\n", word);
    for(i = 0; word[i] != '\0'; i++)
    {
        word[i] = word[i] + key;
    }
    for(i = 0; i < strlen; i++)
    {
        word[i] = word[i] -26;
    }
    
    printf("Encoded message is: %s", word);
    return 0;
}