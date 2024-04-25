#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a!=0)a=1;
    if(b!=0)b=1;
    int k = 0;
    if(((a==0||b==0)&&c==0)||(a==1&&b==1&&c==1)){
        cout<<"AND\n";
        k++;
    
    }
    if((a+b!=0&&c==1)||(a+b==0&&c==0)){
        cout<<"OR\n";
        k++;
    }
    if((a-b==0&&c==0)||(a!=b&&c==1)){
        cout<<"XOR\n";
        k++;
    }
    if(k==0)cout<<"IMPOSSIBLE\n";
}