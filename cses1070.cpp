#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int n;
    cin>>n;
    if(n==1)cout<<1;
    else if(n==2||n==3)cout<<"NO SOLUTION";
    else{
        int odd = n;
        if((odd&1) ==0)odd--;
        while(odd>0){
            printf("%d ",odd);
            odd-=2;
        }
        odd = n;
        if(odd&1==1)odd--;
        while(odd>0){
            printf("%d",odd);
            if(odd !=2)printf(" ");
            odd-=2;
        }
        return 0;
    }
}
