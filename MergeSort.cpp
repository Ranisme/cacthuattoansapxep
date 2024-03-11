#include <bits/stdc++.h>

using namespace std;

void mergeSort(vector<double> &left, vector<double> &right, vector<double> &bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k])
        {
            bars[i] = left[j];
            j++;
        }
        else
        {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL)
    {
        bars[i] = left[j];
        j++;
        i++;
    }
    while (k < nR)
    {
        bars[i] = right[k];
        k++;
        i++;
    }
}

void Sort(vector<double> &bar)
{
    if (bar.size() <= 1)
        return;

    int mid = bar.size() / 2;
    vector<double> left;
    vector<double> right;

    for (size_t j = 0; j < mid; j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    Sort(left);
    Sort(right);
    mergeSort(left, right, bar);
}

vector<double> arr;
clock_t Start, End;
double duration;

int main()
{
    freopen("text10.txt", "r", stdin);
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
    Sort(arr);
    End = clock();
    duration = ((double)(End - Start)) / CLOCKS_PER_SEC;
    cout << "Time run: " << duration << " s" << endl;
    return 0;
}