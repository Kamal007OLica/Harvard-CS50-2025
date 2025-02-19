#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

string convert_upper(string word);
int compute_score(string upper_word);
void print_winner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Convert to uppercase
    string upper_word1 = convert_upper(word1);
    string upper_word2 = convert_upper(word2);

    // Calculate scores
    int score1 = compute_score(upper_word1);
    int score2 = compute_score(upper_word2);

    // TODO: Print the winner
    print_winner(score1, score2);
}

string convert_upper(string word)
{
    // Convert to uppercase
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
    }
    printf("%s\n", word);
    return word;
}

int compute_score(string upper_word)
{
    // Add score for each letter
    int score = 0;
    for (int i = 0; i < strlen(upper_word); i++)
    {
        score = score + POINTS[upper_word[i]-65];
    }
    return score;
}

void print_winner(int score1, int score2)
{
    // Print result based on the scores
    if (score1 > score2)
    {
        printf("Player 1 wins \n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins \n");
    }
    else
    {
        printf("Tie! \n");
    }
}
