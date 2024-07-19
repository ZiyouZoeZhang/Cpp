/*
USACO 2019 February Contest, Gold
Problem 3. Painting the Barn
http://www.usaco.org/index.php?page=viewproblem2&cpid=923
*/

#include <iostream>
#include <vector>
#define loop(i, s, e) for(int i = s; i < e; ++i)
using namespace std;
struct rec{int x1; int x2; int y1; int y2;};
void read_process();
//void cal_prefix();
//void print(vector<vector<int> >vec);
rec cal_largest_sum(rec first);
vector<vector<int> > nums(10 , vector<int> (10, 0)); 
vector<vector<int> > ps;
int N, K, max_x=0, max_y=0, min_x=200, min_y=200;
int area=0, area1=0, area2=0;


int main(){
    cout<<"hiii"<<endl;
    read_process();
    //cal_prefix();
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

/*
void cal_prefix(){
   ps.resize(max_x-min_x+1, vector<int> (max_y-min_y+1, 0));
    loop(x, 0, max_x-min_x){
        loop(y, 0, max_y-min_y){
            ps[x+1][y+1]=nums[x+min_x][y+min_y]+ps[x+1][y]+ps[x][y+1]-ps[x][y];
        }
    }

    //print
    loop(x, 0, ps.size()){
        loop(y, 0, ps[0].size()) cout<<ps[x][y]<<' ';
        cout<<endl;
    }

    //next
    rec temp;
    temp.x1=0, temp.x2=0, temp.y1=0, temp.y2=0;
    rec first = cal_largest_sum(temp);
    cal_largest_sum(first);

    cout<<endl<<area+area1+area2<<endl;
    return;
}

/*
rec cal_largest_sum(rec first){
    //store the location of max, and the value of max;
    //loop x, y, z
    //for y, restore max_so_far, cur_max and start
    //for z, 
    //      if one of x, y is present between x1 and x2 && z is betweeen y1 and y2 (all inlcusive), z=y2+1, return if z>y2
    //      cur_max += ps[y+1][z+1]-ps[x][z+1]-ps[y+1][z]+ps[x][z]
    //      if cur_max <0, cur_max=0, start=z
    //      else check whether cur_max>max_so_far and store first accordingly

}


rec cal_largest_sum(rec first){
    //max
    //loop left x1
    //loop right x2
    //from top to bottom y, cal sum and store in temp array
    //use kanade's algorithm
    int max_area=0;
    rec max;
    for (int i=1; i<ps.size(); ++i) {
        for (int j=i; j<ps.size(); ++j) {
            int max_so_far = 0, max_ending_here = 0, start, end;
            for (int z=1; z<ps[0].size(); z++){
                cout<<ps[j+1][z+1]<<' ';
                //cout<<"\n ps[j][z]:"<<ps[j][z]<<endl;
                //cout<<"ps[j+1][z+1]: "<<ps[j+1][z+1]<<",  ps[j+1][z]: "<<ps[j+1][z]<<",  ps[i][z+1]: "<<ps[i][z+1]<<",  ps[i][z]: "<<ps[i][z];
                //if contained in the other rect;
                //*************************************************
                /*
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
*/
