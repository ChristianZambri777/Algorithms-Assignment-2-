// Algorithms Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Include statements, using statements, function prototypes
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
using namespace std;

void MergeArrays(int* sortArray, int left, int middle, int right);
void PrintArray(int* myArray, int size);


//MergeSort Function 
void MergeSort(int* sortArray, int startIndex, int endIndex)
{

    if (startIndex >= endIndex)
    {
        return;
    }

    //Gets the middle value, and calls merge sort on the left half and right half using reccurssion. Then it merges them.
    int middle= startIndex + (endIndex - startIndex) / 2;
    MergeSort(sortArray, startIndex, middle);
    MergeSort(sortArray, middle + 1, endIndex);
    MergeArrays(sortArray, startIndex, middle, endIndex);
   
}


void MergeArrays(int* sortArray, int left, int middle, int right)
{

    //Calculates size of left and right arrays
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    //Creates left and right temp arrays
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    //Stores elements in left array
    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = sortArray[left + i];
    }

    //Stores element in right array
    for (int i = 0; i < rightSize; i++)
    {
        rightArray[i] = sortArray[middle + 1 + i];
    }

    //Prints out what is being merged 
    cout << "Merging : ";
    PrintArray(leftArray, leftSize);
    cout << "With : ";
    PrintArray(rightArray, rightSize);


    //Gets indexs for left and right sides of arrays to merge
    int index1 = 0;
    int index2 = 0;
    int indexOfMerge = left;


    //Loops for Merge Sorting
    //Checks if index is smaller than the left size and if index2 is smaller than right size to find value to put into sorted array at merge index
    while (index1 < leftSize && index2 < rightSize)
    {

        //Checks if leftArray at index1 is less than the right array at index2 and stores value into sorted array
        if (leftArray[index1] <= rightArray[index2])
        {
            sortArray[indexOfMerge] = leftArray[index1];
            index1++;
        }
        
        //Else stores right value in sorted array
        else
        {
            sortArray[indexOfMerge] = rightArray[index2];
            index2++;
        }
        indexOfMerge++;  
    }

    //Loop that runs while the left size is greater than the left index
    while (index1 < leftSize)
    {
        //Stores left array value into sorted array
        sortArray[indexOfMerge] = leftArray[index1];
        index1++;
        indexOfMerge++;
        
    }

    //Loop that runs while right side index is less than right size
    while (index2 < rightSize)
    {
        //Stores right array value in sorted array
        sortArray[indexOfMerge] = rightArray[index2];
        index2++;
        indexOfMerge++;
        
    }

    //Plays sound and prints array
    PlaySound(TEXT("mySound.mp3"), NULL, SND_FILENAME | SND_SYNC);
    cout << "To get: ";
   PrintArray(sortArray, right + 1);
   
   //Deletes arrays
    delete[] leftArray;
    delete[] rightArray;

}



//Prints array
void PrintArray(int* myArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << ", ";

    }
    cout << "\n\n";
}




//Main method
int main()
{
    //Gets size of array
    int n = 0;
    cout << "Enter the size of your array:\n";
    cin >> n;

    //Creates array and gets input from user
    int* myArray = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of element " << i << ": ";
        cin >> myArray[i];
    }


    //Prints array and calls merge sort
    PrintArray(myArray, n);
    MergeSort(myArray, 0, n - 1);
    PrintArray(myArray, n);

    //Deletes array
    delete[] myArray;
}
