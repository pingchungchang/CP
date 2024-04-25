#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    ld total = 0;
    for(int i = 0;i<n;i++){
        for(int j= i+1;j<n;j++){
            ld tmp = 0;
            for(int k = 1;k<=arr[i];k++){
                if(k>arr[j])tmp += arr[j];
                else tmp += k-1;
            }
            total += tmp/(arr[i]*arr[j]);
        }
    }
	fesetround(FE_TONEAREST);
	cout<<fixed<<setprecision(6)<<nearbyint(total*1e6)/1e6;
}
