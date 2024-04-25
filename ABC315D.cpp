#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2020;
int col[mxn][26],row[mxn][26];
bool del[mxn][mxn];
string s[mxn];
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char c;
			cin>>c;
			s[i] += c;
			row[i][c-'a']++;
			col[j][c-'a']++;
		}
	}
	queue<int> q;
	for(int i = 0;i<n;i++){
		if(*max_element(row[i],row[i]+26) == m)q.push(i);
	}
	for(int i = 0;i<m;i++){
		if(*max_element(col[i],col[i]+26) == n)q.push(n+i);
	}
	while(!q.empty()){
		while(!q.empty()){
			auto now = q.front();
			//cout<<now<<endl;
			q.pop();
			if(now>=n){
				now -= n;
				for(int i = 0;i<n;i++){
					char c = s[i][now];
					if(c == '.')continue;
					row[i][c-'a']--;
					s[i][now] = '.';
				}
				memset(col[now],0,sizeof(col[now]));
			}
			else{
				for(int i = 0;i<m;i++){
					char c = s[now][i];
					if(c == '.')continue;
					col[i][c-'a']--;
					s[now][i] = '.';
				}
				memset(row[now],0,sizeof(row[now]));
			}
		}
		for(int i = 0;i<m;i++){
			int cnt = 0;
			for(int j =0;j<26;j++)if(col[i][j])cnt++;
			if(cnt == 1&&*max_element(col[i],col[i]+26)>1)q.push(i+n);
		}
		for(int i = 0;i<n;i++){
			int cnt = 0;
			for(int j = 0;j<26;j++)if(row[i][j])cnt++;
			if(cnt == 1&&*max_element(row[i],row[i]+26)>1)q.push(i);
		}
		//for(int i = 0;i<n;i++)cout<<s[i]<<endl;
	}
	int ans = 0;
	for(auto &i:s)for(auto &j:i)if(j != '.')ans++;
	cout<<ans;
}
