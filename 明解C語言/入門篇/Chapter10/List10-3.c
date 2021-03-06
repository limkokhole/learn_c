/*
間接的利用指標操作身高
*/

#include  <stdio.h>

int main(void) {
    int    soong   = 178;            /* 宋小瑜的身高 */
    int    chang   = 175;            /* 張小雄的身高 */
    int    chen    = 165;            /* 陳小扁的身高 */
    int    lin     = 179;            /* 林小雄的身高 */

    int* may, *lily;

    may   = &soong;  /* may指到soong（喜歡宋小瑜） */
    lily  = &lin;        /* lily指到lin(喜歡林小雄） */

    printf("may喜歡的人的身高：%d\n", *may);
    printf("lily喜歡的人的身高：%d\n", *lily);

    may = &chang;       /* may指到chang（改變心意）��*/

    *lily = 180;        /*將180指定到lily所指的物件*/
    /*改寫lily喜歡的人的身高 */

    putchar('\n');
    printf("宋小瑜的身高：%d\n", soong);
    printf("張小雄的身高：%d\n", chang);
    printf("陳小扁的身高：%d\n", chen);
    printf("林小雄的身高：%d\n", lin);
    printf("may喜歡的人的身高：%d\n", *may);
    printf("lily喜歡的人的身高：%d\n", *lily);

    return (0);
}
