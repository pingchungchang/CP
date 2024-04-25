#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = INT_MAX;
    int tens = 10;
    while(n>tens){
        tens *=10;
    }
    tens/=10;
    while(tens!=1){
        if((n%tens)%2 == 1){
            printf("%d",max)
        }
    }
}