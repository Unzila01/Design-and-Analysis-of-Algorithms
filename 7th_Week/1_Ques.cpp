/*
After end term examination, Akshay wants to party with his friends. All his friends are living as paying guest and it has been decided to first gather at Akshay’s house and then move towards party location. The problem is that no one knows the exact address of his house in the city. Akshay as a computer science wizard knows how to apply his theory subjects in his real life and came up with an amazing idea to help his friends. He draws a graph by looking in to location of his house and his friends’ location (as a node in the graph) on a map. He wishes to find out shortest distance and path covering that distance from each of his friend’s location to his house and then whatsapp them this path so that they can reach his house in minimum time. Akshay has developed the program that implements Dijkstra’s algorithm but not sure about correctness of results. Can you also implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of Nodes: ";
    cin>>n;
    int graph[20][20];
    cout<<"Enter Matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    
    int distance[20];
    int sssp[20];

    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        sssp[i]=false;
    }

    distance[0]=0;

    int c=0;
    while(c<n-1){
        int min=INT_MAX;
        int dest=0;
        for(int i=0;i<n;i++){
            if(sssp[i]==false && distance[i]<min){
                min=distance[i];
                dest=i;
            }
        }
        sssp[dest]=true;

        for(int i=0;i<n;i++){
            if(graph[dest][i] && sssp[i]==false && distance[dest]+graph[dest][i]<distance[i] ){
                distance[i]=distance[dest]+graph[dest][i];
            }
        }
        c++;
    }

    for(int i=1;i<n;i++){
        cout<<i+1<<"-"<<distance[i]<<"  \n";
    }
}