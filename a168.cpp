#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	int n,d;
	cin>>n>>d;
	int k = 0,ans = 0;
	for(int i = 0;i<n;i++){
		int arr[3];
		int h=0,l = INT_MAX;
		for(int j = 0;j<3;j++){
			cin>>arr[j];
			h = max(arr[j],h);
			l = min(arr[j],l);
		}
		if(h-l>=d){
			ans += (arr[0]+arr[1]+arr[2])/3;
			k++;
		}
	}
	cout<<k<<' '<<ans;
	return 0;
}

