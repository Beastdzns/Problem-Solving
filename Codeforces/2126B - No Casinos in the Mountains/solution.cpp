#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;

        int peak = 0;
        int cnt = 0;
        for (auto x : arr)
        {
            if (x == 0)
                cnt++;
            else
                cnt = 0;

            if (cnt == k)
            {
                peak++;
                cnt = -1;
            }
        }
        cout << peak << endl;
    }

    return 0;
}