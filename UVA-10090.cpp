#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0)return 0;
        int a,b;
        int pa,pb;
        cin>>pa>>a>>pb>>b;
        double aa = (double)pa/a;
        double ab = (double)pb/b;
        int na=0,nb=0;
        // cout<<aa<<' '<<ab;
        if(aa>=ab){
            for(int i = n/b;i>=0;i--){
                if((n-i*b)%a==0){
                    na = (n-i*b)/a;
                    nb = i;
                    break;
                }
            }
        }
        else{
            for(int i = n/a;i>=0;i--){
                if((n-i*a)%b==0){
                    na = i;
                    nb = (n-i*a)/b;
                    break;
                }
            }
        }
        if(na*a+nb*b==n){
            printf("%d %d\n",na,nb);
        }
        else printf("failed\n");
    }
}