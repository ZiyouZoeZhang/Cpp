//https://www.codingame.com/ide/puzzle/there-is-no-spoon-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    vector<vector<pair<int, int> > > coord(height, vector<pair<int, int> >(width));
    vector<vector<bool> > input(height, vector<bool>(width));
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        for (int j=0; j<width; j++){
            (line[j]=='0') ? input[i][j]=true : input[i][j]=false;
        }
    }

    for (int i=0; i<height; i++){
        int last_seen=-1;
        for (int j=width-1; j>=0; j--){
            coord[i][j].first=last_seen;
            if (input[i][j]) last_seen=j;
        }
    }
    for (int j=0; j<width; j++){
        int last_seen=-1;
        for (int i=height-1; i>=0; i--){
            coord[i][j].second=last_seen;
            if (input[i][j]) last_seen=i;
        }
    }

    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (input[i][j]){
                cout<<j<<' '<<i<<' ';
                (coord[i][j].first!=-1) ? cout<<coord[i][j].first<<' '<<i<<' ' : cout<<-1<<' '<<-1<<' ';
                (coord[i][j].second!=-1) ? cout<<j<<' '<<coord[i][j].second<<' '<<endl : cout<<-1<<' '<<-1<<' '<<endl;
            }
        }
    }
}