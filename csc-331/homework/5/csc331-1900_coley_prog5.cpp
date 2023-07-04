/*
 * CSC331-1900
 * Natalie Coley
 * csc331-1900_coley_prog5.cpp
 *
 * Assignment #5 - Due 12/1/2019
 *
 * The purpose of this program is to, based on user or file input, identify a minimum spanning tree from a series
 * of given graph edges and display the MST to the user (or print to an output file.
 *
 *
 */

#include <iostream>
#include <list>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * ############################################
 * ##                                        ##
 * ##              Graph Edges               ##
 * ##                                        ##
 * ############################################
 */

/* ~~ GraphEdge Class ~~ */

class GraphEdge {
public:
    int v1; // 1st vertex
    int v2; // 2nd vertex
    int weight;
    bool contains(int v);
    int other_vertex(int v);

    GraphEdge() {};
    GraphEdge(int first_vertex, int second_vertex, int edge_weight);
};

GraphEdge::GraphEdge(int first_vertex, int second_vertex, int edge_weight) {
    v1 = first_vertex;
    v2 = second_vertex;
    weight = edge_weight;
}

/* Public Methods */

bool GraphEdge::contains(int v) {
    return v1 == v || v2 == v;
}

int GraphEdge::other_vertex(int v) {
    if (v1 == v) { return v2; }
    else { return v1; }
}

/*
 * ############################################
 * ##                                        ##
 * ##           Helper Functions             ##
 * ##                                        ##
 * ############################################
 */

GraphEdge process_user_input(string input, set<int> *vertices) {
    size_t first_substr_pos = input.find(" ", 0);
    size_t second_substr_pos = input.find(" ", first_substr_pos + 1);

    int first_vertex = stoi(input.substr(0, first_substr_pos));
    vertices->insert(first_vertex);
    int second_vertex = stoi(input.substr(first_substr_pos, second_substr_pos));
    vertices->insert(second_vertex);
    int weight = stoi(input.substr(second_substr_pos, string::npos));

    return GraphEdge(first_vertex, second_vertex, weight);
}

void printMinimumSpanningTreeFromUserInput() {
    string input;
    GraphEdge *tempEdges = new GraphEdge[100];
    set<int> *vertices = new set<int>;

    int numberOfEdges = 0;

    while(getline(cin, input)) {
        if (!input.compare("end-of-file")) {

            if (numberOfEdges > 0) {
                /* Create an appropriately sized array to store graph edges */
                GraphEdge *edges = new GraphEdge[numberOfEdges];
                copy(tempEdges, tempEdges + sizeof(GraphEdge), edges);
                delete [] tempEdges;

                // Find MST

                int vertexCount = vertices->size();
                int *checkedVertices = new int[vertexCount];
                GraphEdge *edgesInMst = new GraphEdge[vertexCount - 1];

                int visitedVertexCount = 0;
                int edgesInMstCount = 0;
                set<int>::iterator iterator = vertices->begin();
                while (iterator != vertices->end()) {
                    GraphEdge lowestWeightedEdge = GraphEdge(100, 100, 1000);

                    bool hasIteratorBeenVisited = false;
                    for (int i = 0; i < numberOfEdges; i++) {
                        if (edges[i].contains(*iterator)) {

                            bool hasBeenVisited = false;
                            for (int k = 0; k < vertexCount; k++) {
                                if (checkedVertices[k] == *iterator) { hasIteratorBeenVisited = true; }
                                if (checkedVertices[k] == edges[i].other_vertex(*iterator)) { hasBeenVisited = true; }
                            }

                            if (!hasBeenVisited && edges[i].weight < lowestWeightedEdge.weight) {
                                lowestWeightedEdge = edges[i];
                            }
                        }
                    }

                    if (lowestWeightedEdge.weight < 1000) {
                        if (!hasIteratorBeenVisited) {
                            checkedVertices[visitedVertexCount] = *iterator;
                            visitedVertexCount++;
                        }
                        checkedVertices[visitedVertexCount] = lowestWeightedEdge.other_vertex(*iterator);
                        visitedVertexCount++;
                        edgesInMst[edgesInMstCount] = lowestWeightedEdge;
                        edgesInMstCount++;
                    }

                    iterator++;
                }

                /* Print MST */

                int totalWeight = 0;

                cout << "Minimum Spanning Tree: " << endl;
                for (int i = 0; i < edgesInMstCount; i++) {
                    totalWeight = totalWeight + edgesInMst[i].weight;
                    cout << edgesInMst[i].v1 << " " << edgesInMst[i].v2 << " " << edgesInMst[i].weight << endl;
                }
                cout << "Edge weight total: " << totalWeight << endl;
            }
            break;
        }
        //convert input to edge and store in array, then increment numberOfEdges
        tempEdges[numberOfEdges] = process_user_input(input, vertices);
        ++numberOfEdges;
    }
}

void printMinimumSpanningTreeFromFileInput(char *argv[]) {
    string input;
    /* Assumes input file is a text file containing graph edges in the expected format listed above */
    string inputFileName = argv[1];
    //string outputFileName = argv[2];

    int numberOfEdges = 0;
    GraphEdge *tempEdges = new GraphEdge[100];
    set<int> *vertices = new set<int>;

    /* Read edges from input text file */
    ifstream inputFileStream;
    inputFileStream.open(inputFileName);

    if (!inputFileStream) { cout << "Cannot open input file." << endl; return; } //TODO: request manual input

    while(getline(inputFileStream, input)) {
        if (!input.compare("end-of-file")) {
            break;
        }
        //convert input to edge and store in array, then increment numberOfEdges
        tempEdges[numberOfEdges] = process_user_input(input, vertices);
        ++numberOfEdges;
    }

    if (numberOfEdges > 0) {
        /* Create an appropriately sized array to store graph edges */
        GraphEdge *edges = new GraphEdge[numberOfEdges];
        copy(tempEdges, tempEdges + sizeof(GraphEdge), edges);
        delete [] tempEdges;

        // Find MST

        int vertexCount = vertices->size();
        int *checkedVertices = new int[vertexCount];
        GraphEdge *edgesInMst = new GraphEdge[vertexCount - 1];

        int visitedVertexCount = 0;
        int edgesInMstCount = 0;
        set<int>::iterator iterator = vertices->begin();
        while (iterator != vertices->end()) {
            GraphEdge lowestWeightedEdge = GraphEdge(100, 100, 1000);

            bool hasIteratorBeenVisited = false;
            for (int i = 0; i < numberOfEdges; i++) {
                if (edges[i].contains(*iterator)) {

                    bool hasBeenVisited = false;
                    for (int k = 0; k < vertexCount; k++) {
                        if (checkedVertices[k] == *iterator) { hasIteratorBeenVisited = true; }
                        if (checkedVertices[k] == edges[i].other_vertex(*iterator)) { hasBeenVisited = true; }
                    }

                    if (!hasBeenVisited && edges[i].weight < lowestWeightedEdge.weight) {
                        lowestWeightedEdge = edges[i];
                    }
                }
            }

            if (lowestWeightedEdge.weight < 1000) {
                if (!hasIteratorBeenVisited) {
                    checkedVertices[visitedVertexCount] = *iterator;
                    visitedVertexCount++;
                }
                checkedVertices[visitedVertexCount] = lowestWeightedEdge.other_vertex(*iterator);
                visitedVertexCount++;
                edgesInMst[edgesInMstCount] = lowestWeightedEdge;
                edgesInMstCount++;
            }

            iterator++;
        }

        /* Print MST */

        int totalWeight = 0;

        cout << "Minimum Spanning Tree: " << endl;
        for (int i = 0; i < edgesInMstCount; i++) {
            totalWeight = totalWeight + edgesInMst[i].weight;
            cout << edgesInMst[i].v1 << " " << edgesInMst[i].v2 << " " << edgesInMst[i].weight << endl;
        }
        cout << "Edge weight total: " << totalWeight << endl;
    }
}

void outputMinimumSpanningTreeFromFileInputToOutputFile(char *argv[]) {
    string input;
    /* Assumes input file is a text file containing graph edges in the expected format listed above */
    string inputFileName = argv[1];
    string outputFileName = argv[2];

    int numberOfEdges = 0;
    GraphEdge *tempEdges = new GraphEdge[100];
    set<int> *vertices = new set<int>;

    /* Read edges from input text file */
    ifstream inputFileStream;
    inputFileStream.open(inputFileName);

    if (!inputFileStream) { cout << "Cannot open input file." << endl; return; } //TODO: request manual input

    while(getline(inputFileStream, input)) {
        if (!input.compare("end-of-file")) {
            break;
        }
        //convert input to edge and store in array, then increment numberOfEdges
        tempEdges[numberOfEdges] = process_user_input(input, vertices);
        ++numberOfEdges;
    }

    if (numberOfEdges > 0) {
        /* Create an appropriately sized array to store graph edges */
        GraphEdge *edges = new GraphEdge[numberOfEdges];
        copy(tempEdges, tempEdges + sizeof(GraphEdge), edges);
        delete [] tempEdges;

        // Find MST

        int vertexCount = vertices->size();
        int *checkedVertices = new int[vertexCount];
        GraphEdge *edgesInMst = new GraphEdge[vertexCount - 1];

        int visitedVertexCount = 0;
        int edgesInMstCount = 0;
        set<int>::iterator iterator = vertices->begin();
        while (iterator != vertices->end()) {
            GraphEdge lowestWeightedEdge = GraphEdge(100, 100, 1000);

            bool hasIteratorBeenVisited = false;
            for (int i = 0; i < numberOfEdges; i++) {
                if (edges[i].contains(*iterator)) {

                    bool hasBeenVisited = false;
                    for (int k = 0; k < vertexCount; k++) {
                        if (checkedVertices[k] == *iterator) { hasIteratorBeenVisited = true; }
                        if (checkedVertices[k] == edges[i].other_vertex(*iterator)) { hasBeenVisited = true; }
                    }

                    if (!hasBeenVisited && edges[i].weight < lowestWeightedEdge.weight) {
                        lowestWeightedEdge = edges[i];
                    }
                }
            }

            if (lowestWeightedEdge.weight < 1000) {
                if (!hasIteratorBeenVisited) {
                    checkedVertices[visitedVertexCount] = *iterator;
                    visitedVertexCount++;
                }
                checkedVertices[visitedVertexCount] = lowestWeightedEdge.other_vertex(*iterator);
                visitedVertexCount++;
                edgesInMst[edgesInMstCount] = lowestWeightedEdge;
                edgesInMstCount++;
            }

            iterator++;
        }

        /* Print MST */

        int totalWeight = 0;

        ofstream outputFile;
        outputFile.open(outputFileName);

        outputFile << "Minimum Spanning Tree: \n";
        for (int i = 0; i < edgesInMstCount; i++) {
            totalWeight = totalWeight + edgesInMst[i].weight;
            outputFile << edgesInMst[i].v1 << " " << edgesInMst[i].v2 << " " << edgesInMst[i].weight << "\n";
        }
        outputFile << "Edge weight total: " << totalWeight << "\n";
        outputFile.close();
    }

}

/*
 * ############################################
 * ##                                        ##
 * ##                Main                    ##
 * ##                                        ##
 * ############################################
 */

int main(int argc, char** argv) {
    if (argc == 1) {
        cout << "Please enter the undirected edges of your connected weighted graph. " << endl;
        cout << "[ Each edge should be presented in the following format: v1 v2 w where v1 and v2 are unequal non-negative integers in the range 0 to 99"
                "and w is the edge weight as a positive integer in the range 1 to 99. When you've finished entering your chosen edges an input transaction"
                "containing the string `end-of-file` will terminate the input and then calculate and display the MST ]" << endl;
        printMinimumSpanningTreeFromUserInput();
    }
    else if (argc == 2) {
        printMinimumSpanningTreeFromFileInput(argv);
    }
    else if (argc == 3) {
        outputMinimumSpanningTreeFromFileInputToOutputFile(argv);
    }

    return 0;
}