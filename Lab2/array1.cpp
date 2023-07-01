#include <iostream>

using namespace std;

int arr_size;
bool increasing = true;

int main()
{
    cout << "Enter the size of the array: ";
    cin >> arr_size;

    if (arr_size < 0)
    {
        cout << "ERROR: you entered an incorrect value for the array size!" << endl;
        return 0;
    }

    cout << "Enter the numbers in the array, separated by a space, and press enter: " << endl;
    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
        if (i != 0)
        {
            if (arr[i] <= arr[i - 1])
            {
                increasing = false;
            }
        }
        cout << arr[i] << " ";
    }
    cout << endl;

    if (increasing)
    {
        cout << "This IS an increasing array!" << endl;
    }
    else
    {
        cout << "This is NOT an increasing array!" << endl;
    }
    return 0;
}
