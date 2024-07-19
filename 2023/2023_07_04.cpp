/*
USACO 2019 February Contest, Gold
Problem 3. Painting the Barn
http://www.usaco.org/index.php?page=viewproblem2&cpid=923
*/

#include <iostream>
#include <vector>
#include <limits.h>
#define loop(i, s, e) for(int i = s; i < e; ++i)
using namespace std;
struct rec{int x1; int x2; int y1; int y2;};
void read_process();
void cal_prefix();
void print(vector<vector<int> >vec);
rec cal_largest_sum(vector<vector<int> >ps, rec first);
vector<vector<int> > nums(10 , vector<int> (10, 0)); 
int N, K, max_x=0, max_y=0, min_x=200, min_y=200;
int area=0, area1=0, area2=0;


int main(){
    read_process();
    cal_prefix();
    return 0;
}

void read_process(){
    cin>>N>>K;
    loop(read, 0, N){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        max_x=max(max_x, x2), max_y=max(max_y, y2), min_x=min(min_x, x1), min_y=min(min_y, y1);
        loop(x, x1, x2){
            loop(y, y1, y2) ++nums[x][y];
        }
    }
    print(nums);
    cout<<"OK"<<endl;
    //now reducing it to 1, 0 and -1. 
    //when value==K-1, set it to 1;
    //else if it==K, set it to -1
    //else set it to 0;
    //at the same time keep a count value, counting the ones present as -1
    loop(x, min_x, max_x){
        loop(y, min_y, max_y){
            if (nums[x][y]==K) nums[x][y]=-1, ++area;
            else if (nums[x][y]==K-1) nums[x][y]=1;
            else nums[x][y]=0;
        }
    }
}

void cal_prefix(){
    vector<vector<int> > ps(max_x+1, vector<int> (max_y+1, 0));
    loop(x, min_x, max_x){
        loop(y, min_y, max_y){
            ps[x+1][y+1]=nums[x][y]+ps[x+1][y]+ps[x][y+1]-ps[x][y];
        }
    }

    //print
    loop(x, min_x, max_x+1){
        loop(y, min_y, max_y+1) cout<<ps[x][y]<<' ';
        cout<<endl;
    }

    //next
    rec temp;
    temp.x1=0, temp.x2=0, temp.y1=0, temp.y2=0;
    rec first = cal_largest_sum(ps, temp);
    cal_largest_sum(ps, first);

    cout<<endl<<area+area1+area2<<endl;
    return;
}

rec cal_largest_sum(vector<vector<int> >ps, rec first){
    //max
    //loop left x1
    //loop right x2
    //from top to bottom y, cal sum and store in temp array
    //use kanade's algorithm
    int max_area=0;
    rec max;
    for (int i=min_x; i<max_x; ++i) {
        for (int j=i; j<max_x; ++j) {
            int max_so_far = 0, max_ending_here = 0, start, end;
            for (int z=min_y; z<max_y; z++){
                cout<<ps[j+1][z+1]<<' ';
                //cout<<"\n ps[j][z]:"<<ps[j][z]<<endl;
                //cout<<"ps[j+1][z+1]: "<<ps[j+1][z+1]<<",  ps[j+1][z]: "<<ps[j+1][z]<<",  ps[i][z+1]: "<<ps[i][z+1]<<",  ps[i][z]: "<<ps[i][z];
                //if contained in the other rect;
                //*************************************************
                if (((i>=first.x1&&i<=first.x2)||(j>=first.x1&&j<=first.x2))&&(z==first.y1)){
                    max_ending_here=0, z=first.y2+1;
                    if (z>=max_y) break;
                }
                //area = ps[i][z] - ps[j][z]
                //ps[j+1][z+1]-ps[j+1][z]-ps[i][z+1]+ps[i][z]
                max_ending_here=max_ending_here+ps[j+1][z+1]-ps[j+1][z]-ps[i][z+1]+ps[i][z];
                if(max_so_far < max_ending_here) max_so_far = max_ending_here, end=z;
                if(max_ending_here < 0) max_ending_here = 0, start=z;
            }
            cout<<endl;
            if (max_so_far>max_area) max.x1=i, max.x2=j, max.y1=start, max.y2=end, max_area=max_so_far;
        }
    }
    if (area1==0) area1=max_area;
    else area2=max_area;
    return max;
}

void print(vector<vector<int> >vec){
    loop(x, min_x, max_x){
        loop(y, min_y, max_y) cout<<vec[x][y]<<' ';
        cout<<endl;
    }
    return;
}

void print_rotated(vector<vector<int> >vec){
    for(int y=max_y-1; y>=min_y; --y){
        loop(x, min_x, max_x) cout<<vec[x][y]<<' ';
        cout<<endl;
    }
    return;
}