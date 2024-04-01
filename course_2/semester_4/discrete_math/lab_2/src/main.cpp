#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;



class DSU {
    int* parent;
    int* rank;
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
            parent[s2] = s1;
            rank[s1] += 1;
            }
        }
    }

};

class Graph {
private:
    vector<vector<int>> adjmatrix;
    vector<char> vertices;
    int vert_num = 10;
public:
    Graph(vector<char> vertices) {
        this->vertices = vertices;
    }
    Graph(int vert_num, string file_dir) {
        ifstream ifile;
        ifile.open(file_dir);

        this->vert_num = vert_num;

        if (!ifile.is_open()) {
            cout << "Bad file" << endl;
        }
        else {
            int input;
            this->adjmatrix = vector<vector<int>>(vert_num, vector<int>(vert_num, 0));

            for (int i = 0; i < vert_num; i++) {
                for (int j = 0; j < vert_num; j++) {
                    ifile >> input;
                    if (input != 0) {
                        this->adjmatrix[i][j] = input;
                    }
                    else if (input == 0) {
                        this->adjmatrix[i][j] = 0;
                    }
                }
            }
        }
        char c = 'A';
        for (int i = 0; i < vert_num; i++) {
            this->vertices.push_back(c+i);
        }

    }

    // getters, setters
    vector<char> getVerts() {
        return vertices;
    }
    void setMatrix(vector<vector<int>> mtx) {
        if (mtx.size() != vertices.size() || mtx[0].size() != vertices.size()){
            cout << "Size of matrix doesn't corresponds to number of vertices" << endl;
            return;
        }
        this->adjmatrix = mtx;
    }

    // prints 
    template <class T>
    void printvec(vector<T> vec) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    void printMtx() {
        if (adjmatrix.size() == 0) {
            cout << "There is no links in graph" << endl;
            return;
        }
        cout << "  ";
        printvec(vertices);
        for (int i = 0; i < adjmatrix.size(); i++) {
            cout << vertices[i] << " ";
            printvec(adjmatrix[i]);
        }
        cout << '\n';
    }
    template <class T>
    void printMtx(vector<vector<T>> mtx) {
        if (mtx.size() == 0) {
            cout << "There is no links in graph" << endl;
            return;
        }
        
        for (int i = 0; i < mtx.size(); i++) {
            printvec(mtx[i]);
        }
        cout << endl;
    }
    //
    // Main methods 
    //
    vector<vector<int>> getKruscal_tree() {

        vector<int> edges_values;
        vector<vector<int>> edges_indices;

        for (int i = 0; i < adjmatrix.size(); i++) {
            for (int j = 0; j < adjmatrix.size(); j++) {
                if (i != j) {
                    edges_values.push_back(adjmatrix[i][j]);
                    edges_indices.push_back({i,j});
                }
            }
        }

        vector<vector<int>> edges = sortvec(edges_values, edges_indices);

        DSU s(this->adjmatrix.size());
        //printMtx(edges);

        vector<vector<int>> new_tree; //vector<vector<int>>(adjmatrix.size(), vector<int>(adjmatrix.size(), 0));

        vector<bool> usedVerteces = vector<bool>(vert_num, false);

        for (int i = 0; i < edges.size(); i++) {
            if (s.find(edges[i][0]) != s.find(edges[i][1]) && edges[i][2] != 0) {
                s.unite(edges[i][0], edges[i][1]);
                s.unite(edges[i][1], edges[i][0]);
                new_tree.push_back(edges[i]);
            }
        }

        return new_tree;
    }

    vector<vector<int>> getPrim_tree() {

        vector<vector<int>> new_tree;

        vector<bool> usedVerteces = vector<bool>(adjmatrix.size(), false);

        int e = 0;

        usedVerteces[0] = true;
        while (e < vert_num - 1) {
            
            int min = 10000;
            int min_i = 0;
            int min_j = 0;

            for (int i = 0; i < vert_num; i++) {
                if (usedVerteces[i]) {
                    for (int j = 0; j < vert_num; j++) {
                        if (!usedVerteces[j]) {
                            if (min > adjmatrix[i][j] && adjmatrix[i][j] != 0) {
                                min = adjmatrix[i][j];
                                min_i = i;
                                min_j = j;
                            }
                        }
                    }
                }
            }
            
            new_tree.push_back({min_i, min_j, min});
            usedVerteces[min_j] = true;
            e++;
        }
        return new_tree;
    }   
    void getWeight() {
        auto e1 = this->getPrim_tree();
        auto e2 = this->getKruscal_tree();

        int w1 = 0;
        int w2 = 0;

        for (int i = 0; i < e1.size(); i++) {
            w1 += e1[i][2];
        }
        cout << "Weight from Prim algorithm:" << w1 << endl; 
        printMtx(e1);
        for (int i = 0; i < e2.size(); i++) {
            w2 += e2[i][2];
        }
        cout << "Weight from Kruscal algorithm:" << w2 << endl; 
        printMtx(e2);
    }
private:
    //
    // hidden methods 
    // 
    bool isboolVecTrue(vector<bool> vec) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == false) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> sortvec(vector<int> arr, vector<vector<int>> indices) {
        vector<int> count;
        vector<vector<int>> output = vector<vector<int>>(arr.size());
        
        int max = arr[0];

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }

        count = vector<int>(max + 1);

        for (int i = 0; i < max + 1; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            count[arr[i]]++;
        }
        for (int i = 1; i < max + 1; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            output[count[arr[i]] - 1] = {indices[i][0], indices[i][1], arr[i]};
            
            count[arr[i]]--;
        }
        return output;
    }
};


int main() {
    string file_dir = "./g23.txt";
    int vert_num = 10;

    Graph graph(vert_num, file_dir);

    graph.printMtx();

    //graph.printMtx(graph.getPrim_tree());

    //graph.printMtx(graph.getKruscal_tree());

    graph.getWeight();

    return 0;
}
