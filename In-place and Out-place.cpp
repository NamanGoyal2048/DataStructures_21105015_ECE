/*
ANS -1:
An in-place algorithm is an algorithm that does not need an extra space and produces an 
output in the same memory that contains the data by transforming the input
 ‘in-place’. However, a small constant extra space used for variables is allowed.
 In-place means that the algorithm does not use extra space for manipulating the input but 
 may require a small though non-constant extra space for its operation. Usually, 
 this space is O(log n), though sometimes anything in O(n) (Smaller than linear) is allowed.*/

// ANS-2:

#include <iostream>
using namespace std;

void insertion_sort_inplace(int arr[], int n)
{
    // Initialising variables i and j
    int i = 0, j = i + 1;
    while (j <= n - 1)
    {
        int temp = arr[j];
        while (i >= 0)
        {
            if (arr[i] > temp)
            {
                arr[i + 1] = arr[i];
                i--;
            }
            if (i == -1)
            {
                arr[0] = temp;
                break;
            }
            if (arr[i] <= temp)
            {
                arr[i + 1] = temp;
                break;
            }
        }
        j++;
        i = j - 1;
    }
    return;
}

// Insertion Sort Using Out-Place Algorithm
void insertion_sort_outplace(int arr[], int start, int end)
{

    if (start == end)
    {
        return;
    }
    int j = start + 1;
    int temp = arr[j];
    while (start >= 0)
    {
        if (arr[start] > temp)
        {
            arr[start + 1] = arr[start];
            start--;
        }
        if (start == -1)
        {
            arr[0] = temp;
            break;
        }
        if (arr[start] <= temp)
        {
            arr[start + 1] = temp;
            break;
        }
    }
    insertion_sort_outplace(arr, start + 1, end);
}
// Function to print array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    // Taking Input array
    cout << "ENTER NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin >> n;
    int arr[n], arr2[n]; // Two array with same size and elements
    cout << "ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // copying arr to arr2
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    cout << endl;
    cout << "ARRAY BEFORE SORTING : ";
    printarr(arr, n);

    // Calling insertion sort using in-place algorithm.
    insertion_sort_inplace(arr, n);
    cout << endl;
    cout << "ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    print_array(arr, n);
    cout << endl;

    // calling insertiong sort using out-place algorithm.
    insertion_sort_outplace(arr2, 0, n - 1);
    cout << "ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    print_array(arr, n);

    cout << endl;
}

/*
ANS-3:
In-place means that the algorithm does not use extra space for manipulating the input but 
may require a small though non-constant extra space for its operation. Usually, this space 
is O(log n), though sometimes anything in O(n) (Smaller than linear) is allowed.

Examples of in place Sorting Algorithms:-

Bubble Sort
Heap Sort
Insertion Sort
Quick Sort
Selection sort

Examples of not in place Algorithms :-

Merge Sort
Radix Sort
In-place techniques have lesser space complexity but are difficult to
apply in algorithm whereas out-place techniques are easy to apply but
increases the space complexity of algorithm.
For exapmle if we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the
middle of array,If we want to solve the same problem using out-place
algorithm we have to create one extra array of same size and copy
elements of original array from back to the front of new array,this
algorith increases the space complexity to O(n) as we have creaed an
extra array.
IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.
*/
