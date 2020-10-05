#include <stdio.h>
#include <string.h>
#define BUF_SIZE 33
char *int2bin(unsigned int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);

    for (int i = 31; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';

        a >>= 1;
    }

    return buffer;
}
int swapBits(unsigned int n, unsigned int p1, unsigned int p2) 
{ 
    char buffer[BUF_SIZE+1]={'\0'};
    //memset(buffer,'0',BUF_SIZE);
    int2bin(n, buffer, BUF_SIZE - 1);

    printf("n = %s\n", buffer);
    /* Move p1'th to rightmost side */
    unsigned int bit1 =  (n >> p1) & 1; 
    memset(buffer,'0',BUF_SIZE);
    int2bin(bit1, buffer, BUF_SIZE);
    printf("bit1 = %s\n", buffer);
    /* Move p2'th to rightmost side */
    unsigned int bit2 =  (n >> p2) & 1; 
    memset(buffer,'0',BUF_SIZE);
    int2bin(bit2, buffer, BUF_SIZE);
    printf("bit2 = %s\n", buffer);
    /* XOR the two bits */
    unsigned int x = (bit1 ^ bit2); 
    memset(buffer,'0',BUF_SIZE);
    int2bin(x, buffer, BUF_SIZE);
    printf("x = %s\n", buffer);
    /* Put the xor bit back to their original positions */
    x = (x << p1) | (x << p2); 
    int2bin(x, buffer, BUF_SIZE);
    printf("an = %s\n", buffer);
    /* XOR 'x' with the original number so that the 
       two sets are swapped */
    unsigned int result = n ^ x; 
    int2bin(result, buffer, BUF_SIZE);
    printf("result = %s\n", buffer);
    return result;
} 
int main() 
{ 
    int res =  swapBits(28, 0, 2); 

    printf("Result = %d ", res); 
    return 0; 
} 