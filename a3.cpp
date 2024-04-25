#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct DATE{
	int month,day,year;
	DATE(string s){
		month = stoi(s.substr(0,2));
		day = stoi(s.substr(2,2));
		year = stoi(s.substr(4,4));
	}
	const bool operator<(const DATE &b)const{
		if(year != b.year)return year<b.year;
		if(month != b.month)return month<b.month;
		else return day<b.day;
	}
	string str(){
		string ta = to_string(month),tb = to_string(day),tc = to_string(year);
		if(ta.size()<2)ta = "0"+ta;
		if(tb.size()<2)tb = "0"+tb;
		while(tc.size()<4)tc = "0"+tc;
		return ta+tb+tc;
	}
};
vector<DATE> v;

bool isleap(int k){
	if(k%400 == 0)return true;
	if(k%100 == 0)return false;
	if(k%4 == 0)return true;
	return false;
}

bool check(DATE now){
	if(now.month>12)return false;
	if(now.month == 2){
		if(now.day>29)return false;
		if(now.day == 29)if(isleap(now.year))return true;else return false;
		return true;
	}
	if(now.month == 1||now.month == 3||now.month == 5||now.month == 7||now.month == 8||now.month == 10||now.month == 12){
	if(now.day<=31)return true;
	else return false;

	}
	else{
		if(now.day<30)return true;
		else return false;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<100;i++){
		for(int j = 1;j<100;j++){
			string ta = to_string(i),tb = to_string(j);
			if(ta.size()<2)ta = "0"+ta;
			if(tb.size()<2)tb = "0"+tb;
			DATE tmp(ta+ta+tb+tb);
			if(check(tmp))v.push_back(tmp);
		}
	}
	sort(v.begin(),v.end());
	string in;
	cin>>in;
	DATE now(in);
	auto it = lower_bound(v.begin(),v.end(),now);
	cout<<it->str();
}
