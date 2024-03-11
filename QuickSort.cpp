#include <bits/stdc++.h>

using namespace std;


const string number = "1";

clock_t Start, End;
double duration;

vector <double> arr;

int partition(vector<double> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    double pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<double> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

int main()
{
  freopen("text9.txt", "r", stdin);
  freopen("time.txt", "w", stdout);
  ios_base::sync_with_stdio(false);  Start = clock();
  cin.tie(NULL);
  cout.tie(NULL);
  int n = 1000000;
  for (int i = 0; i < n; i++)
  {
    double cur;
    cin >> cur;
    arr.push_back(cur);
  }
  Start = clock();
  quicksort(arr, 0, n - 1);
  End = clock();
  duration = ((double) (End - Start)) / CLOCKS_PER_SEC;
  cout<<"Time run: "<< duration << " s"<<endl;
  return 0;
}
