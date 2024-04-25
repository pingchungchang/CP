#include <bits/stdc++.h>
using namespace std;

#define f(i,j,k) for(int i = j;i<k;i++)


int main(){
    int n, cnt=0;
    while(cin>>n){
        cnt++;
        long long cargo[18], maxprod=0;
        f(i,0,n) cin>>cargo[i];
        f(i,0,n){
            int prod=1;
            f(j,0,n-i) prod*=cargo[i+j];
            if(prod>maxprod) maxprod=prod;
        }
        if(maxprod<0) cout<<"Case #"<<cnt<<": The maximum product is "<<0<<"."<<endl<<endl;
        else cout<<"Case #"<<cnt<<": The maximum product is "<<maxprod<<"."<<endl<<endl;
    }
}







/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    int ans = arr[0];
    for(int i = 1;i<n;i++){
        arr[i]+= max(0,arr[i-1]);
        ans = max(ans,arr[i]);
    }
    cout<<ans;
}
*/
