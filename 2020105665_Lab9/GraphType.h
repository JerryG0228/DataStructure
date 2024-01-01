//
//  GraphType.h
//  Lab09
//
//  Modified by Jeman Park on 2023/11/28.
//

#include "QueType.h"
#include "StackType.h"
#include <string>
#include <iostream>
#include <vector>
#include <utility>

#define MAX_SIZE 50

using namespace std;

template<class VertexType>
class GraphType {
public:
    GraphType();

    ~GraphType();

    void AddVertex(VertexType);

    void AddEdge(VertexType, VertexType, int);

    void UpdateEdge(VertexType, VertexType, int);

    void DeleteEdge(VertexType, VertexType);

    int WeightIs(VertexType, VertexType);

    void ClearMarks();

    void MarkVertex(VertexType);

    bool IsMarked(VertexType);

    void GetAdjacents(VertexType, QueType<VertexType> &);

    void PrintGraph();

    bool DepthFirstSearch(VertexType, VertexType);

    // Exercise (Bonus): You can change the return type OR input parameter of "DepthFirstSearch_Path" below
    void DepthFirstSearch_Path(VertexType, VertexType);

    bool BreadthFirstSearch(VertexType, VertexType);

private:
    int numVertices;
    int maxVertices;
    VertexType *vertices;
    int **edges;
    bool *marks;
};

template<class VertexType>
GraphType<VertexType>::GraphType() {
    numVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[MAX_SIZE];
    edges = new int *[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        edges[i] = new int[MAX_SIZE];
    }
    marks = new bool[MAX_SIZE];
}


template<class VertexType>
GraphType<VertexType>::~GraphType() {
    delete[] vertices;
    for (int i = 0; i < MAX_SIZE; i++) {
        delete edges[i];
    }
    delete edges;
    delete[] marks;
}

const int NULL_EDGE = 0;

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex) {
    vertices[numVertices] = vertex;


    for (int index = 0; index < numVertices + 1; index++) {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;

}


template<class VertexType>
int IndexIs(VertexType *vertices, VertexType vertex) {
    int index = 0;

    while (!(vertex == vertices[index]))
        index++;
    return index;
}


template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight) {
    int row;
    int col;

    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
    edges[col][row] = weight;
}


template<class VertexType>
void GraphType<VertexType>::UpdateEdge(VertexType fromVertex, VertexType toVertex, int weight) {
    /* Implement the function here (Exercise 9-1) */
    // This function replaces the weight between "fromVertex" and "toVertex" with "weight"
    // Example:
    // Original adjacent matrix:
    //      A   B   C
    //  A   0   2   4
    //  B   2   0   3
    //  C   4   3   0
    // UpdateEdge(B, C, 10);
    // Updated matrix:
    //      A   B   C
    //  A   0   2   4
    //  B   2   0   10
    //  C   4   10  0

    int fromIdx = IndexIs(vertices, fromVertex);
    int toIdx = IndexIs(vertices, toVertex);

    edges[fromIdx][toIdx] = weight;
    edges[toIdx][fromIdx] = weight;

}


template<class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex) {
    /* Implement the function here (Exercise 9-1) */
    // This function deletes (makes the weight "NULL_EDGE") the edge between "fromVertex" and "toVertex"
    // Example:
    // Original adjacent matrix:
    //      A   B   C
    //  A   0   2   4
    //  B   2   0   3
    //  C   4   3   0
    // DeleteEdge(B, C);
    // Updated matrix:
    //      A   B   C
    //  A   0   2   4
    //  B   2   0   0
    //  C   4   0   0

    int fromIdx = IndexIs(vertices, fromVertex);
    int toIdx = IndexIs(vertices, toVertex);

    edges[fromIdx][toIdx] = 0;
    edges[toIdx][fromIdx] = 0;
}

template<class VertexType>
void GraphType<VertexType>::ClearMarks() {
    for (int i = 0; i < numVertices; i++) {
        marks[i] = false;
    }
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex) {
    int ver_id = IndexIs(vertices, vertex);
    marks[ver_id] = true;
}

template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) {
    int ver_id = IndexIs(vertices, vertex);
    return marks[ver_id];
}


template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex) {
    int row;
    int col;

    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetAdjacents(VertexType vertex, QueType<VertexType> &adjVertices) {
    int fromIndex;
    int toIndex;

    fromIndex = IndexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
}


template<class VertexType>
bool GraphType<VertexType>::DepthFirstSearch(VertexType startVertex, VertexType endVertex) {
    /* Implement the function here (Exercise 9-2) */
    // This function performs DFS to find the path from "startVertex" to "endVertex" using stack.
    // Refer to Ch.09 (pp.56-57)
    // The implementation may be different from one in the slide in two aspects:
    // 1) It returns "bool" value
    // It retuns TRUE if it successfully finds ANY path.
    // Otherwise, it returns FALSE
    // 2) It is member function of GraphType
    // which means, it can take only two input parameters instead of three parameters in the slide.

    StackType<VertexType> stack;
    stack.Push(startVertex);
    marks[IndexIs(vertices, startVertex)] = true;

    while (!stack.IsEmpty()) {
        VertexType currentVertex;
        stack.Pop(currentVertex);

        if (currentVertex == endVertex) {
            ClearMarks();
            return true;
        }

        int currentIndex = IndexIs(vertices, currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (edges[currentIndex][i] != 0 && !marks[i]) {
                stack.Push(vertices[i]);
                marks[i] = true;
            }
        }
    }

    ClearMarks();
    return false;
}

template<class VertexType>
bool GraphType<VertexType>::BreadthFirstSearch(VertexType startVertex, VertexType endVertex) {
    /* Implement the function here (Exercise 9-3) */
    // This function performs BFS to find the path from "startVertex" to "endVertex" using stack.
    // Refer to Ch.09 (pp.64-65)
    // The implementation may be different from one in the slide in two aspects:
    // 1) It returns "bool" value
    // It retuns TRUE if it successfully finds ANY path.
    // Otherwise, it returns FALSE
    // 2) It is member function of GraphType
    // which means, it can take only two input parameters instead of three parameters in the slide.

    QueType<VertexType> que;
    que.Enqueue(startVertex);
    marks[IndexIs(vertices, startVertex)] = true;

    while (!que.IsEmpty()) {
        VertexType currentVertex;
        que.Dequeue(currentVertex);

        if (currentVertex == endVertex) {
            ClearMarks();
            return true;
        }

        int currentIndex = IndexIs(vertices, currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (edges[currentIndex][i] != 0 && !marks[i]) {
                que.Enqueue(vertices[i]);
                marks[i] = true;
            }
        }
    }

    ClearMarks();
    return false;
}

template<class VertexType>
void GraphType<VertexType>::DepthFirstSearch_Path(VertexType startVertex, VertexType endVertex) {
    /* Exercise (bonus) */
// You can define and implement your function.
// This function basically performs the same thing as "DepthFirstSearch" (NOT recursive way)
// The difference is that this returns "Path" from startVertex to endVertex.
// Either return-by-value or return-by-reference is okay.
// If "Path" does not exist, it would return empty thing.
// If "Path" exists, it will return the recorded paths.
// Example: for the example in the slide pp 53-55,
// It will return "Austin", "Houston", "Atlanta", "Washington" instead of just "TRUE"

// HINT: there are a lot of ways to implement this.
// One way is that you can use "vector" and "pair" (google "C++ STL vector using pair")
    StackType<VertexType> stack;
    vector<pair<VertexType, VertexType>> all_path;
    VertexType temp;
    vector<VertexType> result;

    stack.Push(startVertex);

    while (!stack.IsEmpty()) {
        stack.Pop(temp);
        int popIdx = IndexIs(vertices, temp);

        if (temp == endVertex) {
            break;
        }

        if (!marks[popIdx]) {
            marks[popIdx] = true;

            for (int i = 0; i < numVertices; i++) {
                if (edges[popIdx][i] != 0) {
                    stack.Push(vertices[i]);
                    all_path.push_back(make_pair(temp, vertices[i]));
                }
            }
        }
    }

    if (stack.IsEmpty()) {
        cout << "[]" << endl;
        ClearMarks();
        return;
    }

    ClearMarks();

    result.push_back(endVertex);
    marks[IndexIs(vertices, endVertex)] = true;
    while (true) {
        for (const auto &elem: all_path) {
            if (result.back() == elem.second) {
                int idx = IndexIs(vertices, elem.first);
                if (!marks[idx]) {
                    result.push_back(elem.first);
                    marks[idx] = true;
                    break;
                }
            }
        }
        if (result.back() == startVertex) break;
    }

    cout << "[ ";
    for (int i = result.size() - 1; i >= 0; i--) {
        if (i == 0) cout << result[i] << " ]";
        else cout << result[i] << " => ";
    }
    ClearMarks();
}

template<class VertexType>
void GraphType<VertexType>::PrintGraph() {

    cout << "\t\t";
    for (int i = 0; i < numVertices; i++) {
        cout << vertices[i];
        if (strlen(vertices[i]) >= 4) {
            cout << "\t";
        } else {
            cout << "\t\t";
        }
    }
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << vertices[i];
        if (strlen(vertices[i]) >= 4) {
            cout << "\t";
        } else {
            cout << "\t\t";
        }

        for (int j = 0; j < numVertices; j++) {
            cout << edges[i][j];
            if (to_string(edges[i][j]).length() >= 4) {
                cout << "\t";
            } else {
                cout << "\t\t";
            }

        }
        cout << endl;
    }

}



