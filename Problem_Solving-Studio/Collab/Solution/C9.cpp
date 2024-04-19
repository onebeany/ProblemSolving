#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxWeight = 0;

void findWeightNodeCluster(vector<int> currCluster, vector<int> currLinks, vector<int> exclusion, vector<int> * adjList, int * weights){
    
    int maxWeightCurrCluster = 0;
    for(int node : currCluster){
        maxWeightCurrCluster += weights[node];
    }
    maxWeight = max(maxWeight, maxWeightCurrCluster);
    
    if(currLinks.empty()) return;
    
    for(int link : currLinks){
        if(find(exclusion.begin(), exclusion.end(), link) != exclusion.end()) {
            continue;
        }
        
        bool isCandidateNodeForCluster = true;

        for(int node : currCluster){
            if(find(adjList[link].begin(), adjList[link].end(), node) == adjList[link].end()) {
                isCandidateNodeForCluster = false;
                break;
            }
        }
        
        if(isCandidateNodeForCluster){
            vector<int> newCurrCluster, newCurrLinks;
            newCurrCluster = currCluster;
            newCurrCluster.push_back(link);
            for(int j : adjList[link]) newCurrLinks.push_back(j);
            findWeightNodeCluster(newCurrCluster, newCurrLinks, exclusion, adjList, weights);
        }
    }

}

int main () {
    
    int n, b;
    cin >> n >> b;
    
    int weights[n];
    for(int i = 0 ; i < n ; i++){
        cin >> weights[i];
    }
    
    vector<int> adjList[n];
    for(int i = 0 ; i < b ; i++){
        int node1, node2;
        cin >> node1 >> node2;
        adjList[node1-1].push_back(node2-1);
        adjList[node2-1].push_back(node1-1);
    }
    
    vector<int> exclusion;
    for(int i = 0 ; i < n ; i++){
        vector<int> currCluster, currLinks;
        currCluster.push_back(i);
        for(int j : adjList[i]){
            currLinks.push_back(j);
        }
        findWeightNodeCluster(currCluster, currLinks, exclusion, adjList, weights);
        exclusion.push_back(i);
    }
    
    cout << maxWeight;
    return 0;
}
