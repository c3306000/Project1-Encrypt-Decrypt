#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added just in case
char *rotatione();
char *rotationd();
char *substitutione();
char *substitutiond();
char *rotationd2();
char substitutiond2();

int main()
{
   int choice;
   printf("Enter 1 for rotation cipher encryption\n");
   printf("Enter 2 for rotation cipher decryption\n");
   printf("Enter 3 for substitution cipher encryption\n");
   printf("Enter 4 for substitution cipher decryption\n");
   printf("Enter 5 for rotation cipher decryption without key\n");
   printf("Enter 6 for substitution cipher decryption without key\n");
   printf("Enter your choice: ")
   scanf("%d", &choice);
   if(choice == 1){
       printf("Encrypted message is: %s", rotatione());
   }else if(choice == 2){
       printf("Decrypted message is: %s", rotationd());
   }else if(choice == 3){
       printf("Encrypted message is: %s", substitutione());
   }else if(choice == 4){
       printf("Decrypted message is: %s", substitutiond());
   }else if(choice == 5){
       printf("Decrypted message is: %s", rotationd2());
   }else if(choice == 6){
       printf("Decrypted message is: %s", substitutiond2());
   }else{
       printf("Enter an appropriate number: ")
   }
   return 0;
}   

char *rotatione()
{
    char word[1000]; // rotation cipher encode working
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
        if(text >= 'a' && text <= 'z')
        {
            text = text - 32;
        }
        if(text >= 'A' && text <= 'Z')
        {
            text = text + key;
            if(text > 'Z')
            {
                text = text - 26;
            }
        }
    }
    printf("Encoded message is: %s", word);
    return word;
}

char *rotationd()
{
    char word[1000]; // rotation cipher decode working
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
        if(text >= 'a' && text <= 'z')
        {
            text = text - 32;
        }
        if(text >= 'A' && text <= 'Z')
        {
            text = text - key;
            if(text < 'A')
            {
                text = text + 26;
            }
        }
        word[i] = text;
    }
    printf("Decoded text is: %s", word);
    return word;
}

char *substitutione()
{
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char subinput[26];
    char store;
    char message;
    static char text[1000];
    int i;
    int b;
    int c;
    
    printf("Enter message to encode: ");
    scanf("%s", text);
    printf("Enter letter substitutions: ");
    scanf("%s", subinput);
    
    for(c = 0; subinput[i] != '\0'; a++)
    {
        store = subinput[i];
        if(store >= 'a' && store <= 'z')
        {
            store = store - 32;
        }
        subinput[i] = store;
    }
    
    printf("Character substitutions are:\n");
    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("||||||||||||||||||||||||||\n");
    printf("%s", subinput);
    
    for(i = 0; text[i] != '\0'; i++)
    {
        message = text[i];
        if(message >= 'a' && message <= 'z')
        {
            message = message - 32;
        }
        text[i] = message;
    }
    
    for(i = 0; i < sizeof(text) / sizeof(text[0]); i++)
    {
        for(b = 0; b < sizeof(alphabet) / sizeof(alpabet[0]); b++)
        {
            if(text[i] == alphabet[b])
            {
                text[i] = subinput[b];
                break;
            }
        }
    }
    return text
}

char *substitutiond()
{
    
}






