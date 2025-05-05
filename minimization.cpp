#include <bits/stdc++.h>


using namespace std;

const int ALPHABET_SIZE = 2;

struct DFA
{
    set<char> numStates;
    vector<char> finalStates;
    map<pair<char, int>, char> transitions;
    vector<char> initalstates;
    void addTransition(char state, int symbol, char nextState)
    {
        transitions[{state, symbol}] = nextState;
        numStates.insert(state);
        numStates.insert(nextState);
    }

    void setFinalStates(const vector<char> &finals)
    {
        finalStates = finals;
    }
    void setIntinalStates(const vector<char> &initials)
    {
        initalstates = initials;
    }
};

bool check(char x, char y, vector<vector<char>> &partitions, const DFA &dfa)
{
    if (dfa.transitions.at({x, 0}) == dfa.transitions.at({y, 0}) && dfa.transitions.at({x, 1}) == dfa.transitions.at({y, 1}))
    {
        return true;
    }

    char z1 = dfa.transitions.at({x, 0}), z2 = dfa.transitions.at({y, 0});
    char o1 = dfa.transitions.at({x, 1}), o2 = dfa.transitions.at({y, 1});
    int y1 = -1, y2 = -1;

    for (int i = 0; i < partitions.size(); i++)
    {
        for (int j = 0; j < partitions[i].size(); j++)
        {
            if (partitions[i][j] == z1)
            {
                y1 = i;
            }
            if (partitions[i][j] == o1)
            {
                y2 = i;
            }
        }
    }

    if (y1 == -1 || y2 == -1)
        return false;
    if (find(partitions[y1].begin(), partitions[y1].end(), z2) == partitions[y1].end() ||
        find(partitions[y2].begin(), partitions[y2].end(), o2) == partitions[y2].end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<vector<char>> equivalence(vector<vector<char>> &partitions, const DFA &dfa)
{
    vector<vector<char>> v;
    for (int i = 0; i < partitions.size(); i++)
    {
        char x = partitions[i][0];
        vector<vector<char>> s;
        vector<char> vy;
        vy.push_back(x);
        s.push_back(vy);

        for (int j = 1; j < partitions[i].size(); j++)
        {
            bool flag = false;
            for (int k = 0; k < s.size(); k++)
            {
                if (check(s[k][0], partitions[i][j], partitions, dfa))
                {
                    s[k].push_back(partitions[i][j]);
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                vector<char> vy;
                vy.push_back(partitions[i][j]);
                s.push_back(vy);
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            v.push_back(s[i]);
        }
    }
    return v;
}

vector<vector<char>> minimizeDFA(const DFA &dfa)
{
    vector<vector<char>> partitions(2);
    set<char> finalSet(dfa.finalStates.begin(), dfa.finalStates.end());

    for (auto it : dfa.numStates)
    {
        if (finalSet.find(it) != finalSet.end())
        {
            partitions[0].push_back(it);
        }
        else
        {
            partitions[1].push_back(it);
        }
    }
    cout << "Minimized DFA States:" << endl;
    for (const auto &partition : partitions)
    {
        cout << "{ ";
        for (char state : partition)
            cout << state << " ";
        cout << "}" << endl;
    }

    while (equivalence(partitions, dfa) != partitions)
    {
        partitions = equivalence(partitions, dfa);
        cout << "Minimized DFA States:" << endl;
        for (const auto &partition : partitions)
        {
            cout << "{ ";
            for (char state : partition)
                cout << state << " ";
            cout << "}" << endl;
        }
    }

    return equivalence(partitions, dfa);
}
vector<char> findcoresponding(char x, int symbol, const DFA &dfa, vector<vector<char>> &partitions)
{
    char tofind = dfa.transitions.at({x, symbol});
    for (int i = 0; i < partitions.size(); i++)
    {
        for (int j = 0; j < partitions[i].size(); j++)
        {
            if (partitions[i][j] == tofind)
            {
                return partitions[i];
            }
        }
    }
}
int main()
{
    DFA dfa;
    dfa.addTransition('A', 0, 'B');
    dfa.addTransition('A', 1, 'C');
    dfa.addTransition('B', 0, 'B');
    dfa.addTransition('B', 1, 'D');
    dfa.addTransition('C', 0, 'B');
    dfa.addTransition('C', 1, 'C');
    dfa.addTransition('D', 0, 'B');
    dfa.addTransition('D', 1, 'E');
    dfa.addTransition('E', 0, 'B');
    dfa.addTransition('E', 1, 'C');
    dfa.setFinalStates({'E'});
    dfa.setIntinalStates({'A'});
    vector<vector<char>> minimizedPartitions = minimizeDFA(dfa);

    cout << "Minimized DFA States:" << endl;
    for (const auto &partition : minimizedPartitions)
    {
        cout << "{ ";
        for (char state : partition)
            cout << state << " ";
        cout << "}" << endl;
    }
    map<pair<vector<char>, int>, vector<char>> m;
    for (int i = 0; i < minimizedPartitions.size(); i++)
    {
        char x = minimizedPartitions[i][0];
        vector<char> v1 = findcoresponding(x, 0, dfa, minimizedPartitions);
        vector<char> v2 = findcoresponding(x, 1, dfa, minimizedPartitions);
        m[{minimizedPartitions[i], 0}] = v1;
        m[{minimizedPartitions[i], 1}] = v2;
    }
    cout << "STATE TRANSITION TABLE" << endl;
    cout << "INITIAL STATE" << "  |  " << "SYMBOL" << "  |  " << "NEXT STATE" << endl;

    for (auto it : m)
    {
        cout << "[ ";
        for (char state : it.first.first)
        {
            cout << state << " ";
        }
        cout << "]      |  " << it.first.second << "      |  [ ";

        for (char state : it.second)
        {
            cout << state << " ";
        }
        cout << "]" << endl;
    }

    cout << "Initial States:" << endl;
    for (int k = 0; k < dfa.initalstates.size(); k++)
    {
        for (int i = 0; i < minimizedPartitions.size(); i++)
        {
            for (int j = 0; j < minimizedPartitions[i].size(); j++)
            {
                if (minimizedPartitions[i][j] == dfa.initalstates[k])
                {
                    cout << "{ ";
                    for (char state : minimizedPartitions[i])
                    {
                        cout << state << " ";
                    }
                    cout << "}" << endl;
                    break;
                }
            }
        }
    }

    cout << "Final States:" << endl;
    for (int k = 0; k < dfa.finalStates.size(); k++)
    {
        for (int i = 0; i < minimizedPartitions.size(); i++)
        {
            for (int j = 0; j < minimizedPartitions[i].size(); j++)
            {
                if (minimizedPartitions[i][j] == dfa.finalStates[k])
                {
                    cout << "{ ";
                    for (char state : minimizedPartitions[i])
                    {
                        cout << state << " ";
                    }
                    cout << "}" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}