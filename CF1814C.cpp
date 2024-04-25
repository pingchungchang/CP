#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

void solve(){
    ll n,s1,s2;
    cin>>n>>s1>>s2;
    bool flag = false;
	if(s1>s2){
		swap(s1,s2);
		flag = true;
	}
	pll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
		arr[i].sc = i+1;
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	vector<int> a,b;
	for(auto &i:arr){
		if(s1*i.fs*(a.size()+1)<=s2*i.fs*(b.size()+1)){
			a.push_back(i.sc);
		}
		else b.push_back(i.sc);
	}
	if(flag)swap(a,b);
	cout<<a.size()<<' ';for(auto &i:a)cout<<i<<' ';cout<<'\n';
	cout<<b.size()<<' ';for(auto &i:b)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
