#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a%2==0) a++;
        if(b%2==0)b--;
        printf("Case %d: %d\n",i+1,(a+b)*((b-a)/2+1)/2);
    }
}
