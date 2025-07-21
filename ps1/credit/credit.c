// #include <cs50.h>
#include <stdio.h>

/*
test card number
378282246310005 as AMEX -- this works on cs50 vscode, here it throws INVALID!
371449635398431 as AMEX
5555555555554444 as MASTERCARD
5105105105105100 as MASTERCARD
4e12888888881881 as VISA
4222222222222 as VISA
1234567890 as INVALID (invalid length, checksum, identifying digits)
369421438439814 as INVALID (invalid identifying digits)
4%29e184e as INVALID (invalid length)
5673598276138ee3 as INVALID (invalid identifying digits)
4222222222223 as INVALID (invalid checksum)
34eeeeeeeeeee620 as INVALID (AMEX identifying digits, VISA/Mastercard length)
43eeeeeeeeeeeee as INVALID (VISA identifying digits, AMEX length)
*/

// identify the card issuer based on 1st 2 digits of amex & master, and 1st digit for visa
char *identify_card(long card_num)
{
    long n = card_num;
    // to count number of digits in the card_num
    // we start with 2 we run while loop till n is 2 digits
    int digits_count = 2;

    // get the 1st 2 digits of the card
    while (n >= 100)
    {
        n = n / 10;
        digits_count++;
    }

    if ((n == 34 || n == 37) && digits_count == 15)
    {
        return "AMEX";
    }
    else if ((n >= 51 && n <= 55) && digits_count == 16)
    {
        return "MASTERCARD";
    }

    // check if the issuer is visa based on 1st digit

    // this is not required for actual credit card checks
    // but for testing, if we give just 4, we get INVALID
    n = n > 10 ? n / 10 : n;
    if (n == 4 && (digits_count == 13 || digits_count == 16))
    {
        return "VISA";
    }

    return "INVALID";
}

// check the checksum of card_num to determine validity
int is_valid(long card_num)
{
    long n = card_num;
    // keep track of the position in the card_num
    int index = 1;

    int sum = 0;

    while (n > 0)
    {
        if (index % 2 == 0)
        {
            // multiply the digit with 2
            int result = (n % 10) * 2;

            // if result is > 9, we have to sum the individual digits and not result itself
            // as digits could be 0-9 and result of multiplication with 2 always yields upto 18, i.e. 2 digits
            if (result <= 9)
            {
                sum += result;
            }
            else
            {
                int digit1 = result % 10;
                int digit2 = result / 10;

                sum = sum + digit1 + digit2;
            }
        }
        else
        {
            sum += n % 10;
        }

        index++;
        n = n / 10;
    }

    // true if % 10 is 0, else false
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    // long card_num = get_long("Number: ");
    long long card_num = 371449635398431;

    if (is_valid(card_num) == 1)
    {
        char *issuer = identify_card(card_num);
        printf("%s\n", issuer);
    }
    else
    {
        printf("INVALID\n");
    }
}
