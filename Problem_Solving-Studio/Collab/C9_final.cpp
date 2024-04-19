#include <iostream>
#include <vector>

using namespace std;

int getWeightNodeCluster(vector<int> currCluster, vector<vector<int>> adjList, vector<int> exclusion, int * weights){
    
    int maxWeightCurrCluster = 0;
    for(int i = 0 ; i < currCluster.size() ; i++){
        maxWeightCurrCluster += weights[currCluster[i]];
    }
    
    int baseNode = (int) currCluster.back();
    
    cout << "Base Node: " << baseNode + 1 << endl;
    cout << "Current Cluster set: ";
    for(auto& node : currCluster){
        cout << node+1 << " ";
    }
    cout << "| maxWeightCurrCluster: " << maxWeightCurrCluster;
    cout << endl;
    
    
    for(int i = 0 ; i < adjList.size(); i++){
        bool isCandidateNodeForCluster = true;
        if((i == baseNode) || (find(exclusion.begin(), exclusion.end(), i) != exclusion.end())) {
            continue;
        }

        for(int j = 0 ; j < (int) currCluster.size() ; j++){
            if(find(adjList[i].begin(), adjList[i].end(), currCluster[j]) == adjList[i].end()) {
                isCandidateNodeForCluster = false;
                break;
            }
        }
        
        if(isCandidateNodeForCluster){
            currCluster.push_back(i);
            int weightNodeCluster = getWeightNodeCluster(currCluster, adjList, exclusion, weights);
            maxWeightCurrCluster = max(maxWeightCurrCluster, weightNodeCluster);
        }
    }
    
    
    return maxWeightCurrCluster;
}

int main () {
    
    int n, b;
    cin >> n >> b;
    
    int weights[n];
    for(int i = 0 ; i < n ; i++){
        cin >> weights[i];
    }
    
    vector<vector<int>> adjList(n);
    for(int i = 0 ; i < b ; i++){
        int node1, node2;
        cin >> node1 >> node2;
        adjList[node1-1].push_back(node2-1);
        adjList[node2-1].push_back(node1-1);
    }
    
    cout << "\n<adjList>" << endl;
    for(int i = 0; i < n ; i++){
        cout << "Node " << i+1 << ": ";
        for(auto node: adjList[i]){
            cout << node + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    int maxWeight = 0;
    vector<int> exclusion;
    for(int i = 0 ; i < n ; i++){
        vector<int> currCluster;
        currCluster.push_back(i);

        int weightNodeCluster = getWeightNodeCluster(currCluster, adjList, exclusion, weights);
        maxWeight = max(maxWeight, weightNodeCluster);
        
        exclusion.push_back(i);
        cout << "\n-------Next Node--------\n\n";
    }
    
    cout << maxWeight;
    return 0;
}
