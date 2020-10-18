#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> used;
vector<int> dist; // ������ � ������� �������� ����������
vector<int> check_friendly;

// 1.Description of the function of the depth-first search algorithm
void dfs(int start) { // O(V+E), ��� V - ���������� ������, E - ���������� ����
    used[start] = true; // ��� ����� � ������� ��������, ��� �� � �� �����
    for (const auto& u : graph[start]) { // ������� ��� ���� ���� �������
        if (!used[u]) { // ���� �� �������� � ������� ������, �� ������� �, ����� ������� � ��
            dfs(u); // ����������� �� ���� �������
        }
    }
}

// 2.Graph traversal algorithm based on breadth - first search
void bfs(int start) { // O(V+E)
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); // ������ �������, �� ����� ������� �� ���� ��������
        q.pop(); // ������� � �� �������, �.�. ��� ������ �� �����
        used[u] = true; // ��������, ��� �� ����� � �������
        for (const auto& x : graph[u]) { // �������� �� ���� ����� ���� �������
            if (!used[x]) {
                q.push(x);
            }
        }
    }
}
// 3.Defines all vertices of the graph that are at a fixed distance d from this vertex.
void bfs_dist(int start) { // O(V+E)
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); // ������ �������, �� ����� ������� �� ���� ��������
        q.pop(); // ������� � �� �������, �.�. ��� ������ �� �����
        used[u] = true; // ��������, ��� �� ����� � �������
        for (const auto& x : graph[u]) { // �������� �� ���� ����� ���� �������
            if (!used[x]) {
                q.push(x);
                dist[x] = dist[u] + 1; // ������� ���������� �� �������� �� ������
            }
        }
    }
}
// 4.Renumber the vertices of the graph in the order of depth traversal and
// calculate the average density of the graph as a quotient of the number of its edges divided by the number of vertices

void dfs_edit_graph(int start) { // O(V+E), ��� V - ���������� ������, E - ���������� ����
    used[start] = true; // ��� ����� � ������� ��������, ��� �� � �� �����
    for (const auto& u : graph[start]) { // ������� ��� ���� ���� �������
        graph[start][u] = rand() % 10;
        if (!used[u]) { // ���� �� �������� � ������� ������, �� ������� �, ����� ������� � ��
            dfs(u); // ����������� �� ���� �������
        }
    }
}
void dfs_density(int start, int* vertex, int* edges) {
    *(vertex)++;
    used[start] = true; // ��� ����� � ������� ��������, ��� �� � �� �����
    for (const auto& u : graph[start]) { // ������� ��� ���� ���� �������
        *(edges)++;
        if (!used[u]) { // ���� �� �������� � ������� ������, �� ������� �, ����� ������� � ��
            dfs_density(u, vertex, edges); // ����������� �� ���� �������
        }
    }
}
// 5.The number of pairs of friendly numbers in the graph vertices that are connected by edges
long long sum_of_divs(long long x) {
    long long sum = 0;
    for (int i = 1; i < x / 2 + 1; ++i) {
        if ( !(x % i) ) {
            sum += i;
        }
    }
    return sum;
}
bool is_friendly_numbers(long long x, long long y) {
    return (sum_of_divs(x) == y) && (sum_of_divs(y) == x);
}

int bfs_friendly_numbers(int start) { // O(V+E)
    int answer = 0;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); // ������ �������, �� ����� ������� �� ���� ��������
        q.pop(); // ������� � �� �������, �.�. ��� ������ �� �����
        used[u] = true; // ��������, ��� �� ����� � �������
        for (const auto& x : graph[u]) { // �������� �� ���� ����� ���� �������
            if (!used[x]) {
                q.push(x);
            }
            if (is_friendly_numbers(check_friendly[u], check_friendly[x])) {
                answer++;
            }
        }
    }

    return answer /= 2;
}
/*   1 2 3 4 ������� ���������
 * 1 0 1 0 1
 * 2 1 0 1 1
 * 3 0 1 0 1
 * 4 1 1 1 0
 * ������ ��������� ������� a[����� ������� �������][����� ������� � ������� �� ����� ��������� �����]
 * ��������� �� ������ O(n^2)
 * ������ � ��������� �������
 */
 /* ������ ����������, ����� ��� ������ ������� �������� ������ �� ������� � �������� ��� ������� ������
  * 1: 2, 4
  * 2: 1, 3, 4
  * 3: 2, 4
  * 4: 1, 2, 3
  * ������ � ������� ��������
  */
  /*
   * ������ m = 5 � n = 4
   * 1 2
   * 1 4
   * 2 3
   * 2 4
   * 3 4
  */

int main() {
    int n, m; // n - ���-�� ������, m - ���-�� ����
    cin >> n >> m;
    
    graph.assign(n, vector<int>());
    used.assign(n, false);
    
    // ��������� ����
    for (int i = 0; i < m; ++i) {
        int u1, u2;
        cin >> u1 >> u2;
        graph[u1 - 1].push_back(u2 - 1);
        graph[u2 - 1].push_back(u1 - 1);
    }
    // 1
    dfs(4);

    used.assign(n, false);
    // 2
    bfs(4);

    used.assign(n, false);
    dist.assign(n, 0);

    int d;
    cout << "Input number tops: ";
    cin >> d;
    cout << "Out number top: ";
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i] == d) { // ���� ���������� d ������� ����� ���� �������
            cout << i + 1 << ' ';
        }
    }
    // 3
    bfs_dist(d);
    dist.assign(n, 0);
    used.assign(n, false);

    // 4
    dfs_edit_graph(d);

    used.assign(n, false);

    int* vertex = 0,* edges = 0;
    dfs_density(0, vertex, edges);

    used.assign(n, false);
    cout << "The average density count: " << *vertex / *edges << endl;
    // 5
    cout << "Friendly numbers: " << bfs_friendly_numbers(n);




    //����� ������ ��� ���������� ����������� ��� ���������� �����
    //used.assign(n, false);
    //for (const auto& us : used) {
    //    if (!used[us]) // ����� ������� ���������� �����������
    //    { 
    //        dfs(us); 
    //    }
    //}

    return 0;
}
