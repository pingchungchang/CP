#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


bitset<200005> done;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pii arr[n*2];
	for(auto &i:arr){
		char c;
		cin>>c;
		if(c == '+')i.fs = i.sc = 1;
		else{
			int k;
			cin>>k;
			i.fs = -1,i.sc = k;
		}
	}
	int pre = 0;
	for(auto &i:arr){
		pre += i.fs;
		if(pre<0){
			cout<<"NO\n";
			return 0;
		}
	}
	/*
	for(int i = 1;i<n*2;i++){
		if(arr[i].fs == arr[i-1].fs&&arr[i].fs == -1&&arr[i-1].sc>arr[i].sc){
			cout<<"NO\n";
			return;
		}
	}

   */
	set<int> st;
	int pos[n+1] = {};
	for(int i = 0;i<n*2;i++){
		if(arr[i].fs == 1)st.insert(i);
		else pos[arr[i].sc] = i;
	}
	for(int i = 1;i<=n;i++){
		auto it = --st.upper_bound(pos[i]);
		arr[*it].sc = i;
		st.erase(it);
	}
	priority_queue<int,vector<int>,greater<int>> pq;
	for(auto &i:arr){
		//cout<<i.fs<<':'<<i.sc<<'\n';
		if(i.fs == 1)pq.push(i.sc);
		else{
			if(pq.top() != i.sc){
				cout<<"NO\n";
				return 0;
			}
			pq.pop();
		}
	}
	cout<<"YES\n";
	for(auto &i:arr)if(i.fs == 1)cout<<i.sc<<' ';
	return 0;
}
