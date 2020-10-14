#include <iostream>
#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

int main()
{
    // 3
    int to;
    cin >> to;

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        bfs(i);

        if (!used[to])
            cout << "No path!";
        else
        {
            vector<int> path;

            for (int v = to; v != -1; v = p[v])
                path.push_back(v);

            if (path.size() == d)
                ++ans;
        }
    }
	return 0;
}