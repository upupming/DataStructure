/* Adjacent list implementation of directed graph
 * just use a symmetric matrix
 * Printable is a type which has operator << and >>
 */

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

struct AdjList{
	int subscript;
	bool visited;
	// pointers to the adjacent vertices
	vector<int> adjacencies;
	int indegree, outdegree;

	AdjList(int sub, const vector<int>& adj = vector<int>(), int in = 0, int out = 0):subscript(sub), visited(false), adjacencies(adj), indegree(in), outdegree(out){}
	// 1. Destructor
	~AdjList(){}
	// 2. Copy constructor
	AdjList(const AdjList & rhs){
        subscript = rhs.subscript;
        adjacencies = rhs.adjacencies;
        indegree = rhs.indegree;    outdegree = rhs.outdegree;
	}
	// 3. Move constructor
	AdjList(AdjList && rhs){
        subscript = std::move(rhs.subscript);
        adjacencies = std::move(rhs.adjacencies);

        // for integer: Using std::move just changes an lsubscript to an xsubscript, so it is eligible for use with move constructors and move assignment operators.
        indegree = std::move(rhs.indegree);    outdegree = std::move(rhs.outdegree);
	}
	// 4. Copy assignment
	AdjList & operator= (const AdjList & rhs){
        AdjList copy = rhs;// copy constructor
        std::swap(*this, copy);// assume that swapping is implemented either with three moves or by swapping member by member, not by three copy assignments which will cause infinite loop
        return *this;
	}
	// 5. Move assignment
	AdjList & operator=(AdjList && rhs){
        subscript = std::move(rhs.subscript);
        adjacencies = std::move(rhs.adjacencies);

        // for integer: Using std::move just changes an lsubscript to an xsubscript, so it is eligible for use with move constructors and move assignment operators.
        indegree = std::move(rhs.indegree);    outdegree = std::move(rhs.outdegree);
	}

	void addAdj(int v){
        outdegree++;
        adjacencies.push_back(v);
	}
	void addAdjs(const vector<int> & adjs){
        outdegree += adjs.size();
        for(auto adj : adjs){
            adjacencies.push_back(adj);
        }
	}
};

template<typename Printable>
class Graph{
private:
    vector<Printable> vertices; // store vertices
    vector<AdjList> adjLists; // adjacency lists

    void DFS(AdjList & adj_list){
        // visit v and is adjacencies if it hasn't been visit
        if(!adj_list.visited){
            adj_list.visited = true;
            cout << vertices[adj_list.subscript] << " ";
            for(int j : adj_list.adjacencies){
                DFS(adjLists[j]);
            }
        }
    }
    void setNotVisited(){
        for(auto & adj_list : adjLists){
            adj_list.visited = false;
        }
    }
public:
    // Using adjacent matrix initialization, empty graph for default
    Graph(const vector<Printable> & vertices = vector<Printable>(),const vector<vector<int>> & adjMatrix = vector<vector<int>>()){
        this->vertices = vertices;
        int n = vertices.size();
        assert((int)adjMatrix.size() == n); // row equals elements size?
        for(int i=0; i<n; i++){
            adjLists.push_back(AdjList(i));
        }

        for(int i=0; i<n; i++){
            vector<int> adjs = adjMatrix[i];
            assert((int)adjs.size() == n); // column equals elements size?
            for(int j=0; j<n; j++){
                if(adjs[j]){ // if i->j is an edge
                    adjLists[i].addAdj(j); // fill in adjacent list, auto increase outdegree
                    adjLists[j].indegree++; // increase indegree manually
                }
            }
        }

        printList();
    }
    // Input Manually
    Graph(){
        int numOfVertices;
        cout << "Number of vertices: " ;
        cin >> numOfVertices;
        vertices = vector<Printable>(numOfVertices); // Initialize vertices
        adjLists = vector<AdjList>(numOfVertices); // Initialize lists
        for(int i=0; i<numOfVertices; i++){
            cout << "The " << i+1 << "th AdjList is : ";
            cin >> vertices[i].subscript; // initialize vertice

            int t = numOfVertices, j;
            cout << "And subscript of its adjacencies are(end with -1) : ";
            while(t--){
                cin >> j;
                if(j == -1) break; // no more adjacencies
                if(j>=0 && j <numOfVertices){
                    adjLists[i].addAdj(j); // create adjacent list, auto increase outdegree
                    adjLists[j].indegree++; // increase indegree manually
                }
            }
        }

        printList();
    }

    void printList(){
        cout << endl << "The adjList of your Graph is : " << endl;
        int m = adjLists.size();
        for(int i=0; i<m; i++){
            cout << vertices[adjLists[i].subscript] << " : ";
            int n = adjLists[i].adjacencies.size();
            for(int j=0; j<n; j++){
                cout << vertices[adjLists[i].adjacencies[j]] << " " ;
            }
            cout << endl;
        }
    }

    void DFS(){
        setNotVisited();
        int n = adjLists.size();
        for(int i=0; i<n; i++)
            DFS(adjLists[i]);
        cout << endl;
    }
    void DFS_noRecur(){
        setNotVisited();
        stack<int> s;
        int n = vertices.size(), sub;
        for(int i=0; i<n; i++){
            if(!adjLists[i].visited)
                s.push(i);
            while(!s.empty()){
                sub = s.top(); s.pop();
                adjLists[sub].visited = true;
                cout << vertices[sub] << " " ;

                for(int j : adjLists[sub].adjacencies){
                    if(!adjLists[j].visited)
                        s.push(j);
                }
            }
        }
        cout << endl;
    }
    void BFS(){
        setNotVisited();
        queue<int> q;
        int sub, n = vertices.size();

        for(int i=0; i<n; i++){ // maybe not connected
            if(!adjLists[i].visited) q.push(i); // begin at v[i]
            while(!q.empty()){
                // v[0] dequeue and all its adjacency inqueue
                sub = q.front(); q.pop();
                adjLists[sub].visited = true;
                cout << vertices[sub] << " " ;

                for(int j : adjLists[sub].adjacencies){
                    if(!adjLists[j].visited)
                        q.push(j); // inqueue: all adjs
                }
            }
        }
        cout << endl;
    }
};
#endif // GRAPH_H_INCLUDED
