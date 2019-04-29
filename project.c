#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added just in case
char *rotatione(); // list of functions to be called
char *rotationd();
char *substitutione();
char *substitutiond();

int main()
{
    //add a 'menu' so users can choose what function they want to test
   int choice;
   printf("Enter 1 for rotation cipher encryption\n");
   printf("Enter 2 for rotation cipher decryption\n");
   printf("Enter 3 for substitution cipher encryption\n");
   printf("Enter 4 for substitution cipher decryption\n");
   printf("Enter 5 for rotation cipher decryption without key\n");
   printf("Enter 6 for substitution cipher decryption without key\n");
   printf("Enter your choice: ");
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
       printf("Enter an appropriate number: ");
   }
   return 0;
}   

char *rotatione()
{
    char word[100]; // array of 100 as only one word is being encoded 
    char text;
    int key;
    int i;
    
    printf("Enter text: ");
    scanf("%s", &word); // Tried to use 'get', got compiler warning saying it was dangerous so changed to scanf. No & symbol as it is a string
    printf("Enter key: ");
    scanf("%d", &key);
    
    for(i = 0; word[i] != '\0'; i++) // Set up to exit if word[i] is equal to the terminating null of the string
    {
        text = word[i];
        if(text >= 'a' && text <= 'z')
        {
            text = text - 32; // ensures lower case letters are changed to upper case
        }
        if(text >= 'A' && text <= 'Z')
        {
            text = text + key; // after everything is upper case the rotation is implemented
            if(text > 'Z')
            {
                text = text - 26; // if the rotation goes past 'Z', this if statement rotates it back to 'A'
            }
        }
        word[i] = text;
    }
    printf("Encoded message is: %s", word);
    return word;
}

char *rotationd()
{
    char word[100]; // Array size of 100 as only one word is being tested
    char text;
    int key;
    int i;
    
    printf("Enter cipher text: ");
    scanf("%s", &word);
    printf("Enter rotation key: ");
    scanf("%d", &key);
    
    for(i = 0; word[i] != '\0'; i++) // Ensures loop exits if word[i] is equal to the terminating null of the string
    {
        text = word[i];
        if(text >= 'a' && text <= 'z')
        {
            text = text - 32; //ensures lower case letters are changed to upper case
        }
        if(text >= 'A' && text <= 'Z')
        {
            text = text - key; // once everything is upper case, rotation happens back towards the start of the alphabet to decode
            if(text < 'A')
            {
                text = text + 26; // if rotation goes past 'A', rotates back to 'Z'
            }
        }
        word[i] = text;
    }
    printf("Decoded text is: %s", word);
    return word;
}

char *substitutione()
{
    // initialise one array to be upper case alphabet and an empty array to store the letter substitutions
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char store[26];
    static char text[100];
    char STORE;
    char TEXT;
    int i;
    int j;
    int k;
    
    printf("Enter message to encode: ");
    scanf("%s", &text);
    printf("Enter letter substitutions: ");
    scanf("%s", &store);
    
    for(k = 0; store[i] != '\0'; i++)
    {
        STORE = store[i];
        if(STORE >= 'a' && STORE <= 'z')
        {
            STORE = STORE - 32; // ensures lower case letters are changed to upper case
        }
        store[i] = STORE;
    }
    
    for(i = 0; text[i] != '\0'; i++)
    {
        TEXT = text[i];
        if(TEXT >= 'a' && TEXT <= 'z')
        {
            TEXT = TEXT - 32; // ensures everything is upper case
        }
        text[i] = TEXT;
    }
    
    for(i = 0; i < sizeof(text)/sizeof(text[0]); i++)
    {
        for(j = 0; j < sizeof(alphabet)/sizeof(alphabet[0]); j++)
        {
            if(text[i] == alphabet[j])
            {
                text[i] = store[j];
                break;
            }
        }
    }
    return text;
}

char *substitutiond()
{
    char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char store[26];
    static char text[100];
    char STORE;
    char TEXT;
    int i;
    int j;
    int k;
    
    printf("Enter text to decode: ");
    scanf("%s", &text);
    printf("Enter letter substitutions: ");
    scanf("%s", &store);
    
    for(k = 0; store[i] != '\0'; i++)
    {
        STORE = store[i];
        if(STORE >= 'a' && STORE <= 'z')
        {
            STORE = STORE - 32; // ensures lower case letters are changed to upper case
        }
        store[i] = STORE;
    }
    
    for(i = 0; text[i] != '\0'; i++)
    {
        TEXT = text[i];
        if(TEXT >= 'a' && TEXT <= 'z')
        {
            TEXT = TEXT - 32;
        }
        text[i] = TEXT;
    }
    
    for(i = 0; i < sizeof(text) / sizeof(text[0]); i++)
    {
        for(j = 0; j < sizeof(alphabet) / sizeof(alphabet[0]); j++)
        {
            if(text[i] == store[j])
            {
                text[i] = alphabet[j];
                break;
            }
        }
    }
    return text;
}






