

// Name - Naman
// SID - 21105015
// BRANCH - ECE
// QUESTION OF ASSIGNMENT 5:
// COMPARE THE BUBBLE SORT AND THE SELECTION SORT
// 1. ON BASIS OF NUMBER OF COMPARISONS
// 2. ON BASIS OF NUMBER OF SWAPS
// 3. ON BASIS OF INPLACE AND OUTPLACE COMPARISONS


#include <iostream>
using namespace std;


//TIME COMPLEXITY OF THIS CODE - O(n^2).
pair<int,int> bubbleSort(int *input, int size)
{
    int swaps = 0;//we will increase the number of swaps and number of comparisons by one
    // each time we do either of them so that we can get the final number
    int comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                swaps++;
            }
            comparisons++;
        }
    }
    pair<int,int> ans;
    ans.first = swaps;    //first member would store the number of swaps.
    ans.second = comparisons;  //second member would store the umber of comparisons.
    return ans;
}

//TIME COMPLEXITY OF THIS CODE - O(n^2).
pair<int,int> SelectionSort(int *input,int size)
{
    int index;
    int swaps = 0;
    int comparisons = 0;
    for(int i=0;i<size;i++)
    {
        index = i;
        for(int j=i+1;j<size;j++)
        {
            if(input[j]<input[index])
            {
                index = j;
                swaps++;
            }
            comparisons++;
        }
        int temp = input[i];
        input[i] = input[index];
        input[index] = temp;
    }
    pair<int,int> ans;
    ans.first = swaps;
    ans.second = comparisons;
    return ans;
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    pair<int,int> bubble = bubbleSort(arr,size);
    pair<int,int> selection = SelectionSort(arr,size);

//     ON BASIS OF NUMBER OF COMPARISONS WHILE SORING
    if(bubble.second > selection.second)
    {
        cout << "Bubble Sort has more comparisons than Selection Sort" << endl;
    }
    else if(bubble.second < selection.second)
    {
        cout << "Selection Sort has more comparisons than Bubble Sort" << endl;
    }
    else
    {
        cout << "Both have equal comparisons" << endl;
    }
    cout << endl;


//     ON BASIS OF NUMBER OF SWAPS WHILE SORING
    if(bubble.first > selection.first)
    {
        cout << "Bubble Sort has more Swaps" << endl;
    }
    else if(bubble.first < selection.first)
    {
        cout << "Selection Sort has more Swaps" << endl;
    }
    else
    {
        cout << "Both have equal number of Swaps" << endl;
    }
    cout << endl;

    cout << "3 . As both BubbleSort and SelectionSort are In-place algorithms, hence both of their Algorithms have been written above" << endl;

}
