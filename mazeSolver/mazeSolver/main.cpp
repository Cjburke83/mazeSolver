//
//  main.cpp
//  mazeSolver
//
//  Created by Connor Burke on 8/3/17.
//  Copyright © 2017 Connor Burke. All rights reserved.
//  UIN: 323002113 Sec: 201
//

#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <list>
#include <cmath>
#include "adjacencyMatrix.h"

std::vector<int> readFile(std::string filename) {
    std::ifstream in(filename);
    std::vector<int> cont((std::istream_iterator<int>(in)), std::istream_iterator<int>());
    return cont;
}

std::vector<int> fourDirections(std::vector<int> &vec, int j) {
    std::vector<int> new_vec;
    for(int i=j;i<j+4;i++) {
        new_vec.push_back(vec.at(i));
    }
    return new_vec;
}

std::vector< std::vector<int> > joinVecs(std::vector<int> &vec) {
    std::vector< std::vector<int> > vec_directions;
    std::vector<int> vec_temp;
    for(int i=1;i<vec.size();i=i+4) {
        vec_temp = fourDirections(vec, i);
        vec_directions.push_back(vec_temp);
    }
    return vec_directions;
}

void insertEdges(std::vector< std::vector<int> > &vec_directions,
    AdjacencyMatrix &adjMat, int numRoom) {
    for(int i=0;i<vec_directions.size();i++) {
        if (vec_directions.at(i).at(0) == 1) {
            adjMat.add_edge(i, i-(sqrt(numRoom)));
        }
        if (vec_directions.at(i).at(1) == 1) {
            adjMat.add_edge(i, i+1);
        }
        if (vec_directions.at(i).at(2) == 1) {
            adjMat.add_edge(i, i+(sqrt(numRoom)));
        }
        if (vec_directions.at(i).at(3) == 1) {
            adjMat.add_edge(i, i-1);
        }
    }
}

std::vector<char> pathView(std::vector<int> &path) {
    std::vector<char> visPath;
    for(int i=0;i<path.size();i++) {
        visPath.push_back('X');
    }
    for(int i=0;i<path.size();i++) {
        int spot = path.at(i);
        visPath.at(spot) = 'O';
    }
    return visPath;
}

int displayMenu() {
    std::cout << "MENU:" << std::endl;
    std::cout << "1: display adjacency matrix" << std::endl;
    std::cout << "2: print length of exit path found" << std::endl;
    std::cout << "3: print vertices on exit path" << std::endl;
    std::cout << "4: display rooms visited" << std::endl;
    std::cout << "0: exit the program" << std::endl;
    int selection;
    std::cout << "Selection: ";
    std::cin >> selection;
    std::cout << std::endl;
    return selection;
}

int main() {
    std::cout << "Enter filename: "; //ask for file
    std::string filename;
    std::cin >> filename; //store filename
    std::vector <int> vec;
    vec = readFile(filename); //read file into a vector
    
    int numRoom = vec.at(0); //store the number of rooms
    //std::cout << numRoom << std::endl;
    std::vector< std::vector<int> > vec_directions = joinVecs(vec); //split original vector
    
    // use to check to see if vec_direction are correct
    /*
    for(int i=0;i<vec_directions.size();i++) {
        std::cout << std::endl;
        for(int j=0;j<4;j++) {
            std::cout << vec_directions.at(i).at(j) << " ";
        }
    }
    */
    
    AdjacencyMatrix am(numRoom); // create adjacency matrix
    //std::cout << "loc...." << std::endl;
    insertEdges(vec_directions, am, numRoom); // insert the edges into the matrix
    //std::cout << "loc...." << std::endl;
    std::vector<int> path = am.dfs(0, numRoom); // find the path
    //std::cout << "loc...." << std::endl;
    
    //not working rn
    
    //std::vector<char> visPath = pathView(path); // create visualiztion of rooms visited
    //std::cout << "loc...." << std::endl;

    
    int selection = displayMenu();
    while(selection != 0) {
        if (selection == 1) {
            am.display();
            std::cout << std::endl;
            std::cout << std::endl;
        }
        if (selection == 2) {
            std::cout << "Length of exit path: " << path.size();
            std::cout << std::endl;
            std::cout << std::endl;
        }
        if (selection == 3) {
            std::cout << "Exit path taken: ";
            for(int i=0;i<path.size();i++) {
                std::cout << path.at(i) << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        if (selection == 4) {
            std::cout << "NA " << std::endl;
            
            // not working rn
            
            /*
             for(int i=0;i<visPath.size();i++) {
                if(i%4==0 && i!=0) {
                    std::cout << std::endl;
                }
                std::cout << visPath.at(i) << " ";
            }
             */
            std::cout << std::endl;
            std::cout << std::endl;
        }
        if (selection == 0) {
            return 0;
        }
        selection = displayMenu();
    }
    return 0;
}
