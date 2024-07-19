#include <fstream> // files haha
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>
#include <queue>
#include <string>
using namespace std; 

const int no_path=100000000;

struct point{
    bool is_in;
    int distance_TYC;//from TYC to this
    vector<pair<string,int> > neighbor_path={};//from this pos to others 
};

map<string,point> all_point;

vector<vector<int> > path;

void readFile(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string from=line.substr(0,3);
            string destination="";
            string distance="";
            for (int i=0; i<line.size()-6; i+=9){
                destination=line.substr(7+i, 3);
                distance=line.substr(11+i,4);
                //addEdge(adj, from, destination, stoi(distance));
                if(all_point.find(from)!=all_point.end()){
                    if(destination=="TYC") all_point[from].distance_TYC=stoi(distance);
                    all_point[from].neighbor_path.push_back(make_pair(destination,stoi(distance)+600));
                }
                else{
                    point new_point;
                    if(from=="TYC"){
                        new_point.distance_TYC=0;
                        new_point.is_in=0;
                    }
                    else if(destination=="TYC") {
                        new_point.is_in=0;
                        new_point.distance_TYC=stoi(distance);
                    }
                    else {
                        new_point.is_in=0;
                        new_point.distance_TYC=no_path;
                    }
                    new_point.neighbor_path={};
                    new_point.neighbor_path.push_back(make_pair(destination,stoi(distance)+600));
                    all_point.insert(make_pair(from,new_point));
                }
                // cout<<destination<<endl;
                // cout<<distance<<endl;
                // cout<<from<<endl;
            }
        }
        file.close();
    }

}

void dijkstra(){
    int times = all_point.size();
    for(int i=0;i<times;i++){//dijkstra running times
        string best_pos;//this time add which
        int shortest_path=no_path;
        map<string,point>::iterator curr_pos;
        for(curr_pos=all_point.begin();curr_pos!=all_point.end();curr_pos++){
            if((!curr_pos->second.is_in)&&(curr_pos->first=="TYC"||curr_pos->second.distance_TYC<shortest_path)){
                shortest_path=curr_pos->second.distance_TYC;
                best_pos=curr_pos->first;
            }
        }
        cout<<best_pos<<endl;
        all_point[best_pos].is_in=1;
        for(int j=0;j<all_point[best_pos].neighbor_path.size();j++){
            if(!all_point[all_point[best_pos].neighbor_path[j].first].is_in||all_point[best_pos].distance_TYC+all_point[best_pos].neighbor_path[j].second<all_point[all_point[best_pos].neighbor_path[j].first].distance_TYC){
                all_point[all_point[best_pos].neighbor_path[j].first].distance_TYC=all_point[best_pos].distance_TYC+all_point[best_pos].neighbor_path[j].second;
            }
        }
    }
}

int main(){
    readFile("Day_10.txt");
    dijkstra();
    cout<<(all_point["EAR"].distance_TYC)-600;
    return 0;
}
/*
# define INF 0x3f3f3f3f 
void readFile(string filename);

// Program to find Dijkstra's shortest path using
// priority_queue in STL
 
// iPair ==> Integer Pair
typedef pair<int, int> iPair;
 
// To add an edge
void addEdge(vector<pair<string, int> > adj[], string u, string v,
             int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
 
// Prints shortest paths from src to all other vertices
void shortestPath(vector<pair<int, int> > adj[], int V,
                  int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair> >
        pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    //Looping till priority queue becomes empty (or all
    //distances are not finalized)
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        // Get all adjacent of u.
        for (auto x : adj[u]) {
            // Get vertex label and weight of current
            // adjacent of u.
            int v = x.first;
            int weight = x.second;
 
            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// Driver program to test methods of graph class
int main()
{
    int V = 9;
    vector<iPair> adj[V];
 
    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 8);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
 
    shortestPath(adj, V, 0);
 
    return 0;
}
//EAR => DEV:2694 MGE:4668 TYT:8730

void readFile(string filename){
    ifstream file(filename);
    
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string from=line.substr(0,3);
            cout<<from<<endl;
            string destination="";
            string distance="";
            for (int i=0; i<line.size()-6; i+=9){
                destination=line.substr(7+i, 3);
                distance=line.substr(11+i,4);
                //addEdge(adj, from, destination, stoi(distance));

            }
        }
        file.close();
    }
}
*/