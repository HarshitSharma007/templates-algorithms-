//stress test

#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

#define ll long long int
#define endl "\n"

int naive_soln(int arr[], int n)
{

}

int fast_soln(int arr[], int n)
{
    
}
int main()
{
    srand((unsigned)time(NULL));
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    while (t++)
    {
        int n = rand() % 1000000;
        int range = 10;
        // cin>>n>>m;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = rand() % range;
            //cin>>arr[i];
        }

        int x = fast_soln(arr, n);
        int y = naive_soln(arr, n);
        if (x != y)
        {
            cout << "n= " << n << endl;
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl
                 << x << " " << y;
            // break;
            goto x;
        }
        else
            cout << t << " OK" << endl;
    }
x:
    return 0;
}
