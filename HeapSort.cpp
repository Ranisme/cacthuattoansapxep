#include <bits/stdc++.h>

using namespace std;

void max_heapify(vector<double> &arr, int i, int size_)
{
    int largest, l = (2 * i) + 1, r = l + 1;

    if (l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if (r < size_ && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size_);
    }
}

void build_max_heap(vector<double> &arr)
{
    for (int i = (arr.size() / 2); i >= 0; i--)
        max_heapify(arr, i, arr.size());
}

void heap_sort(vector<double> &arr)
{
    build_max_heap(arr);
    int sz = arr.size();
    for (int i = arr.size() - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        sz--;
        max_heapify(arr, 0, sz);
    }
}

vector<double> arr;

clock_t Start, End;
double duration;


int main()
{
    freopen("text9.txt", "r", stdin);
    freopen("time.txt", "w", stdout);
    ios_base::sync_with_stdio(false);  
    cout.tie(NULL);
    int n = 1000000;
    for (int i = 0; i < n; i++)
    {
        double cur;
        cin >> cur;
        arr.push_back(cur);
    }
    Start = clock();
    heap_sort(arr);
    End = clock();
    duration = ((double) (End - Start)) / CLOCKS_PER_SEC;
    cout<<"Time run: "<< duration << " s"<<endl;
    return 0;
}