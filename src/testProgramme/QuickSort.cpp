#include "QuickSort.h"

int PartitionII(int a[] , int low , int high)
{
    int index = low + rand()%(high-low+1);
    swap(a[index],a[low]);
    int pivot = a[low];
    int i = low;
    for(int j = i+1 ; j <= high ; j++)
    {
        if(a[j] < pivot)
        {
            ++i;                                        //i先进步
            swap(a[i], a[j]);                           //交换
        }
    }                                                   //x<=i的位置均看做是小于pivot的值
    swap(a[i], a[low]);

    return i;
}

void QuickSort(int A[],int head,int tail)
{				                                        //鍩虹
    if(head<tail){                                      //涓嶈兘灏忎簬绛変簬锛岀瓑浜庢椂娌℃湁鎰忎箟
    int pivotPT=PartitionII(A,head,tail);
    QuickSort(A,head,pivotPT-1);
    QuickSort(A,pivotPT+1,tail);
        }
}