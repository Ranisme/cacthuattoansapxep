#include <bits/stdc++.h>

using namespace std;

double a[1000010];

int main()
{
    freopen("text1.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    int n = 1e6;
    for (int i = 1; i <= n; i++)
    {
        bool dau = rand() % 2;
        double x = rand() % 1000000;
        double y = rand() % 1000000;
        if (y == 0)
            a[i] = 0;
        else
            a[i] = x / y;
        if (dau == 1)
            a[i] = -1 * a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
