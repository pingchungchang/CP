#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long arr[15] = {-1,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
    while(scanf("%d",&n)!= EOF){
        if(n ==0)return 0;
        printf("%lld\n",arr[n]);
    }
}
// int main(){
//     long long n;
//     while(scanf("%lld",&n)!= EOF){
//         if(n ==0)return 0;
//         long long done = 0;
//         long long ans = 0;
//         for(long long i = n+1;i<LONG_LONG_MAX;i++){
//             long long now = 1;
//             long long nums = 2*n;
//             for(long long j =0;j<n;j++){
//                 now += (i-1)%nums;
//                 now = now%nums;
//                 if(now == 0)now = nums;
//                 if(now<=n)break;
//                 if(now == nums){
//                     now = 1;
//                 }
//                 nums--;
//                 if(j == n-1)done = 1;
//             }
//             if(done) ans = i;
//             if(done)break;
//         }
//         printf("%lld\n",ans);
//     }
// }