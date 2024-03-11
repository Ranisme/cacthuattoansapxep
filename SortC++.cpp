#include <bits/stdc++.h>

using namespace std;

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
    sort(arr.begin(), arr.end());
    End = clock();
    duration = ((double) (End - Start)) / CLOCKS_PER_SEC;
    cout<<"Time run: "<< duration << " s"<<endl;
    return 0;
}