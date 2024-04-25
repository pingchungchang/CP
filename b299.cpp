#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        int w;
        scanf("%d %d",&w,&m);
        int smallest = INT_MAX;
        for(int j =0;j<m;j++){
            int k;
            scanf("%d",&k);
            smallest = min(k,smallest);
        }
        if(w<=smallest)printf("YEEES!!! INKER!");
        else printf("NOOOO!!! JACKY XX!");
        if(i != n-1)printf("\n");
    }
}