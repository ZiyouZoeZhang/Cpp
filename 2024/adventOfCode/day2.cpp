#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;

bool check(vector<int> v){
    bool a = true, inc=true, dec=true;
    FOR(i, 1, v.size()){
        if (!((max(v[i], v[i-1])-min(v[i],v[i-1])>=1)&&(max(v[i], v[i-1])-min(v[i],v[i-1])<=3))){
            a=false;
            break;
        }
    }
    if (!a) return false;
    FOR(i, 1, v.size()){
        if (v[i]>=v[i-1]){
            dec = false;
        }
        if (v[i]<=v[i-1]){
            inc = false;
        }
    }
    if (!dec && !inc){
        return false;
    }
    return true;
}

int main() {

    freopen("/Users/zoezhang/Documents/Home/C/2024/adventOfCode/day2.txt", "r", stdin);


    ll sum = 0;
    string line;

    while (getline(cin, line)) {
        vector<int> num;
        stringstream ss(line);
        int number;

        while (ss >> number) {
            num.push_back(number);
        }

        FOR(i, 0, num.size()){
            vector<int> num2 = num;
            num2.erase(num2.begin()+ i);
            if (check(num2)) {
                sum++; break;
            }
        }
    }

    cout<<sum<<endl;
}



    /*
    ll sum = 0;
    std::string line;

    while (getline(std::cin, line)) {
        vector<int> num;
        std::stringstream ss(line);
        int number;

        while (ss >> number) {
            num.push_back(number);
        }

        bool a = true, inc=true, dec=true;
        FOR(i, 1, num.size()){
            if (!((max(num[i], num[i-1])-min(num[i],num[i-1])>=1)&&(max(num[i], num[i-1])-min(num[i],num[i-1])<=3))){
                a=false;
                break;
            }
        }
        if (!a) continue;
        FOR(i, 1, num.size()){
            if (num[i]>=num[i-1]){
                dec = false;
            }
            if (num[i]<=num[i-1]){
                inc = false;
            }
        }
        if (!dec && !inc){
            continue;
        }
        sum++;
    }






        vector<int> num2 = num;

        bool ok = true;
        bool removed = false, inc = true;
        FOR(i, 1, num.size()){
            if ((!((max(num[i], num[i-1])-min(num[i],num[i-1])>=1)&&(max(num[i], num[i-1])-min(num[i],num[i-1])<=3))) || num[i-1]>=num[i]){
                if (!removed) num.erase(num.begin()+i), removed = true, i--;
                else ok = false;
            }
        }

        if (ok){
            sum++;

            cout<<"ok"<<endl;
            continue;
        }

        ok = true, removed = false;
        bool dec = true;
        FOR(i, 1, num2.size()){
            if ((!((max(num2[i], num2[i-1])-min(num2[i],num2[i-1])>=1)&&(max(num2[i], num2[i-1])-min(num2[i],num2[i-1])<=3))) || num2[i-1]<=num2[i]){
                if (!removed) num2.erase(num2.begin()+i), removed = true, i--;
                else ok = false;
            }
        }

        if (ok){
            sum++;
            cout<<"ok"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }

    cout<<sum<<endl;
}



bool check(vector<int> v){
    bool a = true, inc=true, dec=true;
    FOR(i, 1, v.size()){
        if (!((max(v[i], v[i-1])-min(v[i],v[i-1])>=1)&&(max(v[i], v[i-1])-min(v[i],v[i-1])<=3))){
            a=false;
            break;
        }
    }
    if (!a) return false;
    FOR(i, 1, v.size()){
        if (v[i]>=v[i-1]){
            dec = false;
        }
        if (v[i]<=v[i-1]){
            inc = false;
        }
    }
    if (!dec && !inc){
        return false;
    }
    return true;
    */