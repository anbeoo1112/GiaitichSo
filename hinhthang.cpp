#include<bits/stdc++.h>
#define f(x) ((x*x)/(4*x*x+8))*atan(x)
using namespace std;

double tichphan(double x, double y, int n){
    double h=(y-x)/(n);
    double s;
    s=f(x)+f(y);
    for (int i=1;i<6;i++)
        s+=2*f(x+i*(h));
    return s*(h/2);
}
int main(){
    // freopen("INP.TXT","r",stdin);
    // freopen("OUT.TXT","w",stdout);
    int n;
    cin>>n;
    double x,y;
    cin>>x>>y;
    cout<<tichphan(x,y,n);
}