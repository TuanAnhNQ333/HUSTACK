#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// ham quy hoach cho quick sort
int partition (int *arr, int low, int high)
{
    int pivot = arr[high]; // chon phan tu cuoi lam pivot
    int i = (low - 1); // chi so cua phan tu nho hon
    for(int j = low; j <= high - 1; j ++)
    {
        if(arr[j] <= pivot)
        {
            i ++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return(i + 1);

}
// ham quick sort
void quicksort (int *arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        // sap xep phan tu
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    // cap phat dong
    int *s = (int *) malloc(n* sizeof(int));
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &s[i]);
    }
    quicksort(s, 0, n - 1);
    int max = 0;
    for(int i = n - k; i < n; i ++)
    {
        max += s[i];
    }
    printf("%d", max);
    free(s);
    return 0;
}

/* 
input
2 5
3 2 -1 9 8
output
17
*/