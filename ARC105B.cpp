#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int tmp = arr[0];
	for(auto i:arr)tmp = gcd(tmp,i);
	cout<<tmp;
}

