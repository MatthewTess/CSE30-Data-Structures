#include <iostream>

using namespace std;

int arr_size;
int v;

void search(const int arr[], int key)
{
    int count = 0;
    for (int i = 0; i < arr_size; i++)
    {
        count++;
        if (arr[i] == key)
        {
            cout << "Found value " << key << " at index " << i << ", which took " << count << " checks." << endl;
            if (count == 1)
            {
                cout << "We ran into the best case scenario!" << endl;
            }
            if (count == arr_size)
            {
                cout << "We ran into the worst case scenario!" << endl;
            }
            return;
        }
    }
    cout << "The value " << key << " was not found in the array!" << endl;
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

    cout << "Enter the numbers in the array, separated by a space, and press enter: " << endl;
    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter a number to search for in the array: " << endl;
    cin >> v;

    search(arr, v);
    return 0;
}
