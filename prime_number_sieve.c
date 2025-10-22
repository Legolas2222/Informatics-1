#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int bit_number = 100;
    int buffer_length = (int)ceil(bit_number / 8.0f);
    printf("Bytes: %d\n", buffer_length);
    unsigned char *buffer = malloc(buffer_length);

    memset(buffer, 0xFF, buffer_length);
    // printf("%d\n", buffer);
    buffer[0] = 0b11111110;
    // printf("%d", buffer[0]);
    
    // Sieving the prime numbers
    for (int i = 2; i < bit_number; i++)
    {
        
        if (((buffer[i / 8] >> (i % 8)) & 1) == 0)
        {
            // printf("%d\n", i);
            continue;
        }
        
        for (int j = i*i; j < bit_number; j += i)
        {
            buffer[j / 8] &= ~(1 << (j % 8 ));
        //printf("%d\n", j);
        }
    }
    // printf("%d", buffer[0]);



    
    // Output
    for (int i = 2; i < bit_number; i++)
    {
        int byte_index = i / 8;
        int bit_index = i % 8;
        int bit = buffer[byte_index] & ( 1 << (i % 8));
        //  printf("%d", bit);
        //  printf("\n");
        if (bit != 0)
        {
            printf("%d, ", i);
        }
    }

    free(buffer);

    return 0;
}
