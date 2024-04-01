#include <stdio.h>

#define MAX_VERTICES 10
#define MAX_EDGES 45

typedef struct {
    int u;
    int v;
    int w;
} Edge;

void KruskalAlgorithm(void);
void Sort(void);
void Print(Edge edges[MAX_EDGES]);

Edge edgeList[MAX_EDGES] = {0};
int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int parent[MAX_VERTICES] = {0};
int rank[MAX_VERTICES] = {0};

void LoadGraph(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    int c, num, row, column;

    row = column = 0;
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            num = c - '0';
            if (num >= 0 && num <= 100)
                graph[row][column++] = num;
            if (column == 10) {
                column = 0;
                ++row;
            }
        }
    } else {
        printf("Can't open the file.\n");
    }
}

void MakeSet(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

int FindSet(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = FindSet(parent[v]);
}

void UnionSets(int a, int b)
{
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
        if (rank[a] < rank[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void KruskalAlgorithm(void)
{
    printf("Kruskal's algorithm:\n");
    int cost = 0;
    Edge result[MAX_EDGES] = {0};

    int edgeIndex = 0;
    for (int row = 0; row < MAX_VERTICES; ++row)
        for (int col = row + 1; col < MAX_VERTICES; ++col)
            if (graph[row][col] != 0) {
                edgeList[edgeIndex].u = row;
                edgeList[edgeIndex].v = col;
                edgeList[edgeIndex].w = graph[row][col];
                ++edgeIndex;
                if (edgeIndex >= MAX_EDGES)
                    return;
            }

    for (int vertIndex = 0; vertIndex < MAX_VERTICES; ++vertIndex) {
        MakeSet(vertIndex);
    }

    Sort();

    for (int edgeIndex = 0; edgeIndex < MAX_EDGES; ++edgeIndex)
        if (edgeList[edgeIndex].w)
            if (FindSet(edgeList[edgeIndex].u) != FindSet(edgeList[edgeIndex].v)) {
                cost += edgeList[edgeIndex].w;
                result[edgeIndex] = edgeList[edgeIndex];
                UnionSets(edgeList[edgeIndex].u, edgeList[edgeIndex].v);
            }

    Print(result);
    printf("Total cost: %d\n", cost);
}

void Sort(void)
{
    for (int prev = 0; prev < MAX_EDGES; ++prev)
        for (int next = prev + 1; next < MAX_EDGES - 1; ++next)
            if (edgeList[prev].w > edgeList[next].w) {
                Edge temp = edgeList[prev];
                edgeList[prev] = edgeList[next];
                edgeList[next] = temp;
            }
}

void PrimAlgorithm(void)
{
    printf("\nPrim's algorithm:\n");
    int selected[MAX_EDGES] = {0};
    int cost = 0;
    int minRow, minCol;

    selected[0] = 1;
    int edgeIndex = 0;
    for (int vertIndex = 0; vertIndex < MAX_VERTICES - 1; ++vertIndex) {
        int min = 100;
        minRow = minCol = 0;

        for (int row = 0; row < MAX_VERTICES; ++row)
            if (selected[row])
                for (int col = 0; col < MAX_VERTICES; ++col)
                    if (!selected[col] && graph[row][col])
                        if (graph[row][col] < min) {
                            min = graph[row][col];
                            minRow = row;
                            minCol = col;
                        }

        printf("%2d -- %2d: %2d\n", minRow + 1, minCol + 1, graph[minRow][minCol]);
        cost += graph[minRow][minCol];
        selected[minCol] = 1;
    }
    printf("Total cost: %d\n", cost);
}

void Print(Edge edges[MAX_EDGES])
{
    for (int edgeIndex = 0; edgeIndex < MAX_EDGES; ++edgeIndex)
        if (edges[edgeIndex].w)
            printf("%2d -- %2d: %2d\n",
                   edges[edgeIndex].u + 1, edges[edgeIndex].v + 1, edges[edgeIndex].w);
}

int main(void)
{
    LoadGraph("g23.txt");
    printf("    ");
    for (int col = 0; col < MAX_VERTICES; ++col)
        printf("%2d ", col + 1);
    printf("\n");
    for (int row = 0; row < MAX_VERTICES; ++row) {
        printf("%2d| ", row + 1);
        for (int column = 0; column < MAX_VERTICES; ++column)
            printf("%2d ", graph[row][column]);
        printf("\n");
    }
    printf("\n");

    KruskalAlgorithm();
    PrimAlgorithm();
    return 0;
} 
