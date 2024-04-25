#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        int ten = 1;
        int ans = 0;
        while(ten<=a){
            for(int k = 1;k<a/ten%10;k++){
                ans += k;
            }
            ans += (a/ten%10)*(a%ten+1);
            ten *=10;
        }
        if(ans%3) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

