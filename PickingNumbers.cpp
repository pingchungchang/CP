#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[N];
    unordered_map<int, int> m;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
        m[arr[i]] += 1;
    }
    int max = 1;
    for (int i = 0; i < N;i++){
        if(m.count(arr[i]+1) !=0){
            if(max<m[arr[i]+1]+m[arr[i]]) max = m[arr[i]+1]+m[arr[i]];
        }
        if(m.count(arr[i]-1) !=0){
            if(max<m[arr[i]-1]+m[arr[i]]) max = m[arr[i]-1]+m[arr[i]];
        }
        if(max<m[arr[i]]) max = m[arr[i]];
    }
    cout << max;
}