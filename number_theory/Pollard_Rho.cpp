#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int gcd(int a, int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    int r=a%b;
    while(r){
        a=b;b=r;
        r=a%b;
    }
    return b;
}
void Pollard_Rho(int n){
    srand((unsigned)time(NULL));
    int x=(int)((float(rand())/RAND_MAX)*(n-1));
    int i=1,k=2,y=x,m=n,d=1;
    cout<<'x'<<i<<'='<<x<<endl;
    while(m--){
        i++;
        x=(x*x-1)%n;
        cout<<'x'<<i<<'='<<x<<endl;
        d=gcd(y-x,n);
        if(d!=1&&d!=n){
            cout<<d<<' ';
            break;
        }
        if(i==k){
            y=x;
            k=k*2;
        }
    }
}
int main(){
    int n;
	cout<<"please input a positive number n=";
	cin>>n;
	Pollard_Rho(n);
	return 0;
}
