#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int n;
bool f(int val){
	vector<int> arr;
	for(int i = 0;i<n;i++){
		if(v[i].second>=val-arr.size()-1&&v[i].first>=arr.size()){
			arr.push_back(i);
		}
	}
	if(arr.size()>=val)return true;
	else return false;
}
void solve(){
	cin>>n;
	v = vector<pair<int,int>>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].second>>v[i].first;
	}
	int l = 0;
	int r = n;
	while(l != r){
		int mid = (l+r+1)/2;
		if(f(mid)){
			l = mid;
		}
		else r = mid-1;
	}
	cout<<r<<'\n';	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();

}
