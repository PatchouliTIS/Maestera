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
            ++i;                                        //i�Ƚ���
            swap(a[i], a[j]);                           //����
        }
    }                                                   //x<=i��λ�þ�������С��pivot��ֵ
    swap(a[i], a[low]);

    return i;
}

void QuickSort(int A[],int head,int tail)
{				                                        //基础
    if(head<tail){                                      //不能小于等于，等于时没有意义
    int pivotPT=PartitionII(A,head,tail);
    QuickSort(A,head,pivotPT-1);
    QuickSort(A,pivotPT+1,tail);
        }
}