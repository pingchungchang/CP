#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n;
vector<pii> arr;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i= 0;i<n;i++){
		pii tmp;
		cin>>tmp.fs>>tmp.sc;
		arr.push_back(tmp);
	}
	if(n&1){
		cout<<"NO\n";
		return 0;
	}
	pii cen = make_pair(arr[0].fs+arr[n/2].fs,arr[0].sc+arr[n/2].sc);
	for(int i = 0;i<n/2;i++){
		if(arr[i].fs+arr[i+n/2].fs != cen.fs||arr[i].sc+arr[i+n/2].sc != cen.sc){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}
