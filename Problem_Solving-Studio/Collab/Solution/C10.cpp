#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Circle {
    double x;
    double r;
};

double getRadiusTouched(Circle &existCircle, Circle &currCircle){
    return (existCircle.x - currCircle.x) * (existCircle.x - currCircle.x) / (4 * existCircle.r);
}

int main() {
    
    int n;
    cin >> n;
    
    Circle circles[n];
    int maxRadiusIndex = 0; // Index of a circle which has the max radius among existing circles.
    for(int i = 0 ; i < n ; i++){
        
        cin >> circles[i].x >> circles[i].r;
        
        double smallestRadius = circles[i].r;

        for(int j = maxRadiusIndex ; j < i ; j++){
            smallestRadius = min(smallestRadius, getRadiusTouched(circles[j], circles[i]));

        }

        circles[i].r = smallestRadius;
        
        if(circles[i].r >= circles[maxRadiusIndex].r) {
            maxRadiusIndex = i;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        printf("%.3lf\n", circles[i].r);
    }
}
