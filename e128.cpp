#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0) return 0;
        int k = sqrt(n);
        if(k*k==n){
            // cout<<"s";
            if(k&1) printf("%d %d\n",1,k);
            else printf("%d %d\n",k,1);
        }
        else{
            if((k+1)*(k+1)+k*k+1 <=2*n){
                // cout<<n<<k<<k+1;
                if((k+1)&1==1) printf("%d %d\n",(k+1)*(k+1)-n+1,k+1);
                else printf("%d %d\n",k+1,(k+1)*(k+1)-n+1);
            }
            else{
                // cout<<"t";
                if(k&1==1) printf("%d %d\n",n-k*k,k+1);
                else printf("%d %d\n",k+1,n-k*k);
            }
        }
    }
}