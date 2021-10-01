#include<iostream>
#include<math.h>
#include<unordered_set>
#include<algorithm>

using namespace std;

int memo[1005][1005];

int ans(int a[],int price[],int w,int n)
{
    if(w==0||n==0)
    {
        return 0;
    }
    if(memo[n-1][w]!=0)
    {
        return memo[n-1][w];
    }

    int res;

    if (w - a[n] >= 0)
    {
        res = max(price[n] + ans(a, price, w - a[n], n - 1), ans(a, price, w, n - 1));
    }
    else
    {
        res = ans(a, price, w, n - 1);
    }
    memo[n-1][w]=res;
    return res;
}

int main()
{
    memset(memo,0,sizeof(memo));
    int n, w;

    cin >> n >> w;

    int a[n+1], price[n+1];

    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++)
    {
        cin >> price[i];
    }

    int cnt = ans(a, price, w, n);

    cout << cnt;

    return 0;
}