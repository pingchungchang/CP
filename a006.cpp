#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int x = b*b-4*(a*c);
    if(x<0){
        cout<<"No real root";
    }
    else if(x == 0){
        cout<<"Two same roots x="<<-b/(2*a);
    }
    else{
        int x0=(int)x;
        int x1=(-b+sqrt(x))/(2*a);
        int x2 = (-b-sqrt(x))/(2*a);
        cout<<"Two different roots x1="<<max(x1,x2)<<" , x2="<<min(x1,x2);
    }
    cout<<endl;
}
