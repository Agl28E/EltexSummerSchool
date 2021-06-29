#include <stdio.h>

int main()
{
int a = 0x00DDAABB;
int b = 0xDDCCBBAA;
unsigned char c;

printf("a = %x\n", a);
c = ((a >> 16) & 0xFF);
printf("third byte of a = %x\n", c);

printf("b = %X\n",b);
b = b ^ (0x11 << 16);
printf("b = %X\n",b);
}
