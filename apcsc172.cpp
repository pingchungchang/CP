#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

class cmp{
	public:
		bool operator()(string a,string b){
			return a+b>b+a;
		}
};
int main(){
	io
	int n;
	cin>>n;
	priority_queue<string,vector<string>,cmp> pq;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		pq.push(s);
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
}

