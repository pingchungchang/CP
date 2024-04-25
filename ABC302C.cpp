#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int n;

int dif(string a,string b){
	int c = 0;
	for(int i = 0;i<min(a.size(),b.size());i++)if(a[i] != b[i])c++;
	return c<=1;
}

bool check(string arr[]){
	auto pre = arr[0];
	for(int i = 1;i<n;i++){
		if(!dif(arr[i-1],arr[i]))return false;
	}
	return true;
}

void solve(){
	cin>>n;
	int kk;
	cin>>kk;
	string arr[n];
	for(auto &i:arr){
		cin>>i;
	}
	sort(arr,arr+n);
	if(check(arr)){
		cout<<"Yes";
		return;
	}
	while(next_permutation(arr,arr+n)){
		if(check(arr)){
			cout<<"Yes";
			return;
		}
	}
	cout<<"No";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
