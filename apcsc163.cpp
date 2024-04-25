#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int two = 0;
	int three = 0;
	for(int i = 0;i<n-1;i++){
		if(arr[two]+arr[two+1]<arr[i]+arr[i+1])two = i;
		if(i+2<n&&arr[three]+arr[three+1]+arr[three+2]<arr[i]+arr[i+1]+arr[i+2]){
			three = i;
		}
	}
	int a = arr[two]+arr[two+1];
	if(n== 2){
		cout<<a/__gcd(a,2)<<' '<<(a == 0?1:2/__gcd(a,2));
	}
	else{
		int b = arr[three]+arr[three+1]+arr[three+2];
		if(b*2>a*3){
			cout<<b/__gcd(b,3)<<' '<<(b == 0?1:3/__gcd(b,3));
		}
		else cout<<a/__gcd(a,2)<<' '<<(a == 0?1:2/__gcd(a,2));
	}
}

