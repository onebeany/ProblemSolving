#include <iostream>
#include <map>

using namespace std;
 
int main() {
    
    int M;
    cin >> M;
    
    map<int, int> bagType; // <weight, num of bags>
    
    int newBag;
    
    while(cin >> newBag){
        // 새로 들어온 bag이 기존 map에 없다면, map에 해당 bag을 추가해주고 개수는 1로 초기화.
        if(bagType.find(newBag) == bagType.end()) bagType[newBag] = 1;
        else bagType[newBag]++;
    }
    
    int carriers = 0;
    if(bagType.empty()){
        cout << carriers;
        return 0;
    }
    
    auto startBag = bagType.begin();
    auto endBag = bagType.end();
    if(endBag != bagType.begin()) --endBag;
    
    while(startBag != endBag){
        
        int leftWeight = M - endBag->first;
        
        // 만약 현재 가장 가벼운 가방의 무게가, M kg에서 가장 무거운 가방의 무게를 제외한 것보다 크다면
        if(startBag->first > leftWeight) {
            carriers += endBag->second;
            endBag--;
        }
        else{
            
            // 비교하고자 하는 두 bagType 중 개수가 더 적은 bagType의 수량
            int interNum;
            int compare = startBag->second - endBag->second;
            
            // 무게가 가장 적은 가방의 개수가 가장 큰 가방의 개수보다 많다면
            if(compare > 0) {
                interNum = endBag->second;
                startBag->second -= interNum; endBag->second -= interNum;
                endBag--;
                carriers += interNum;
            }
            else{
                interNum = startBag->second;
                startBag->second -= interNum; endBag->second -= interNum;
                
                if(compare==0){
                    if(next(startBag) != endBag) startBag++;
                    endBag--;
                }
                else
                    startBag++;
                
                carriers += interNum;
            }
        }
    }
    
    // end of comparing
    if(startBag == endBag){
        if(M/2 >= startBag->first){
            carriers += (startBag->second)/2;
            carriers += (startBag->second)%2;
        }
        else carriers += startBag->second;
    }
    
    cout << carriers;
}
