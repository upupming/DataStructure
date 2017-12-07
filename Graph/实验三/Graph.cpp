#include <iostream>
#include <vector>
#include "Graph.h"

int main(){
    cout << "Building graph..." ;
    vector<string> eles = { "v0", "v1", "v2", "v3", "v4", "v5", "v6" };
    vector<vector<int>> matrix = {  { 0, 1, 1, 0, 0, 0, 0 },
                                    { 1, 0, 0, 1, 0, 0, 0 },
                                    { 1, 0, 0, 0, 0, 1, 0 },
                                    { 0, 1, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 1, 0 },
                                    { 0, 0, 1, 0, 1, 0, 1 },
                                    { 0, 0, 0, 0, 0, 1, 0 },
                                  };
    Graph<string> g(eles, matrix);

    cout << endl << "DFS result is : " << endl;
    g.DFS();
    cout << "DFS non-recursively, result is : " << endl;
    g.DFS();

    cout << endl << "BFS result is : " << endl;
    g.BFS();

    return 0;
}
