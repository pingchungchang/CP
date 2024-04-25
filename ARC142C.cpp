#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int f(int a,int b){
	
	cout<<"? "<<a<<' '<<b<<endl;
	int returns;
	cin>>returns;
	return returns;
}
int main(){
	int n;
	cin>>n;
	int d1[n+1] = {};
	int d2[n+1] = {};
	for(int i = 3;i<=n;i++){
		d1[i] = f(1,i);
		d2[i] = f(2,i);
	}
	int md = INT_MAX;
	for(int i = 3;i<=n;i++){
		md = min(md,d1[i]+d2[i]);
	}
	int arr[n+1] = {};
	for(int i = 3;i<=n;i++){
		if(d1[i]+d2[i] == md){
			arr[d1[i]] = i;
		}
	}
	bool flag = true;
	for(int i = 1;i<md;i++){
		if(arr[i] == 0)flag = false;
	}
	if(flag&&md == 3&&f(arr[1],arr[2]) != 1)flag = false;
	if(flag)cout<<"! "<<md<<endl;
	else cout<<"! 1"<<endl;
}

