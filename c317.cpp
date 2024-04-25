#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int x,a,b;
        cin>>x>>a>>b;
        if(a<b){
            int k = b;
            b = a;
            a = k;
        }
        if(x%a == 0){
            cout<<x/a<<endl;
            continue;
        }
        int biggest = x/a;
        int ans = -1;
        for(int j = biggest;j>=0;j--){
            if((x-a*j)%b == 0){
                ans = j+(x-a*j)/b;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
