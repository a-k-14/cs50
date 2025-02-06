#include <cs50.h>
#include <stdio.h>

int get_score(string s);
int get_point(char c);

int main(void)
{
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    int score1 = get_score(player1);
    int score2 = get_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("invalid!\n");
    }
}

int get_score(string s)
{
    int i = 0;
    int score = 0;
    while (s[i] != '\0')
    {
        // we check if the letter is lowercase and convert it to uppercase
        // then we get the point for the letter
        if (s[i] >= 97 & s[i] <= 122)
        {
            score += get_point(s[i] - 32);
        }
        else
        {
            score += get_point(s[i]);
        }
        i++;
    }

    return score;
}

int get_point(char c)
{
    int point = 0;

    switch (c)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
        return point = 1;
        break;

    case 'D':
    case 'G':
        return point = 2;
        break;

    case 'B':
    case 'C':
    case 'M':
    case 'P':
        return point = 3;
        break;

    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
        return point = 4;
        break;

    case 'K':
        return point = 5;
        break;

    case 'J':
    case 'X':
        return point = 8;
        break;

    case 'Q':
    case 'Z':
        return point = 10;
        break;
    }

    return point;
}
