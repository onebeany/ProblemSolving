#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<char, vector<string>> graph;
vector<string> result;
vector<bool> visited;
map<string, int> wordIndex;
map<char, vector<string>> end_graph;

void findPossiblePath(char start) {
    if(graph[start].empty()) return;
    for (auto& word : graph[start]) {
        if (!visited[wordIndex[word]]) {
            visited[wordIndex[word]] = true;
            findPossiblePath(word.back());
            if(end_graph.count(word.front())){
                result.push_back(word);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    visited.resize(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        wordIndex[words[i]] = i;
    }
    sort(words.begin(), words.end());
    
    for (const string& word : words) {
        graph[word.front()].push_back(word);
        end_graph[word.back()].push_back(word);
    }

    for (auto& entry : graph) {
        sort(entry.second.begin(), entry.second.end());
    }
    
    int start = -1;

    for(int i = 0 ; i < (int) words.size() ; i++){
        if((end_graph.count(words[i].front()) == 0)
           || ( ((int)end_graph[words[i].front()].size() == 1) && end_graph[words[i].front()].front() == words[i]) ){
            start = i;
            break;
        }
    }
    
    if(start != -1){
        findPossiblePath(words[start].front());
    }
    else{
        findPossiblePath(words[0].front());
    }
    
    if (result.size() == words.size()) {
        reverse(result.begin(), result.end());
        for (const string& word : result) {
            cout << word << endl;
        }
    } else {
        cout << "0";
    }

    return 0;
}
