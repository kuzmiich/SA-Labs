#pragma once
using namespace std;

//1.Description of the function of the depth-first search algorithm
void Depth_First_Search(int n, int** Graph, bool* Visited, int Node) {
    Visited[Node] = true;
    cout << Node + 1 << endl;
    for (int i = 0; i < n; i++)
    {
        if (Graph[Node][i] && !Visited[i])
        {
            Depth_First_Search(n, Graph, Visited, i);
        }
    }
}

//2.Description of the function of the breadth-first search algorithm
void Breadth_First_Search(int n, int** Graph, bool* Visited, int Node) {
    int* List = new int[n];
    int Count, Head;
    int i;
    for (i = 0; i < n; i++)
        List[i] = 0;
    Count = Head = 0;

    List[Count++] = Node;
    Visited[Node] = true;
    while (Head < Count) {

        Node = List[Head++];
        cout << Node + 1 << endl;

        for (i = 0; i < n; i++)
            if (Graph[Node][i] && !Visited[i]) {
                List[Count++] = i;
                Visited[i] = true;
            }
    }
}
//3.Determine all vertices of the graph that are at a fixed distance "d" from a given vertex
vector<vector<int>> g;
int n;
vector<bool> used(n);

void bfs(int start)
{
    used.clear();

    queue<int> q;
    q.push(start);
    vector<int> d(n), p(n);
    used[start] = true;
    p[start] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (!used[to])
            {
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
}

//5.
const int SIZE = 1e3 + 10;
int p[SIZE];
bool usd[SIZE];

int connected_components_amount_dsu() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
        int par = p[f];
        for (int j = 1; j <= n; ++j) {
            if (p[j] == par)
                p[j] = p[s];
        }
    }
    for (int i = 1; i <= n; ++i)
        usd[p[i]] = true;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (usd[i]) ++cnt;
    }
    return cnt;
}