#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int k;
    cin>>k;
    for(int i = 0;i<k;i++){
        cin>>n>>m;
        int times = 0;
        while(n>=m){
            times += n/m;
            n=n/m+n%m;
        }
        // cout<<n<<m;
        if(n == 1)cout<<times<<endl;
        else cout<<"cannot do this\n"; 
    }
}