
#include <iostream>
#include <cstdlib>
#include "stack.h"
/*
 * Adjacency Matrix Class
 */
class AdjacencyMatrix
{
private:
    int n;
    int **adj;
    bool *visited;
public:
    AdjacencyMatrix(int n) {
        this->n = n;
        visited = new bool [n];
        adj = new int* [n];
        for (int i=0; i<n; i++) {
            adj[i] = new int [n];
            for(int j=0;j<n;j++) {
                adj[i][j] = 0;
            }
        }
    }
   
    void add_edge(int begin, int fin) { //Add Edge to Graph
        if(begin>n||fin>n||begin<0||fin<0) {
            //throw runtime error
        }
        else {
            adj[begin][fin] = 1;
        }
    }
    
    void display() { //Print the graph
        for(int i=0;i<n;i++) {
            std::cout<<std::endl;
            for(int j=0;j<n;j++) {
                std::cout<<adj[i][j]<<" ";
            }
        }
    }
    
    std::vector<int> dfs(int start, int end) { //dfs algoritm
        bool change = false;
        int visited[n];
        std::vector<int> path;
        int top = 0;
        int stack[n*2];
        for(int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        visited[start] = 1;
        stack[top] = start;
        path.push_back(start);
        while(top >= 0) {
            change = false;
            int i = stack[top];
            for(int j = 0; j < n; j++) {
                if(visited[j] == 0 && adj[i][j] == 1) {
                    visited[j] = 1;
                    top++;
                    stack[top] = j;
                    path.push_back(j);
                    if (j == end-1) {
                        return path;
                    }
                    change = true;
                    break;
                }
            }
            if(change == false) {
                top--;
            }
        }
        return path;
    }
};
