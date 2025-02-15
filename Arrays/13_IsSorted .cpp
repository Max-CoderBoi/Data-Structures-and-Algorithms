// #include<iostream>
// using namespace std;

// struct Array
// {
// 	int* A;
// 	int size;
// 	int length;
// };
// void Display(struct Array* arr)
// {
// 	int i;
// 	cout << "the elements of the array is " << endl;
// 	for (i = 0; i < arr->length; i++)
// 		cout <<arr->A[i] << " ";
// }

// int IsSorted(struct Array* arr)
// {
// 	for (int i = 0; i < arr->length - 1; i++) 
// 	{
// 		if (arr->A[i] > arr->A[i + 1]) // if 1st element is greater then 2nd element then it will k/as not sorted so return 0 
// 			return 0;
// 	}
	
// 	return 1; // if everything is ok and the element came successfully out of loop means it is sorted return 1 for thet 
// }
// int main()
// {
// 	struct Array arr;
// 	cout << "Enter the size of Array " << endl;
// 	cin >> arr.size;
// 	arr.A = new int[arr.size];	
// 	int no;
// 	cout << "Enter the length of the array " << endl;
// 	cin >> no;
// 	arr.length = 0;	
// 	cout << "Enter the elements of the array " << endl;
// 	for (int i = 0; i < no; i++)
// 		cin >> arr.A[i];
// 	arr.length = no;
// 	cout<<IsSorted(&arr);
//  return 0;
// }
#include <iostream>
using namespace std;

struct Array
{
    int* A;
    int size;
    int length;
};

// Function to check if the array is sorted in ascending order
int IsSorted(const struct Array* arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] > arr->A[i + 1]) // If any element is greater than the next, it's not sorted
            return 0;
    }
    return 1; // If no issues found, return 1 (sorted)
}

int main()
{
    struct Array arr;

    // Get the array size
    cout << "Enter the size of the array: ";
    cin >> arr.size;

    arr.A = new int[arr.size]; // Allocate memory dynamically

    // Get the length of the array
    int no;
    cout << "Enter the number of elements: ";
    cin >> no;

    // Validate input
    if (no > arr.size) {
        cout << "Error: Number of elements cannot exceed the array size!" << endl;
        delete[] arr.A; // Free memory before exiting
        return 1; // Exit with error
    }

    arr.length = no;

    // Input elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < no; i++)
        cin >> arr.A[i];

    // Check if array is sorted
    if (IsSorted(&arr))
        cout << "The array is sorted." << endl;
    else
        cout << "The array is NOT sorted." << endl;

    delete[] arr.A; // Free allocated memory

    return 0;
}
