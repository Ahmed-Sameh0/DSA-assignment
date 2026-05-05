#include <iostream>
using namespace std;

int comparisons = 0;
int swaps = 0; 

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void selection_sort(int arr[], int start, int size)
{
    for (int i = start; i < size - 1; i++)
    {
        int largest_num_index = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if(arr[j] > arr[largest_num_index])
            {
                largest_num_index = j;
            }
        }
        if(largest_num_index != i)
        {
            swap(arr[i], arr[largest_num_index]);
            swaps++;
        }
    }
}


void bitonic_sort(int arr[], int size)
{
    int middle = size / 2;
    bubble_sort(arr, middle);
    selection_sort(arr, middle, size);
}

int linear_search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    // target not found
    return -1;
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void run_test(int arr[], int size, int target)
{
    comparisons = 0;
    swaps = 0;
    cout << "Before" << endl;
    print_arr(arr, size);
    cout << "After" << endl;
    bitonic_sort(arr, size);
    print_arr(arr, size);

    int search = linear_search(arr, size, target);
    if(search == -1)
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << target << " Is at index: " << search << endl;
    } 
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "--------------------------" << endl;
}

int main()
{
    int arr1[] = {8, 3, 12, 5, 6, 1, 9, 2};
    run_test(arr1, 8, 12);

    int arr2[] = {7, 2, 10, 4, 9, 1, 5, 3};
    run_test(arr2, 8, 4);

    int arr3[] = {6, 11, 2, 8, 15, 3, 9, 1};
    run_test(arr3, 8, 3);

    int arr4[] = {5, 2, 8, 1, 7, 3, 6, 4};
    run_test(arr4, 8, 100);

    int arr5[] = {4, 2, 4, 8, 2, 9, 1, 9};
    run_test(arr5, 8, 9);

}