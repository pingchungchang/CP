#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        float total = 0;
        float avg = 0;
        for(int i = 0;i<n;i++){
            cin>>avg;
            total += avg;
        }
        avg = total/n;
        if(avg>59)cout<<"no\n";
        else cout<<"yes\n";
    }
}
