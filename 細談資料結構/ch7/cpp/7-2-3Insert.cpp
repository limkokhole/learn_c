/*=========================================================

       7-2-3 插入排序法


          Insert_Sort()         插入排序法函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <iostream.h>

#define ARR_NUM 9
void Insert_Sort(int [], int);

void main(void) {
    int a[ARR_NUM] = {37, 41, 19, 81, 41, 25, 56, 61, 49}, i;
    cout << "排序前 ( before sorting )" << endl;

    for (i = 0; i < ARR_NUM; i++) {
        cout << " " << a[i];
    }

    Insert_Sort(a, ARR_NUM);
    cout << endl << "排序後 ( after sorting )" << endl;

    for (i = 0; i < ARR_NUM; i++) {
        cout << " " << a[i];
    }

    cout << endl;
}
void Insert_Sort(int a[], int n) {
    int i, j, up;

    for (i = 1; i < n; i++) {
        up = a[i];
        j = i;

        while (j > 0 && a[j - 1] > up) {
            a[j] = a[j - 1];
            j--;
        }

        a[j] = up;
    }
}
