/*
輸出 unsigned 型態的邏輯積、邏輯和、排他性邏輯和、1的補數
*/

#include  <stdio.h>

/*---傳回整數x中的位元---*/
int count_bits(unsigned x) {
    int  count = 0;

    while (x) {
        if (x & 1U) {
            count++;
        }

        x >>= 1;
    }

    return (count);
}

/*---傳回unsigned型態的位元數---*/
int int_bits(void) {
    return (count_bits(~0U));
}

/*---輸出unsigned型態的位元內容---*/
void print_bits(unsigned x) {
    int     i;

    for (i = int_bits() - 1; i >= 0; i--) {
        putchar(((x >> i) & 1U) ? '1' : '0');
    }
}

int main(void) {
    unsigned  na, nb;

    puts("請輸入兩個非負數的整數。");
    printf("整數A：");
    scanf("%u", &na);
    printf("整數B：");
    scanf("%u", &nb);

    printf("\nA   = ");
    print_bits(na);
    printf("\nB   = ");
    print_bits(nb);
    printf("\nA&B = ");
    print_bits(na & nb);     /* 邏輯積 */
    printf("\nA|B = ");
    print_bits(na | nb);     /* 邏輯和 */
    printf("\nA^B = ");
    print_bits(na ^ nb);     /* 排他性邏輯和 */
    printf("\n~A  = ");
    print_bits(~na);         /* 1 的補數 */
    printf("\n~B�@= ");
    print_bits(~nb);         /* 1 的補數 */
    putchar('\n');

    return (0);
}
