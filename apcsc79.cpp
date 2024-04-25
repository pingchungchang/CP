#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

deque<int> dq;
bool isempty(){
	if(dq.empty()){
		cout<<"error\n";
		return true;
	}
	else return false;
}
int main(){
	io
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int k;
			cin>>k;
			dq.push_back(k);
		}
		else if(t ==2){
			int k;
			cin>>k;
			dq.push_front(k);
		}
		else if(t == 3){
			if(!isempty())cout<<dq.back()<<'\n';
		}
		else if(t == 4){
			if(!isempty())cout<<dq.front()<<'\n';
		}
		else if(t == 5){
			if(!isempty())dq.pop_back();
		}
		else if(t == 6){
			if(!isempty())dq.pop_front();
		}
		else if(t == 7)cout<<dq.size()<<'\n';
	}
	return 0;
}

