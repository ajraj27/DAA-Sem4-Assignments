#include<iostream>
using namespace std;
bool check(int x,int n)
{
    int temp = x*x;
    if(temp < n)
    {
        return true;
    }
    else if(temp == n)
    {
        printf("It is a perfect sqaure");
        exit(0);   
    }
    return false;
}
void SquareRoot(int hi,int lo,int n)
{
    while(lo <= hi)
    {
        int mid = (lo) + (hi-lo)/2;
        if(check(mid,n))
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    int lst = n%10;
    if(lst != 0 and lst != 1 and lst != 4 and lst != 6 and lst != 9 and lst != 5)
    {
        //best case
        cout << "This is not the perfect square !!" << endl;
        exit(0);
    }
    SquareRoot(n,0,n);// best case is 4;
    printf("This is not the perfect square ");
}
signed main()
{
    solve();
    return 0;
}