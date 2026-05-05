#include <iostream>
using namespace std;

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void next_greater(int arr[], int size)
{
    int *temp = new int[size];

    for (int i = 0; i < size; i++)
    {
        int j = i + 1;
        while(true)
        {
            if (j >= size)
            {
                j = 0;
            }
            if (arr[j] > arr[i])
            {
                temp[i] = arr[j];
                break;
            }
            if (j == i)
            {
                temp[i] = -1;
                break;
            }
            j++;
        }
    }

    print_arr(temp, size);
    delete[] temp;
}


int main()
{
    int num[] {1, 2, 3, 4, 3};
    next_greater(num, 5);
}
