#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
int cur_sum;
int cur_min = 100000;


vector<vector<int> >check(13, vector<int> (13, 0));

/*{{0000, 1971,2868,2102,2368,0420,2377,629,1866,2419,2417,2249},
{1971,0000,0670,0367,0341,2651,1001,0703,2789,2090,2006,0350},
{},
{},
{}
,
};
*/


void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        int x=0;
        string cur_i, cur_j;
        while (getline(file, cur_i)) {
            int y=0;
            istringstream this_round(cur_i);
            string cur_j;      
            while (getline(this_round, cur_j, ' ')) {
                check[x][y]=stoi(cur_j);
                cout<<cur_j<<" ";
                y+=1;
            }
            cout<<endl;
            x+=1;
        }
    }
}
 
void display(int a[], int n) {
    cur_sum=0;
    int j=0;
    for (int i = 0; i < n; i++) {
        if (i==0) cur_sum+=check[0][a[i]];
        else cur_sum+=check[a[i-1]][a[i]];
        if (i==10) cur_sum+=check[a[i]][0];
    }
    if (cur_sum<=cur_min){
        cur_min=cur_sum;
        cout<<cur_min<<endl;
    }
}
 
void findPermutations(int a[], int n) {
    sort(a, a + n);
    do display(a, n);
    while (next_permutation(a, a + n));
}
 
int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10,11};
    int n = sizeof(a) / sizeof(a[0]);
    readFile("Day_8.txt");
    findPermutations(a, n);
    cout<<"done"<<endl;
    cout<<cur_min<<endl;
    return 0;
}