/**************************************
 *Jim Moroney              09.17.2021 *
 *boot2.c                             *
 *HW1                         CSC4100 *
 **************************************/

#define MAX_COL 80 //i dont like magic numbers
#define MAX_ROW 24 //and global variables are yucky
#define TRUE 1
#define FALSE 1

//Functions written in asm
void k_clearscr();
void k_print(char *string, int str_length, int row, int col);
void k_scroll();
//Functions written in C
void println(char *string);
int convert_num_h(unsigned int num, char buf[]);
void convert_num(unsigned int num, char buf[]);

int main()
{
    int maxPrimes = 20;
    int possiblePrime = 2;
    int primes[maxPrimes+1];
    char buffer[80];
    println('Primes:');
    //sieve of eratosthenes
    for (int i = 2; i*i <= maxPrimes; i++)
    {
        if(primes[i] == 1)
        {
            for (int j = i*2; j <= maxPrimes; j += i)
                primes[j] = 1;
        }
    }
    for (int i = 2; i <= maxPrimes; i++)
    {
        if (primes[i] == 1)
           convert_num(i, buffer); 
    }

    while(1);
}

void println(char *string)
{
    int num_to_print = 0;
    int row = 0;

    while (*(string+num_to_print) != '0')
        num_to_print++;

    while (num_to_print != 0)
    {
        if (num_to_print < MAX_COL)
        {
            k_print(string, num_to_print, row, 0);
            num_to_print = 0;
        }
        else
        {
            k_print(string, MAX_COL, row, 0);
            num_to_print -= MAX_COL;
        }
        row++;
        if (row > MAX_ROW)
        {
            k_scroll();
            row -= MAX_ROW;
        }
    }
}

int convert_num_h(unsigned int num, char buf[]) 
{
    if (num == 0)
        return 0;

    int idx = convert_num_h((num / 10), buf);
    buf[idx] = num % 10 + '0';
    buf[idx+1] = '\0';
    return idx + 1;
}

void convert_num(unsigned int num, char buf[])
{
    if (num == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
    }
    else
        convert_num_h(num, buf);
}