#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int up)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    int temp[100];

    while (i <= mid && j <= up)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= up)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = lb; i <= up; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int lb, int up)
{
    if (lb < up)
    {
        int mid = (lb + up) / 2;

        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, up);

        merge(arr, lb, mid, up);
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
