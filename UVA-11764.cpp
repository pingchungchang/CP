#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int m;
        cin>>m;
        int a,b;
        cin>>a;
        int h=0,l=0;
        for(int j = 0;j<m-1;j++){
            cin>>b;
            if(a<b) h++;
            else if(b<a)l++;
            a=b;
        }
        printf("Case %d: %d %d\n",i,h,l);
    }
}
