#include<iostream>
#include<utility>


using namespace std;

void SortowaniePrzezWstawianie(int arr[], int length)
{
    for(int index = 1; index < length; index++)
    {
        int key = arr[index];
        int moving_index = index - 1;

        while(moving_index >= 0 && arr[moving_index] > key)
        {
            arr[moving_index + 1] = arr[moving_index];
            moving_index--;
        }
        
        arr[moving_index + 1] = key;
    }
}

void BubbleSort(int arr[], int length)
{
    bool swapped;
    for(int index = 0; index < length-1; index++)
    {
        swapped = false;
        for(int movingIndex = 0; movingIndex < length-index-1; movingIndex++)
        {
            if (arr[movingIndex] > arr[movingIndex + 1]) 
            {
                swap(arr[movingIndex], arr[movingIndex + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void MergeSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int mid = (start & end) + ((start ^ end) >> 1);
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, start, mid, end);
}

void Merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int *left = new int[leftSize], *right = new int[rightSize];

    for(int index = 0; index < leftSize; index++)
        left[index] = arr[start+index];
    
    for(int index = 0; index < rightSize; index++)
        right[index] = arr[mid + 1 + index];

    int leftIndex = 0, rightIndex = 0;
    int resultIndex = start;

    while(leftIndex < leftSize && rightIndex < rightSize)
    {
        if(left[leftIndex] <= right[rightIndex])
        {
            arr[resultIndex] = left[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[resultIndex] = right[rightIndex];
            rightIndex++;    
        }
        resultIndex++;
    }

    while(leftIndex < leftSize)
    {
        arr[resultIndex] = left[leftIndex];
        leftIndex++;
        resultIndex++;
    }

    while(rightIndex < rightSize)
    {
        arr[resultIndex] = right[rightIndex];
        rightIndex++;
        resultIndex++;
    }

    delete[] left;
    delete[] right;
}

void QuickSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int pivot = arr[(start+end)>>1];
    int leftIndex = start-1;
    int rightIndex = end+1;

    while(true)
    {
        while(pivot > arr[++leftIndex]);

        while(pivot < arr[--rightIndex]);

        if(leftIndex <= rightIndex)
            swap(arr[leftIndex], arr[rightIndex]);
        else
            break;
    }

    if(rightIndex >= start)
        QuickSort(arr, start, rightIndex);

    if(leftIndex <= end)
        QuickSort(arr,leftIndex, end);
}