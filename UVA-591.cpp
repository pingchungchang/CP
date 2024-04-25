#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int times = 0;
    while(cin>>n){
        times ++;
        if(n == 0) return 0;
        int sum = 0;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        int ans = 0;
        sum = sum/n;
        for(int i = 0;i<n;i++){
            if(arr[i]>sum) ans += arr[i]-sum;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",times,ans);
    }
}
