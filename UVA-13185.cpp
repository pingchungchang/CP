#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int sum = 0;
        int k;
        cin>>k;
        for(int j= 0;j<k;j++){
            if(k%i == 0)sum += k;
        }
        if(k==sum)cout<<"perfect\n";
        else if(k<sum)cout<<"abundant\n";
        else cout<<"deficient\n";
    }
}