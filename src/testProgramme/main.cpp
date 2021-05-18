#include "swap.h"
#include "QuickSort.h"


void print(int *a, int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[6] = {3, 10, 89, 38, 7, 40};
    QuickSort(a, 0, 5);
    print(a, 6);
    return 0;
}
