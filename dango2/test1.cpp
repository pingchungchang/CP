#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 550;
string arr[mxn];
bitset<mxn> done[mxn];
int N,M;
vector<pii> dir;

bool check(int a,int b,int c,int d,int e,int f){
	pii pos[] = {pii(a,b),pii(c,d),pii(e,f)};
	string s;
	for(auto &i:pos){
		if(i.fs<0||i.sc<0||i.fs>=N||i.sc>=M)return false;
		s += arr[i.fs][i.sc];
	}
	if(s == "GWP"||s == "PWG"){
		for(auto &i:pos){
			if(done[i.fs][i.sc])return false;
			done[i.fs][i.sc] = true;
		}
		return true;
	}
	return false;
}

int main(int argc,char* argv[]){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifstream cin(argv[1]);
	cin>>N>>M;
	for(int i = 0;i<N;i++){
		cin>>arr[i];
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(check(i-1,j-1,i,j,i+1,j+1))arr[i][j] = '\\';
		}
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(check(i-1,j,i,j,i+1,j))arr[i][j] = '|';
		}
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(arr[i][j] != 'W')continue;
			if(check(i,j-1,i,j,i,j+1))arr[i][j] = '-';
		}
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(check(i-1,j+1,i,j,i+1,j-1))arr[i][j] = '/';
		}
	}
	ofstream cout((string(argv[1])+".out").c_str());
	for(auto &i:arr)cout<<i<<endl;
	return 0;
}
