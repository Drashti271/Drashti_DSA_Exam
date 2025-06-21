#include<iostream>
#include<vector>
using namespace std;

// Binary Search

int BinarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr;
    int n,target,result;

    cout<<"Enter the size of array: ";
    cin>>n;

    arr.resize(n);
    cout<<"Enter "<< n << " Sorted elements: "<<endl;

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the target value of a search: "<<endl;
    cin>>target;

    result = BinarySearch(arr,target);

    if(result != -1)
    {
        cout<<"Element is found at index: "<<result;
    }
    else
    {
        cout<<"Element Not found.";
    }

    return 0;
}