#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int ModularExponent(int a,int m,int n){//compute a^m(mod n)
    int p=1;
    a=a%n;
    while(m>0){
        if(m%2==1) p=(p*a)%n;
        a=(a*a)%n;
        m=m/2;
    }
    return p;
}
int main(){
	int n;
	cout<<"please input a positive odd number n=";
	cin>>n;
	if(n%2==0){
		cout<<"Composite"<<endl;
		return 0;
	}

	int q=0,m=n-1,a=2;
	while(m%2==0){
		q++;m=m/2;
	}//n-1=m*2^q
	cout<<"n-1=2^"<<q<<"*"<<m<<endl;
	srand(time(NULL));
	double x=double(rand())/RAND_MAX;
	a=int(x*(n-3))+2;//a is a random number between 2 and n-1
	cout<<"a="<<a<<endl;

	int s=ModularExponent(a,m,n);
	int t=0;
	for(int i=1;i<=q;i++){
		t=(s*s)%n;
		if((s!=1)&&(s!=n-1)&&(t==1)){
			cout<<"Composite"<<endl;
			cout<<"hello world"<<endl;
			return 0;
		}
		s=t;
	}
	if(t!=1) cout<<"Composite"<<endl;
	else cout<<"Prime"<<endl;
	return 0;
}
