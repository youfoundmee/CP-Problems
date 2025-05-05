#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1), adj2(n + 1);
        vector<pair<int, int>> edges(n);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent1(n + 1, 0), subtree1(n + 1, 0), tin(n + 2, 0), tout(n + 2, 0), diffArr(n + 2, 0);
        int timer = 0;

        stack<tuple<int, int, int>> dfsStack;
        dfsStack.push({1, 0, 0});

        while (!dfsStack.empty())
        {
            auto [v, p, idx] = dfsStack.top();
            dfsStack.pop();

            if (idx == 0)
            {
                parent1[v] = p;
                subtree1[v] = 1;
                timer++;
                tin[v] = timer;
            }

            if (idx < adj[v].size())
            {
                int u = adj[v][idx];
                dfsStack.push({v, p, idx + 1});
                if (u != p)
                    dfsStack.push({u, v, 0});
            }
            else
            {
                tout[v] = timer;
                if (p != 0)
                {
                    int sz = subtree1[v];
                    int oth = n - sz;
                    if (sz <= oth)
                    {
                        diffArr[tin[v]]++;
                        diffArr[tout[v] + 1]--;
                    }
                    else
                    {
                        diffArr[1]++;
                        diffArr[n + 1]--;
                        diffArr[tin[v]]--;
                        diffArr[tout[v] + 1]++;
                    }
                    subtree1[p] += subtree1[v];
                }
            }
        }

        for (int i = 1; i <= n; ++i)
            diffArr[i] += diffArr[i - 1];

        vector<int> smallCount(n + 1, 0);
        for (int v = 1; v <= n; ++v)
            smallCount[v] = diffArr[tin[v]];

        long long bestL = LLONG_MAX;
        int A = 1, B = 2;

        for (int i = 1; i < n; ++i)
        {
            auto [x, y] = edges[i];
            int a = min(x, y), b = max(x, y);
            int compB = (parent1[b] == a) ? subtree1[b] : n - subtree1[a];
            int oth = n - compB;
            int orig_min = min(compB, oth);
            long long L = orig_min + smallCount[b] - (compB <= oth ? 1 : 0);
            if (L < bestL)
            {
                bestL = L;
                A = a;
                B = b;
            }
        }

        for (int v = 1; v <= n; ++v)
        {
            if (v == B)
                continue;
            for (int u : adj[v])
                if (u != B)
                    adj2[v].push_back(u);
        }
        for (int u : adj[B])
            if (u != A)
                adj2[A].push_back(u), adj2[u].push_back(A);

        vector<int> parent3(n + 1, -1), subtree3(n + 1, 0), order;
        queue<int> q;
        q.push(A);
        parent3[A] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            order.push_back(v);
            for (int u : adj2[v])
            {
                if (parent3[u] == -1)
                {
                    parent3[u] = v;
                    q.push(u);
                }
            }
        }

        for (int i = (int)order.size() - 1; i >= 0; --i)
        {
            int v = order[i];
            subtree3[v] = 1;
            for (int u : adj2[v])
            {
                if (u != parent3[v])
                    subtree3[v] += subtree3[u];
            }
        }

        int nodes_tprime = n - 1, cent2 = A, bestHeavy = nodes_tprime;
        for (int v : order)
        {
            int heavy = nodes_tprime - subtree3[v];
            for (int u : adj2[v])
                if (u != parent3[v])
                    heavy = max(heavy, subtree3[u]);
            if (heavy < bestHeavy)
                bestHeavy = heavy, cent2 = v;
        }

        vector<bool> used(n + 1, false);
        used[B] = true;
        used[cent2] = true;

        vector<vector<int>> groups = {{cent2}};
        for (int u : adj2[cent2])
        {
            if (used[u])
                continue;
            vector<int> grp;
            deque<int> dq = {u};
            used[u] = true;
            while (!dq.empty())
            {
                int w = dq.front();
                dq.pop_front();
                grp.push_back(w);
                for (int x : adj2[w])
                {
                    if (!used[x])
                    {
                        used[x] = true;
                        dq.push_back(x);
                    }
                }
            }
            groups.push_back(grp);
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < groups.size(); ++i)
            if (!groups[i].empty())
                pq.push({(int)groups[i].size(), i});

        vector<int> color_ans(n + 1, 0);
        color_ans[B] = 0;
        int cur_color = 1;

        while (pq.size() > 1)
        {
            auto [_, i1] = pq.top();
            pq.pop();
            auto [__, i2] = pq.top();
            pq.pop();
            int v1 = groups[i1].back();
            groups[i1].pop_back();
            int v2 = groups[i2].back();
            groups[i2].pop_back();
            color_ans[v1] = color_ans[v2] = cur_color++;
            if (!groups[i1].empty())
                pq.push({(int)groups[i1].size(), i1});
            if (!groups[i2].empty())
                pq.push({(int)groups[i2].size(), i2});
        }

        if (max(A, B) != B)
            swap(A, B);
        cout << A << " " << B << "\n";
        for (int i = 1; i <= n; ++i)
            cout << color_ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
