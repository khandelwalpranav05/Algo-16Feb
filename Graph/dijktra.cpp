#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

void dijkstra(unordered_map<char, vector<pair<char, int> > > &adjList) {

	char src = 'A';

	unordered_map<char, int> dist;

	for (int i = 65; i <= 70; i++) {
		char ch = i;
		dist[ch] = INT_MAX;
	}

	dist[src] = 0;

	priority_queue< pair<int, char>, vector<pair<int, char> >, greater<pair<int, char> > > pq;

	pq.push({0, src});

	while (!pq.empty()) {
		auto temp = pq.top();
		pq.pop();

		char u = temp.second;

		for (auto neighbor : adjList[u]) {

			char v = neighbor.first;
			int wt = neighbor.second;

			if (dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				pq.push({dist[v], v});
			}
		}
	}

	cout << "************ Distance ************" << endl;

	for (int i = 65; i <= 70; i++) {
		char ch = i;
		cout << "Distance of " << ch << " from src is " << dist[ch] << endl;
	}
}

void display(unordered_map<char, vector<pair<char, int> > > &adjList) {
	for (auto node : adjList) {

		cout << node.first << " -> ";

		for (auto neighbor : node.second) {
			cout << "( " << neighbor.first << " ," << neighbor.second << " ) ,";
		}
		cout << endl;
	}
}

void addEdge(unordered_map<char, vector<pair<char, int> > > &adjList, char u, char v, int wt) {
	adjList[u].push_back(make_pair(v, wt));
}

void createGraph(unordered_map<char, vector<pair<char, int> > > &adjList) {

	addEdge(adjList, 'A', 'B', 5);
	addEdge(adjList, 'A', 'D', 2);
	addEdge(adjList, 'D', 'B', 2);
	addEdge(adjList, 'B', 'C', 1);
	addEdge(adjList, 'D', 'E', 6);
	addEdge(adjList, 'C', 'E', 1);
	addEdge(adjList, 'C', 'F', 3);
	addEdge(adjList, 'E', 'F', 8);

}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

	unordered_map<int, vector<pair<int, int>>> adjList;

	for (auto val : flights) {
		int u = val[0];
		int v = val[1];
		int wt = val[2];

		adjList[u].push_back(make_pair(v, wt));
	}

	priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

	pq.push({0, {src, -1}});

	while (!pq.empty()) {

		auto temp = pq.top();
		pq.pop();

		int cost = temp.first;
		int u = temp.second.first;
		int stops = temp.second.second;

		if (u == dst) {
			return cost;
		}

		if (stops < K) {
			for (auto neighbor : adjList[u]) {
				int neighborCost = cost + neighbor.second;
				int v = neighbor.first;
				pq.push({neighborCost, {v, stops + 1}});
			}
		}
	}

	return -1;
}

int networkDelayTime(vector<vector<int>>& times, int N, int K) {

	unordered_map<int, vector<pair<int, int>>> adjList;

	for (auto val : times) {
		int u = val[0];
		int v = val[1];
		int wt = val[2];

		adjList[u].push_back(make_pair(v, wt));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	unordered_map<int, int> dist;
	for (int i = 1; i <= N; i++) dist[i] = INT_MAX;

	dist[K] = 0;

	pq.push({0, K});

	while (!pq.empty()) {

		auto temp = pq.top();
		pq.pop();

		int u = temp.second;

		for (auto neighbor : adjList[u]) {

			int v = neighbor.first;
			int wt = neighbor.second;

			if (dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				pq.push({dist[v], v});
			}

		}

	}

	int maxValue = -1;
	for (int i = 1; i <= N; i++) maxValue = max(maxValue, dist[i]);

	return maxValue == INT_MAX ? -1 : maxValue;
}

int main() {

	unordered_map<char, vector<pair<char, int> > > adjList;

	createGraph(adjList);

	display(adjList);

	dijkstra(adjList);

	return 0;
}