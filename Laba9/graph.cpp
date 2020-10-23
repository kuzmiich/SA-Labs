#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> used;
vector<int> dist; // Вектор в котором хранятся расстояния
vector<int> check_friendly{};

// 1.Description of the function of the depth-first search algorithm
void dfs(int start) { // O(V+E), где V - количество вершин, E - количество рёбер
    used[start] = true; // При входе в вершину помечаем, что мы в неё вошли
    for (const auto& u : graph[start]) { // Обходим все рёбра этой вершины
        if (!used[u]) { // Если мы заходили в вершину раньше, то скипаем её, иначе заходим в неё
            dfs(u); // Запускаемся из этой вершины
        }
    }
}

// 2.Graph traversal algorithm based on breadth - first search
void bfs(int start) { // O(V+E)
    queue<int> q;
    q.push(start);
    used[start - 1] = true;
    while (!q.empty()) {
        int u = q.front(); // достаём вершину, по рёбрам которой мы хоти пройтись
        q.pop(); // удаляем её из очереди, т.к. она больше не нужна
        used[u] = true; // помечаем, что мы зашли в вершину
        for (const auto& x : graph[u]) { // проходим по всем рёбрам этой вершины
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
    used[start - 1] = true;
    while (!q.empty()) {
        int u = q.front(); // достаём вершину, по рёбрам которой мы хоти пройтись
        q.pop(); // удаляем её из очереди, т.к. она больше не нужна
        used[u] = true; // помечаем, что мы зашли в вершину
        for (const auto& x : graph[u]) { // проходим по всем рёбрам этой вершины
            if (!used[x]) {
                q.push(x);
                dist[x] = dist[u] + 1; // считаем расстояние от родителя до предка
            }
        }
    }
}
// 4.Renumber the vertices of the graph in the order of depth traversal and
// calculate the average density of the graph as a quotient of the number of its edges divided by the number of vertices

void dfs_edit_graph(int start) { // O(V+E), где V - количество вершин, E - количество рёбер
    used[start] = true; // При входе в вершину помечаем, что мы в неё вошли
    for (const auto& u : graph[start]) { // Обходим все рёбра этой вершины
        // graph[start][u] = rand() % 10;
        if (!used[u]) { // Если мы заходили в вершину раньше, то скипаем её, иначе заходим в неё
            dfs(u); // Запускаемся из этой вершины
        }
    }
}
void dfs_density(int start, int& vertex, int& edges) {
    vertex++;
    used[start] = true; // При входе в вершину помечаем, что мы в неё вошли
    for (const auto& u : graph[start]) { // Обходим все рёбра этой вершины
        edges++;
        if (!used[u]) { // Если мы заходили в вершину раньше, то скипаем её, иначе заходим в неё
            dfs_density(u, vertex, edges); // Запускаемся из этой вершины
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
    used[start] = true;
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); // достаём вершину, по рёбрам которой мы хоти пройтись
        q.pop(); // удаляем её из очереди, т.к. она больше не нужна
        used[u] = true; // помечаем, что мы зашли в вершину
        for (const auto& x : graph[u]) { // проходим по всем рёбрам этой вершины
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
/*   1 2 3 4 Матрица смежности
 * 1 0 1 0 1
 * 2 1 0 1 1
 * 3 0 1 0 1
 * 4 1 1 1 0
 * Удобно доставать элемент a[номер текущей вершины][номер вершины с которой мы хотим проверить связь]
 * Сложность по памяти O(n^2)
 * Храним в двумерном массиве
 */
 /* Список смежностей, когда для каждой вершины записаны только те вершины с которыми она связана ребром
  * 1: 2, 4
  * 2: 1, 3, 4
  * 3: 2, 4
  * 4: 1, 2, 3
  * Храним в векторе векторов
  */
  /*
   * читаем n = 4 и m = 5
   * 4 5
   * 1 2
   * 1 4
   * 2 3
   * 2 4
   * 3 4
  */

int main() {
    int n, m; // n - кол-во вершин, m - кол-во рёбер
    cout << "Input the number of vertices - n and number of edges - m:\n";
    cin >> n >> m;
    
    graph.assign(n, vector<int>());
    used.assign(n, false);
    
    // Считываем граф
    for (int i = 0; i < m; ++i) {
        int u1, u2;
        cin >> u1 >> u2;
        graph[u1 - 1].push_back(u2 - 1);
        graph[u2 - 1].push_back(u1 - 1);
    }
    // 1
    dfs(3);

    used.assign(n, false);
    // 2
    bfs(3);

    used.assign(n, false);
    dist.assign(n, 0);

    // 3
    int d;
    cout << "Input number tops: ";
    cin >> d;
    bfs_dist(d);
    used.assign(n, false);

    cout << "Out number top: ";
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i] == d) { // если расстояние d выводим номер этой вершины
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
    dist.assign(n, 0);
    // 4
    // dfs_edit_graph(d);

    used.assign(n, false);
    int zero_vertex = 0, zero_adges = 0;
    int * vertex = &zero_vertex,* edges = &zero_adges;
    dfs_density(2, *vertex, *edges);

    used.assign(n, false);
    cout << "The average density count: " << (double)*vertex / *edges << endl;
    // 5
    for (int i = 0; i < n; i++) {
        check_friendly.push_back(rand() % 50);
        cout << check_friendly[i] << " ";
    }
    cout << "Friendly numbers: " << bfs_friendly_numbers(n - 1);


    // чтобы пройти все компоненты связанности для несвязного графа
    //used.assign(n, false);
    //for (const auto& us : used) {
    //    if (!used[us]) // можно считать компоненты связанности
    //    { 
    //        dfs(us); 
    //    }
    //}

    return 0;
}
