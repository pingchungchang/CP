#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		bool ans = true;
		for(int j = i-1;j>=0;j--){
			if(j == i-a-1)break;
			if(arr[i]>arr[j])ans = false;
		}
		for(int j = i+1;j<n;j++){
			if(j == i+b+1)break;
			if(arr[i]>arr[j])ans = false;
		}
		if(ans){
			cout<<i+1<<'\n';
			return 0;
		}
	}
}

