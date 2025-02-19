#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is numeric (valid key)
bool is_numeric(string s);

int main(int argc, string argv[])
{
    // Ensure exactly one command-line argument is provided
    if (argc != 2 || !is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Encrypt plaintext using the Caesar cipher
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            // Preserve case
            char offset = isupper(c) ? 'A' : 'a';
            printf("%c", (c - offset + key) % 26 + offset);
        }
        else
        {
            printf("%c", c); // Non-alphabetic characters remain unchanged
        }
    }

    printf("\n");
    return 0;
}

// Function to check if a string consists of only digits
bool is_numeric(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
