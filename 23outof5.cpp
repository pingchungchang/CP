#include <bits/stdc++.h>
using namespace std;

int arr[5];
vector<vector<int>> all;
bool flag = false;
vector<int> tmp;

// #define cout fout
// ofstream fout("output.txt");
void dfs(){
    if(tmp.size() == 4){
        all.push_back(tmp);
        return;
    }
    for(int i = 0;i<3;i++){
        tmp.push_back(i);
        dfs();
        tmp.pop_back();
    }
    return;
}

bool check(){
    for(auto &i:all){
        int total = arr[0];
        for(int j = 0;j<4;j++){
            if(i[j] == 0)total += arr[j+1];
            else if(i[j] == 1)total -= arr[j+1];
            else total *= arr[j+1];
        }
        if(total == 23){
            // for(int j = 0;j<5;j++)cout<<arr[j]<<' ';for(int j = 0;j<4;j++)cout<<i[j]<<',';cout<<endl;
            return true;
        }
    }
    return false;
}

void solve(){
    for(int i = 1;i<5;i++)cin>>arr[i];
    sort(arr,arr+5);
    if(check()){
        cout<<"Possible\n";
        return;
    }
    while(next_permutation(arr,arr+5)){
        if(check()){
            cout<<"Possible\n";
            return;
        }
    }
    cout<<"Impossible\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dfs();
    while(cin>>arr[0]&&arr[0] != 0)solve();
}