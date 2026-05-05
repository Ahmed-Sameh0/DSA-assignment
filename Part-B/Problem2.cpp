#include <iostream>
using namespace std;

int comparisons = 0;

int search_rotated(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        comparisons++;
        if (arr[mid] == target)
        {
            return mid;
        }

        comparisons++;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
        }
        else
        {
            comparisons++;
            if (arr[low] <= arr[mid])
            {
                comparisons += 2;
                if (arr[low] <= target && target < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                comparisons += 2;
                if (arr[mid] < target && target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 6, 7, 1, 2, 3, 4};
    int size = 7;
    int target = 3;

    int index = search_rotated(arr, size, target);

    if (index == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found at index: " << index << endl;
    }

    cout << "comparisons: " << comparisons << endl;

    return 0;
}


// The time complexity for the best case is O(1) when the element is in the middle of the array
// The time complexity for the average case is O(log n)
// time complexity for the worst case (duplicates) O(n)