#include<iostream>
#include<vector>
using namespace std;

// Merge and Quick Sort

void inputArray(vector<int>& arr)
{
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) 
    {
        cin >> value;
        arr.push_back(value);
    }
}

void Merge(vector<int> &arr, int start,  int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for(int k = 0; k < temp.size(); k++)
    {
        arr[start + k] = temp[k];
    }
}

void MergeSort(vector<int> &arr, int start, int end)
{
    if(start >= end) return;

    int mid = start + (end - start) / 2;

    MergeSort(arr,start,mid);

    MergeSort(arr,mid + 1,end);

    Merge(arr,start,mid,end);
}

int Partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[++i] , arr[j]);
        }
    }
    swap (arr[i + 1],arr[end]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    if(start >= end) return;

    int pivotIndex = Partition(arr, start, end);

    QuickSort(arr, start, pivotIndex - 1);

    QuickSort(arr, pivotIndex + 1, end);
}

void Display(vector<int> &arr)
{
    cout << "Array is: ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    int choice;

    do
    {
       cout << endl << "-------Merge and Quicke Sort Menu------" << endl;
       cout <<"Enter 1 for Input Array." << endl;
       cout <<"Enter 2 for Merge Sort." << endl;
       cout <<"Enter 3 for Quick Sort." << endl;
       cout <<"Enter 4 for Display Array." << endl;
       cout <<"Enter 0 for Exit." << endl;

       cout << "Enter your choice: ";
       cin >> choice;

       switch (choice)
       {
            case 1:
            inputArray(arr);
            break;

            case 2:
                MergeSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Merge Sort." << endl;
            break;

            case 3:
                QuickSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Quick Sort." << endl;
            break;

            case 4:
                Display(arr);
            break;

            case 0:
                cout << "Exiting....";
            break;
        
            default:
                cout << "Invalid Choice...";
            break;
       }
    } while (choice != 0);

    return 0;
}