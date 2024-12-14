#include <bits/stdc++.h>
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define ll long long
#define f first
//#define s second
#define pb push_back
using namespace std;


int main() {

    freopen("/Users/zoezhang/Documents/Home/C/2024/adventOfCode/day3.txt", "r", stdin);


    ll sum = 0;
    string s;
    bool yes = true;

    while (getline(cin, s)) {
        FOR(i, 0, s.size()){
            if (s.substr(i, 4) == "do()") yes = true;
            if (s.substr(i, 7) == "don't()") yes = false;
            if (s.substr(i, 4) == "mul(" && yes){
                int j=i+4;
                string a, b;
                while (s[j]>='0' && s[j]<='9' && !(s[j]=='0' && j==5)){
                    a.push_back(s[j]);
                    j++;
                    if (j==s.size()) continue;
                }
                if (s[j]==',') {
                    j++;
                    if (j==s.size()) continue;
                    while (s[j]>='0' && s[j]<='9' && !(s[j]=='0' && j==5)){
                        b.push_back(s[j]);
                        j++;
                        if (j==s.size()) continue;
                    }
                    if (s[j]==')'){
                        sum+= (stoll(a) * stoll(b));
                    } else {continue;}
                } else {continue;}
            }
        }

    }

    cout<<sum<<endl;
}
