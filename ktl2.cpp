#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vc vector
#define pb push_back
#define str string;
#define en cout << '\n'
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)

void iof()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
}

bool check(string s)
{
    int len = s.size();
    if (len < 4)
    {
        ll vl = stoll(s);
        if (vl % 16 == 0)
            return 1;
        return 0;
    }
    int id = len - 4;
    string x = s.substr(id, 4);
    ll vl = stoll(x);
    if (vl % 16 == 0)
        return 1;
    else
        return 0;
}

void ip()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (check(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios;
    clock_t begin = clock();
    iof();
    ip();
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
    return 0;
}