#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    while(scanf("%d",&n)!= EOF){
        if(n == 0)return 0;
        int ans = 0;
        int nowsum = 0;
        for(int i =0;i<n;i++){
            int k;
            scanf("%d",&k);
            nowsum = max(k,nowsum+k);
            ans = max(ans,nowsum);
        }
        if(ans == 0)printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",ans);        
    }
}

// int main(){
//     int n;
//     while(scanf("%d",&n) != EOF){
//         if(n==0)return 0;
//         vector<int> v(n+1,0);
//         for(int i =1;i<=n;i++){
//             int k;
//             scanf("%d",&k);
//             v[i] = v[i-1]+k;
//         }
//         int ans = 0;
//         for(int i =0;i<n;i++){
//             for(int j = i+1;j<=n;j++){
//                 ans = max(ans,v[j]-v[i]);
//             }
//         }
//         if(ans == 0)printf("Losing streak.\n");
//         else printf("The maximum winning streak is %d.\n",ans);
//     }
// }
