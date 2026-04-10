#include <iostream>
using namespace std;

int partition(int arr[], int lb, int up)
{
    int pivot = arr[lb];   // pivot = first element
    int start = lb;
    int end = up;

    while (start < end)
    {
        // move start forward until element > pivot
        while (arr[start] <= pivot)
        {
            start++;
        }

        // move end backward until element <= pivot
        while (arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }

    // place pivot at correct position
    swap(arr[lb], arr[end]);

    return end;
}

void quickSort(int arr[], int lb, int up)
{
    if (lb < up)
    {
        int loc = partition(arr, lb, up);

        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, up);
    }
}

int main()
{
    int arr[] = {4, 1, 5, 2, 3};
    int n = 5;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
