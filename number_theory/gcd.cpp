#include<iostream>
#include<stack>
using namespace std;
int egcd(int a, int b, int &x, int &y){
    stack<int> Quotient;
    cout<<"a\tb\n"<<a<<'\t'<<b<<endl;
    for(int r=a%b;r;r=a%b){
        Quotient.push(a/b);
        a=b;b=r;
        cout<<a<<'\t'<<b<<endl;
    }
    x=0;y=1;int old_x;
    cout<<"x\ty\tq\n"<<x<<'\t'<<y<<'\t'<<a/b<<endl;
    while(!Quotient.empty()){
        old_x=x;
        x=y;
        y=old_x-Quotient.top()*y;
        cout<<x<<'\t'<<y<<'\t'<<Quotient.top()<<endl;
        Quotient.pop();
    }
    return b;
}
int main(){
    int x,y,a,b;
    cin>>a>>b;
    egcd(a,b,x,y);
}
