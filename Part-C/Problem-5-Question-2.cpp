#include <iostream>
#include <stack>
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
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        temp[i] = -1;
    }
    
    for (int i = 0; i < 2 * size; i++)
    {
        int idx = i % size;

        while (!st.empty() && arr[st.top()] < arr[idx])
        {
            temp[st.top()] = arr[idx]; 
            st.pop();                          
        }

        if (i < size)
        {
        st.push(idx); 
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