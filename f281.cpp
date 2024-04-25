#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	io
	int c;
	cin>>c;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0;i<c;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	int l;
	cin>>l;
	int a = pq.top();
	pq.pop();
	int b = pq.top();
	pq.pop();
	int dif = l-a;
	if(b-dif>=l){
		cout<<dif;
	}
	else cout<<"You are too black!";
	return 0;
}

