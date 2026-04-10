//BINARY SEARCH FOR MULTIPLE OCCURANCE:
#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {11,12,27,36,52,72,72,82,88,99};
    int target;
    int l = 0, r = 9, mid;
    int index = -1;

    cout << "Enter number: ";
    cin >> target;

    // Binary Search (find one occurrence)
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if (index == -1)
    {
        cout << "Value not found";
    }
    else
    {
        cout << "Value found at index: ";

        // Left side check
        int i = index;
        while (i >= 0 && arr[i] == target)
        {
            i--;
        }
        i++;

        // Right side check
        while (i < 10 && arr[i] == target)
        {
            cout << i << " ";
            i++;
        }
    }

    return 0;
}
