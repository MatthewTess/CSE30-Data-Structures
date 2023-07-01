#include <iostream>

using namespace std;

int arr_size;

void sort(int arr[])
{
    cout << "This is the sorted array in descending order: ";
    for (int i = 0; i < arr_size; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }
        swap(arr[i], arr[max_idx]);
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The algorithm selected the maximum for the traverse of the array." << endl;
}

int main()
{
    cout << "Enter the size of the array: ";
    cin >> arr_size;

    if (arr_size < 0)
    {
        cout << "ERROR: you entered an incorrect value for the array size!" << endl;
        return 0;
    }

    cout << "Enter the numbers in the array, separated by a space, and press enter: ";
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }
    sort(arr);
    return 0;
}
