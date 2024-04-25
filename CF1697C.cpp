#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
vector<vector<int>> bit;

void modify(int r,int c,int v){
	for(;c<=n;c += c&-c)bit[r][c]+=v;
	return;
}
int getval(int r,int s,int e){
	int returns = 0;
	for(;e>0;e -= e&-e)returns += bit[r][e];
	s--;
	for(;s>0;s -= s&-s)returns -= bit[r][s];
	return returns;
}
void solve(){
	cin>>n;
	set<int> a;
	set<int> b;
	set<int> c;
	bit = vector<vector<int>>(3,vector<int>(n+1,0));
	string s,t;
	cin>>s>>t;
	for(int i = 1;i<=n;i++){
		if(s[i-1] == 'a'){
			a.insert(i);
		}
		else if(s[i-1] == 'b')b.insert(i);
		else c.insert(i);
		modify(s[i-1]-'a',i,1);
	}
	bool flag = true;
	for(int i = 1;i<=n;i++){
//		cout<<s<<',';
//		cout<<flag;
		if(s[i-1] == t[i-1])continue;
		else if(s[i-1] == 'a'&&t[i-1] == 'b'){
			auto pos = b.upper_bound(i);
			if(pos == b.end()){
				flag = false;
				continue;
			}
			if(getval(0,i,*pos) == *pos-i){
				swap(s[i-1],s[*pos-1]);
			}
			else{
				flag = false;
			}
			a.insert(*pos);
			modify(0,*pos,1);
			b.erase(pos);
		}
		else if(s[i-1] == 'b'&&t[i-1] == 'c'){
			auto pos = c.upper_bound(i);
			if(pos == c.end()){
				flag = false;
				continue;
			}
			if(getval(1,i,*pos) == *pos-i){
				swap(s[i-1],s[*pos-1]);
			}
			else{
				flag = false;
			}
			b.insert(*pos);
			modify(1,*pos,1);
			c.erase(pos);
		}
		else flag = false;
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

