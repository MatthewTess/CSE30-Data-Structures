#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList firstList;
    LinkedList secondList;

    // Check if the lists are empty
    if (firstList.isEmpty())
        cout << "The first list is empty!" << endl;
    else
        cout << "The first list is NOT empty..." << endl;

    if (secondList.isEmpty())
        cout << "The second list is empty!" << endl;
    else
        cout << "The second list is NOT empty..." << endl;

    // Print the size of the lists
    cout << "The size of the first list is: " << firstList.size() << endl;
    cout << "The size of the second list is: " << secondList.size() << endl;

    // Insert some values into the first list
    firstList.insertAtBack(1);
    firstList.insertAtBack(2);
    firstList.insertAtBack(3);
    firstList.insertAtBack(4);
    firstList.insertAtBack(5);

    // Print the lists
    cout << "Here is the first list: [";
    firstList.print();
    cout << "]" << endl;
    cout << "Here is the second list: [";
    secondList.print();
    cout << "]" << endl;

    // Insert a value into the second list
    secondList.insertAtBack(25);

    // Print the lists
    cout << "Here is the first list: [";
    firstList.print();
    cout << "]" << endl;
    cout << "Here is the second list: [";
    secondList.print();
    cout << "]" << endl;

    // Clear the second list and remove an item from the first list
    secondList.clear();
    firstList.removeFromBack();

    // Print the lists
   
