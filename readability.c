#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int letters(string text);
int words(string text);
int sentence(string text);
int compute_index(int letters_count, int sentence_count, int words_count);

char c;

int main(void)
{
    string text = get_string("Name: ");
    int letters_count = letters(text);

    int sentence_count = sentence(text);

    int words_count = words(text);
    
    int grade = compute_index(letters_count,  sentence_count,  words_count);

    if(grade<1)
    {
        printf("Before Grade 1");
    }

    else if(grade>=16)
    {
        printf("Grade 16+");
    }

    else
    {
        printf("Grade: %i\n",grade);
    }
    printf("\n");

}

int letters(string text)
{
    int sum =0;

    for(int i = 0; i<strlen(text); i++)
    {
        c = text[i];
        if(isalpha(c))
        {
            sum++;
        }
    }
    return sum;
}

int words(string text)
{
    int words = 1;
    for(int i = 0; i<strlen(text); i++)
    {

        c = text[i];
        if(isspace(c))
        {
            words++;
        }
    }
    return words;
}

int sentence(string text)
{
    int sentence = 0;
    for(int i = 0; i<strlen(text); i++)
    {
        c = text[i];
        if(c=='!'|| c=='.' || c=='?')
        {
            sentence++;
        }
    }
    return sentence;
}

int compute_index(int letters_count, int sentence_count, int words_count)
{
     float L = ((float)letters_count/words_count)*100;
     float S = ((float)sentence_count/words_count)*100;
     float index = ((float)0.0588 * L - 0.296 * S - 15.8);
     return round(index);
}
