#include <cstdio>

#define INF 0x3f3f3f3f
int a[100002];
int trocas;


void merge(int low, int mid, int high)
{
    int n1 = mid - low + 1; 
    int n2 = high - mid; 
    int left[n1 + 1], right[n2 + 1]; 
    
    for (int i = 0; i < n1; i++)
        left[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];
    
    left[n1] = INF;
    right[n2] = INF;
    int i = 0, j = 0;
    for (int k = low; k <= high; k++)
        if (left[i] <= right[j])
            a[k] = left[i++];
        else
        {
            trocas += ((mid + 1) - (low + i));
            a[k] = right[j++];
        }
}


void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}


int main()
{
    int tam;
    while (scanf("%d", &tam) && tam)
    {
        for (int i = 0; i < tam; i++)
            scanf("%d", &a[i]);
        trocas = 0;
        merge_sort(0, tam - 1);
        puts((trocas % 2 ? "Marcelo" : "Carlos"));
    }
    return 0;
}
