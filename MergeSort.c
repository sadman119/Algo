#include <stdio.h>
void mergeSort(int ar[],int low, int high);
void merge(int ar[], int low, int mid, int high);

void merge(int ar[], int low, int mid, int high)
{
    //left array
    int left_array_length = mid - low + 1;
    int L[left_array_length];
    for(int i = 0; i < left_array_length; i++)
    {
        L[i] = ar[low+i];
    }
    //right array
    int right_array_length = high - mid;
    int R[right_array_length];
    for(int i = 0; i < right_array_length; i++)
    {
        R[i] = ar[mid+1+i];
    }
    //compare and merge
    int i = 0, j = 0,k = low;
    while(i<left_array_length && j <right_array_length)
    {
        if(L[i] < R[j])
        {
            ar[k] = L[i];
            i++;k++;
        }
        else
        {
            ar[k] = R[j];
            j++;k++;
        }
    }
    //After merging address the leftover values
    while(i<left_array_length)
    {
        ar[k] = L[i];
        i++;k++;
    }
    while(j<right_array_length)
    {
        ar[k] = R[j];
        j++;k++;
    }

}
void mergeSort(int ar[],int low, int high)
{
    if(low < high)
    {

        int mid = (low+high) /2;
        mergeSort(ar,low, mid);
        mergeSort(ar,mid+1, high);
        merge(ar, low, mid, high);
    }
}
int main() {
    int sz;
    scanf("%d", &sz);
    int ar[sz];
    for(int i = 0; i<sz; i++)
    {
        scanf("%d", &ar[i]);
    }
    mergeSort(ar,0, sz-1);
    for(int i =0; i<sz; i++)
    {
        printf("%d\t", ar[i]);
    }
    return 0;
}
