//xcode-select --install

/*
This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. 
Each True boolean represents a wall. 
Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, 
return the minimum number of steps required to reach the end coordinate from the start. 
If there is no possible path, then return null. You can move up, left, down, and right. 
You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[
[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), 
the minimum number of steps required to reach the end is 7, 
since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*/

//dijkstra's algorithm: finding shortest paths between nodes in a graph implemented in O(n^2) in an array
//the set of all the paths is a directed graph.
//sequentially representing a directed graph can be done as an adjacency matrix or an adjacency list
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Edge
{
    int start, end;
};

class Graph
{
    Node **head;
    int N;

public:
    Node *getListNode(int val, Node *head)
    {
        Node *newNode = new Node;
        newNode->val = val;
        newNode->next = head;
        return newNode;
    }
    Graph(Edge edges[], int number_of_vertices, int number_of_edges)
    {
        head = new Node *[number_of_edges](); //node pointer array
        this->N = number_of_edges;
        for (int i = 0; i < N; ++i)
            head[i] = nullptr; //init all nodes as null
        for (unsigned i = 0; i < number_of_vertices; i++)
        {
            int start = edges[i].start;
            int end = edges[i].end;

            Node *newNode = getListNode(end, head[start]);
            head[start] = newNode;
        }
    }
    ~Graph()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] head[i];
            delete[] head;
        }
    }
};


void message(int i, int j, int ii, int jj, int curr_tile, int adj_tile)
{

    if (!adj_tile)
        if (ii >= 0 && //within bounds
            ii < 4 &&  //within bounds
            jj >= 0 &&               //within bounds
            jj < 4                   //within bounds
            && !(jj == j && ii == i) // nodes are not adjacent with themselves
        )
            if (!curr_tile && !adj_tile) //if current tile and its neighbor are floor,
            {

                cout << "edge from (i,j) = (" << i << "," << j << ") to (ii,jj) = (" << ii << "," << jj << ")" << endl;
                
                
            }
}

int main()
{
    int matrix[4][4] = {{0, 0, 0, 0},
                        {1, 1, 0, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};

    int i, j;

    //generate edges
    
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            cout << i * 4 + j << ": (i,j) = (" << i << "," << j << ") = " << matrix[i][j] << endl;

            int ii = i - 1; //left
            int jj = j;
            message(i, j, ii, jj, matrix[i][j], matrix[ii][jj]);
            ii = i;
            jj = j - 1; //up
            message(i, j, ii, jj, matrix[i][j], matrix[ii][jj]);
            ii = i + 1; //right
            jj = j;
            message(i, j, ii, jj, matrix[i][j], matrix[ii][jj]);
            ii = i;
            jj = j + 1; //down
            message(i, j, ii, jj, matrix[i][j], matrix[ii][jj]);
        }
    }
    /*
    Edge edges[] = {
        // (x, y) -> edge from x to y
        {0, 1},
        {0, 2},
        {1, 4},
        {2, 3},
        {3, 1},
        {4, 3}};
    int N = 6; // Number of vertices in the graph
    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);
    // construct graph
    Graph diagraph(edges, n, N);
*/
    return 0;
}
