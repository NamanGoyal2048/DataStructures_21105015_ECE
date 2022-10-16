// UNKNOWN SIZE OF THE ARRAY TO PERFORM THE BINARY SEARCH OF THE ARRAY
//  NAMAN GOYAL
// 21105015
// ECE

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// CREATING THE FUNCTION SUCH THAT WE ARE NOT PASSING THE SIZE OF THE ARRAY TO THE FUNCTION.

// LINEAR SEARCH

// in linear search keep transversing the array until we are not able to find the element of the array
int linear_search(int arr[], int element)
{
    for (int i = 0;; i++) 
    // No condition on terminating the loop of linear search
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
}

// BINARY SEARCH

//this function is a simple binary search function where left and right index are being provided.

int binary_search_code(int arr[],int l,int r,int element)
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>element)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<element)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}

//we try to reduce our work done to O(log(N)) time complexity, by increasing the range of our search exponentitaly by 2 every time.

int binary_search(int arr[], int element)
{
    int low = 0;
    int high = 1;

    while (arr[high] < element) //if element to be found is still high the value at high index .
    {
        low = high; //update the low value
        high = 2 * high; //double the range of search exponentially , when the condition is satisfies then we call BINARY SEARCH on that range(low to high).
    }

    return binary_search_code(arr,low,high,element);
}


/*
NOTE - We are creating an array , but the size of the array is not passed to the function.
*/
int main()
{
    // you are given the starting index of the array.
    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int element;
    cout << "ENTER THE ELEMENT TO SEARCH FOR : ";
    cin >> element;
    cout << endl;

    cout << "Index of " << element << " from LINEAR SEARCH is : " << linear_search(arr, element) << endl;
    cout << "Index of " << element << " from BINARY SEARCH is : " << binary_search(arr, element) << endl;
    delete[] arr;
}
