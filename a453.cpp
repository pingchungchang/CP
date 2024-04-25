#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int d = b*b-4*a*c;
        if(d>=0&&(int)sqrt(d)*(int)sqrt(d) - d == 0){
            printf("Yes");
        }
        else printf("No");
        if(i != n-1)printf("\n");
    }
}