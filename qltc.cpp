#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define fi first
#define se second
#define en cout << '\n'
#define vc vector
#define nll nullptr
#define pr pair<string, int>
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

typedef struct node
{
    int mahang;
    int trongluong;
    int dongia;
    string tentraicay;
    struct node *next;
} list;

void iof()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
}

node *makenode(int mh, int tl, int dg, string nm)
{
    node *tmp = new node();
    tmp->mahang = mh;
    tmp->trongluong = tl;
    tmp->dongia = dg;
    tmp->tentraicay = nm;
    tmp->next = nll;
    return tmp;
}

void insL(node *&head, int mh, int tl, int dg, string nm)
{
    node *tmp = makenode(mh, tl, dg, nm);
    if (head == nll)
    {
        head = tmp;
        return;
    }

    node *n1 = head;

    while (n1->next != nll)
    {
        n1 = n1->next;
    }

    n1->next = tmp;
}

void delF(node *&head)
{
    if (head == nll)
    {
        return;
    }

    node *n1 = head;
    head = n1->next;
    delete n1;
}

void duyet(node *head)
{
    node *n1 = head;
    while (n1 != nll)
    {
        cout << n1->mahang;
        n1 = n1->next;
        en;
    }
    return;
}
void bill(node *head, int mh)
{
    node *li = head;
    int cnt = 0;
    ll vl = 0;
    while (li != nll)
    {
        if (li->mahang == mh)
        {
            vl += li->dongia * li->trongluong;
            if (!cnt)
            {
                cout << li->mahang << " " << li->trongluong << " " << li->dongia << " " << li->tentraicay << ". ";
                cnt++;
            }
        }
        li = li->next;
    }

    if (cnt == 0)
    {
        cout << "Not Found\n";
        return;
    }
    cout << "Total:" << vl;
    en;
}

void ip()
{
    node *head = nll;
    string s;
    while (cin >> s)
    {
        if (s == "Fin")
            break;
        else if (s == "Add")
        {
            int mh, tl, dg;
            string nm;
            cin >> mh >> tl >> dg;
            cin.ignore(1);
            cin >> nm;
            insL(head, mh, tl, dg, nm);
        }
        else if (s == "Del")
        {
            delF(head);
        }
        else
        {
            int mh;
            cin >> mh;
            bill(head, mh);
        }
    }
}

int main()
{
    ios;
    clock_t begin = clock();
    iof();
    ip();
    // solve();
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
    return 0;
}