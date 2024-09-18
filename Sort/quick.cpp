#include "../IMPORTME.cpp"

int partition(vector<int>& arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int start = startIndex + 1;
    int end = endIndex;
    while (start<=end) {
        if(arr[start] <= pivot)
        {
             start++;
        
        else if( arr[end] > pivot)
        {
             end--;
        
      else
        { 
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[startIndex], arr[end]);
    return end;
}

void helperquicksort(vector<int>& arr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;
    int pivotIndex = partition(arr, startIndex, endIndex);
    helperquicksort(arr, startIndex, pivotIndex - 1);
    helperquicksort(arr, pivotIndex + 1, endIndex);
}

void quicksort(vector<int>& arr) {
    helperquicksort(arr, 0, arr.size() - 1);
}


signed main()
{
    vector<int> v = {9,2,15,3,4};
    quicksort(v);
    for(int n : v)
    {
        cout << n << " ";
    }

}
