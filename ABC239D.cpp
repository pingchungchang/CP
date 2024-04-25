#include <bits/stdc++.h>
using namespace std;

bool isp(int k){
    for(int i = 2;i*i<=k;i++){
        if(k%i == 0)return false;
    }
    return true;
}
bool check(int k,int a,int b){
    for(int i = a;i<=b;i++){
        if(isp(k+i))return true;
    }
    return false;
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i = a;i<=b;i++){
        bool flag = true;
        if(!check(i,c,d)){
            cout<<"Takahashi";
            return 0;
        }
    }
    cout<<"Aoki";
    return 0;
}