\#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char word[100]; // rotation cipher encode working
    char text;
    int key;
    int i;
    
    printf("Enter text: ");
    scanf("%s", word); // Tried to use 'get', got compiler warning saying it was dangerous so changed to scanf. No & symbol as it is a string
    printf("Enter key: ");
    scanf("%d", &key);
    
    for(i = 0; word[i] != '\0'; i++) // Set up to exit if word[i] is equal to the terminating null of the string
    {
        text = word[i];
        text = text + key;
        if(text >= 'Z')
        {
            text = text - 32;
        }
        word[i] = text;
    }
    printf("Encoded message is: %s", word);
    return 0;
}




char word[100]; // rotation cipher decode working
    char text;
    int key;
    int i;
    
    printf("Enter cipher text: ");
    scanf("%s", word);
    printf("Enter rotation key: ");
    scanf("%d", &key);
    
    for(i = 0; word[i] != '\0'; i++)
    {
        text = word[i];
        text = text - key;
        if(text >= 'Z')
        {
            text = text - 32;
        }
        word[i] = text;
    }
    printf("Decoded text is: %s", word);
    return 0;
}