#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n == 0) return 0;
        double s = sqrt(n);
        int k = s;
        if(s-k==0){
            printf("yes\n");
        }
        else printf("no\n");
    }
}