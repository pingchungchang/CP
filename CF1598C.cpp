#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin>>n;
	multiset<int> st;
	multiset<int>tar;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		tar.insert(k);
	}
	bool flag = true;
	for(auto i:tar){
		if(st.find(i-1) != st.end()){
			st.erase(st.find(i-1));
		}
		else if(st.find(i) != st.end()){
			st.erase(st.find(i));
		}
		else flag = false;
	}
	if(flag){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
