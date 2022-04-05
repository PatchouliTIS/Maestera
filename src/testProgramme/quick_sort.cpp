#include<iostream>

using namespace std;


void merge_sort(int*, int, int);
void merge(int*, int, int);

int main()
{
    int num = 0;
    scanf("%d", &num);
    int *arr = new int[num];
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, num - 1);

    for(int i = 0 ; i < num ; ++i)
    {
        printf("%d ", arr[i]);
    }
    system("pause");
    return 0;
}

void merge_sort(int a[], int left, int right)
{
    if(left<right)
    {
        int mid = left+right+1>>1;
        merge_sort(a,left,mid-1);
        merge_sort(a,mid,right);
        merge(a,left,right);
    }
};

void merge(int a[],int b[], int left, int right)
{
    if(left>=right) return;
    int fnt = left , mid = left+right+1>>1 , rear = mid;

    int wr = left;
    int cnt = -left+right+1;
    int *b = new int[cnt];
    for(int i = left ; i <= right ; ++i)
    {
        b[i] = a[i];
    }
    

    while(fnt<mid&&rear<=right)
    {
        while(fnt<mid&&rear<=right&&b[fnt]<=b[rear]) a[wr++] = b[fnt++];
        while(fnt<mid&&rear<=right&&b[fnt]>b[rear]) a[wr++] = b[rear++];
    }

    while(fnt<mid) a[wr++] = b[fnt++];
    while(rear<=right) a[wr++] = b[rear++];

    delete[] b;
};
