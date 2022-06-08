/*
Assume that a project of road construction to connect some cities is given to your friend. Map of these cities and roads which will connect them (after construction) is provided to him in the form of a graph. Certain amount of rupees is associated with construction of each road. Your friend has to calculate the minimum budget required for this project. The budget should be designed in such a way that the cost of connecting the cities should be minimum and number of roads required to connect all the cities should be minimum (if there are N cities then only N-1 roads need to be constructed). He asks you for help. Now, you have to help your friend by designing an algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of Nodes: ";
    cin>>n;
    int graph[20][20];
    cout<<"Enter matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    
    int parent[20];
    int key[20];
    bool mst[20];

    for(int i=0;i<n;i++){
        parent[i]=-1;
        key[i]=INT_MAX;
        mst[i]=false;
    }

    parent[0]=-1;
    key[0]=0;

    int c=0;
    while(c<n-1){
        int min=INT_MAX;
        int dest=0;
        for(int i=0;i<n;i++){
            if(mst[i]==false && key[i]<min){
                min=key[i];
                dest=i;
            }
        }
        mst[dest]=true;

        for(int i=0;i<n;i++){
            if(graph[dest][i] && mst[i]==false && graph[dest][i]<key[i]){
                parent[i]=dest;
                key[i]=graph[dest][i];
            }
        }
        c++;
    }

    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<"  \n";
    }
}