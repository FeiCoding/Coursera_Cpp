#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

int main(){
    int n = 0;
    cin >> n;
    Point p[100];
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    Point maxPoint[100];
    int count = 0;
    for(int i = 0; i < n; i ++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(j == i){
                continue;
            }
            else if(p[i].x <= p[j].x && p[i].y <= p[j].y){
                flag = false;
                break;
            }
        }
        if(flag){
            maxPoint[count++] = p[i];
        }
    }
    for(int i = count; i >= 0; i--){
        for(int j = 0; j <i - 1; j++){
            if(maxPoint[j].x > maxPoint[j + 1].x){
                Point temp = maxPoint[j];
                maxPoint[j] = maxPoint[j + 1];
                maxPoint[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < count; i++){
        cout << '(' << maxPoint[i].x << ',' << maxPoint[i].y << ')';
        if(i != count - 1){
            cout << ',';
        }
    }
    cout << endl;
    return 0;
}