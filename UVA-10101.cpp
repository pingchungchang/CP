#include <bits/stdc++.h>
#include <stoi>


//fail

using namespace std;
int main(){
    string s;
    vector<int> numbers = {2,1,2,2};
    vector<string> name = {""," shata"," hajar"," lakh"," kuti"};
    int id = 0;
    while(cin>>s){
        id ++;
        cout<<id<<". ";
        int now = s.size();
        int x = 0;
        string ans;
        while(now>0){
            string nowindex;
            for(int i = 1;i<=numbers[x%5];i++){
                if(now == 0) break;
                now--;
                nowindex = s[now]+nowindex;
            }
            if(stoi(nowindex) == 0){
                x++;
                continue;
            }
            else{
                nowindex = to_string(stoi(nowindex));
            }
            nowindex += name[x%5];
            if(x%5 != 0){
                ans = " "+ans;
            }
            ans = nowindex+ans;
            x++;
        }
        cout<<ans<<endl;
    }
}
//10000000
//100000
//1000
//100
//1
//45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58
