#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 4

int tsp(int graph[][V], vector<bool> &visited, vector<int> &path, int currentPos, int count, int cost, int ans, vector<int> &bestPath)
{
    if (count == V)
    {
        if (graph[currentPos][0] != 0)
        {
            if (cost + graph[currentPos][0] < ans)
            {
                ans = cost + graph[currentPos][0];
                bestPath = path;       
                bestPath.push_back(0); 
            }
        }
        return ans;
    }

    for (int city = 0; city < V; city++)
    {
        if (!visited[city] && graph[currentPos][city] != 0)
        {
            visited[city] = true;
            path.push_back(city); 

            ans = tsp(graph, visited, path, city, count + 1, cost + graph[currentPos][city], ans, bestPath);

            visited[city] = false;
            path.pop_back();       
        }
    }

    return ans;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    vector<bool> visited(V, false);
    vector<int> path;     
    vector<int> bestPath; 

    visited[0] = true;
    path.push_back(0); 

    int ans = INT_MAX;

    ans = tsp(graph, visited, path, 0, 1, 0, ans, bestPath);

    cout << "Minimum cost of the Hamiltonian Cycle: " << ans << endl;

    cout << "Visited cities in order: ";
    for (int city : bestPath)
    {
        cout << city << " ";
    }
    cout << endl;

}
