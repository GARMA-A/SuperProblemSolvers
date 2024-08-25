#include "../IMPORTME.cpp"

int partition(vector<int>& arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int start = startIndex + 1;
    int end = endIndex;
    while (start<=end) {
        if(arr[start] <= pivot)
        {
             start++;
        }
        else if( arr[end] > pivot)
        {
             end--;
        }
      else
        { 
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[startIndex], arr[end]);
    return end;
}

void qiuckSort(vector<int>& arr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;
    int pivotIndex = partition(arr, startIndex, endIndex);
    qiuckSort(arr, startIndex, pivotIndex - 1);
    qiuckSort(arr, pivotIndex + 1, endIndex);
}


signed main()
{
    vector<int> v = {9,2,15,3,4};
    qiuckSort(v, 0, v.size()-1);
    for(int n : v)
    {
        cout << n << " ";
    }

}
