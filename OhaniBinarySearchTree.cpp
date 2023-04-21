#include <bits/stdc++.h>
using namespace std;


int* parent, *tree,n,*a,*lis;



int binSearchRec(int left, int right, int x)
{
    if (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        if (a[lis[mid]] >= a[x])
            return binSearchRec(left, mid, x);
        else
            return binSearchRec(mid, right, x);
    }

    return right;
}

int findLis()
{
    int i, pos, ch;
    if (n == 0)
        pos = 0;
    else
    {
        pos = 1;
        lis[0] = 0;
        for (i = 1; i < n; i++)
        {
            if (a[i] > a[lis[pos - 1]])
                lis[pos] = i,
            pos++;
            else
            {
                if (a[i] < a[lis[0]])
                    lis[0] = i;
                else
                {
                    ch = binSearchRec(-1, pos - 1, i);
                    lis[ch] = i;
                }
            }
        }
    }

    return pos;
}

void findRoot(int l, int r, int i)
{
    if (l == r)
    {
        tree[i] = l;
        if (i == 0)
            parent[l] = -1;
        else if (i % 2 != 0)
            parent[l] = tree[((i - 1) / 2)];
        else
            parent[l] = tree[((i - 2) / 2)];
    }

    if (r > l && i < n)
    {
        int h, max, maxnodes, root, tn = (r - l + 1);
        h = floor(log2(r - l + 1));
        maxnodes = pow(2, (h + 1));
        max = maxnodes / 2;
        if (maxnodes - 1 > tn)
        {
            root = ((max) / 2) + (tn + 1 - max) + (l - 1);
            if (root > ((maxnodes / 2) + (l - 1)))
                root = (maxnodes / 2) + (l - 1);
        }
        else
            root = ((tn + 1) / 2) + (l - 1);

        tree[i] = root;
        if (i == 0)
            parent[root] = -1;
        else if (i % 2 != 0)
            parent[root] = tree[((i - 1) / 2)];
        else
            parent[root] = tree[((i - 2) / 2)];
        findRoot(l, root - 1, 2 * i + 1);
        if (parent[root + 1] == 0)
            findRoot(root + 1, r, 2 * i + 2);
    }
}

int main()
{
    int l, i, j, t;
    cin>>t;
    for (j = 1; j <= t; j++)
    {
        cin>>n;
        parent = new int[n + 1];
        tree = new int[n + 1];
        a = new int[n + 1];
        lis = new int[n + 1];
        for (i = 0; i < n; i++)
            cin>>a[i];
        memset(parent, 0, sizeof(parent));
        cout<<"Case "<<j<<":"<<endl;
        l = findLis();
        cout<< "Minimum Move: "<< n - l<< endl;
        findRoot(1, n, 0);
        for (i = 1; i < n; i++)
            cout << parent[i] << " ";
        cout << parent[i] << endl;
    }

    return 0;
    
}
    