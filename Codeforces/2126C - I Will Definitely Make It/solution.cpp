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
        int init = arr[k - 1];
        set<int> s;
        for (const auto x : arr)
        {
            if (x >= init)
                s.insert(x);
        }
        bool ans = true;
        int prev = init;
        for (auto &x : s)
        {
            if (x - prev > init)
                ans = false;
            prev = x;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}