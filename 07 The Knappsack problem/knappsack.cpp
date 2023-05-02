#include<map>
#include<iostream>
#include<sstream>
#include<functional>
#include<set>
#include<vector>

using namespace std;

typedef function<bool(pair<int, int>, pair<int, int>)> densitycomparefunction;

template <typename S>
string greedytake(S start, S end, int N)
{
    stringstream ss;
    int currentWeight = 0;
    int value = 0;
    map<int, int> valuesUsed;
    map<int, int> weightsUsed;
    for (S it = start; it != end; it++)
    {
        while(currentWeight+it->first < N+1)
        {
            currentWeight += it->first;
            value += it->second;
            valuesUsed[it->second]++;
            weightsUsed[it->first]++;
        }
    }
    ss << "knappsacksize = " << N << " got value " << value << " = ";
    map<int,int>::reverse_iterator itV = valuesUsed.rbegin();
    ss << itV->second << "*" << itV->first;
    itV++;
    for (;itV != valuesUsed.rend(); itV++)
    {
        ss << " + " << itV->second << "*" << itV->first;
    }
    ss << " used weight " << currentWeight << "/" << N << " = ";
    map<int,int>::reverse_iterator itW = weightsUsed.rbegin();
    ss << itW->second << "*" << itW->first;
    itW++;
    for (;itW != weightsUsed.rend(); itW++)
    {
        ss << " + " << itW->second << "*" << itW->first;
    }
    return ss.str();
}

string greedytake2(map<int, int>& weight_and_values, int N)
{
    densitycomparefunction densitycompare = [] (pair<int, int> p0, pair<int, int>p1)
    {
        return (((double)p0.second)/p0.first) > (((double)p1.second)/p1.first);
    };
    set<pair<int, int>, densitycomparefunction> valuedensities(weight_and_values.begin(), weight_and_values.end(), densitycompare);
    return greedytake(valuedensities.begin(), valuedensities.end(), N);
}

vector<pair<int, int>> cached;
template <class T>
vector<pair<int, int>> dynamictake(T begin, T end, int N)
{
    if(N > cached.size())
    {
        for (int i = cached.size(); i < N+1; i++)
        {
            int bestWeight = 0;
            int bestValue = 0;
            for (T it = begin; it != end; it++)
            {
                int diff = i-it->first;
                if(diff == 0)
                {
                    bestWeight = it->first;
                    bestValue = it->second;
                    break;
                }
                else if(diff > 0)
                {
                    if(cached[diff].first + it->second > bestValue)
                    {
                        bestValue = cached[diff].first + it->second;
                        bestWeight = cached[diff].second;
                        if(diff < 13) bestWeight += it->first;
                    }
                }
            }
            cached.push_back(make_pair(bestValue, bestWeight));
        }
    }
    vector<pair<int, int>> results;
    int currentWeight = N;
    while(N != 0)
    {
        results.push_back(make_pair(cached[N].first, cached[N].second));
        N -= cached[N].second;
        if(N < 13) break;
    }
    return results;
}
string dynamicSolution(map<int, int> weight_and_values, int N)
{
    vector<pair<int,int>> results = dynamictake(weight_and_values.begin(), weight_and_values.end(), N);
    stringstream ss;
    int currentWeight = 0;
    int value = results.front().first;
    map<int, int> valuesUsed;
    map<int, int> weightsUsed;
    for(const auto& n : results)
    {
        currentWeight += n.second;
        valuesUsed[weight_and_values[n.second]]++;
        weightsUsed[n.second]++;
    }
    ss << "knappsacksize = " << N << " got value " << value << " = ";
    map<int,int>::reverse_iterator itV = valuesUsed.rbegin();
    ss << itV->second << "*" << itV->first;
    itV++;
    for (;itV != valuesUsed.rend(); itV++)
    {
        ss << " + " << itV->second << "*" << itV->first;
    }
    ss << " used weight " << currentWeight << "/" << N << " = ";
    map<int,int>::reverse_iterator itW = weightsUsed.rbegin();
    ss << itW->second << "*" << itW->first;
    itW++;
    for (;itW != weightsUsed.rend(); itW++)
    {
        ss << " + " << itW->second << "*" << itW->first;
    }
    return ss.str();
}

int main()
{
    map<int, int> weight_and_values = {
        {16, 24},
        {19, 29},
        {15, 23},
        {14, 22},
        {13, 21},
        {17, 28},
    };
    for (map<int,int>::reverse_iterator it = weight_and_values.rbegin(); it != weight_and_values.rend(); it++)
    {
        cout << "weight: " << it->first << " value: " << it->second << endl;
    }
    for (int i = 52; i > 12; i--)
    {
        cout << "Weight " << i << ":\n";
        cout << "\tGreedy1: " << greedytake(weight_and_values.rbegin(), weight_and_values.rend(), i) << endl;
        cout << "\tGreedy2: " << greedytake2(weight_and_values, i) << endl;
        cout << "\tDynamic: " << dynamicSolution(weight_and_values, i) << endl;
    }
}