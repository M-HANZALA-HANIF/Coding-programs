//BINARY SEARCH FOR SINGLE OCCURANCE:
#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {11,12,27,36,52,72,72,82,88,99}; 
    int target;
    int l = 0, r = 9, mid;

    cout << "Enter number: ";
    cin >> target;

    while(l <= r)
    {
        mid = (l+r) / 2;

        if(arr[mid] == target)
        {
            cout << "Value found at index " << mid;
            return 0;
        }
        if(arr[mid] < target)
        {
            l = mid + 1;  
        }
        if(arr[mid]> target)
        {
            r= mid - 1;
        }
    }

    cout << "Value not found";
    return 0;}
