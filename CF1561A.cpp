#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n;
        cin>>n;
        int arr[n];
        int done[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
            done[i]=arr[i];
        }
        sort(done,done+n);
        int ans =0;
        int fine = 1;
        while(true){
            for(int i =0;i<n;i++){
                if(arr[i]!= done[i])break;
                if(arr[i]==done[i]&&i == n-1)fine =0;
            }
            if(fine==0)break;
            ans++;
            if(ans&1==1){
                for(int i =0;i<=n-2;i+=2){
                    if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
                }
            }
            else{
                for(int i =1;i<=n-2;i+=2){
                    if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
                }
            }
        }
        cout<<ans<<'\n';
    }
}
//nope
