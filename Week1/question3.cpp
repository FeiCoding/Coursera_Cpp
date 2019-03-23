#include <iostream>
using namespace std;
#include <iomanip> 
// 输入
// 系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）

int main(){
    int id;
    int n;
    float recipeCount[3] = {0};
    float totalCount[3] = {0};
    for(int i = 0; i < 3; i++){
        cin >> id >> n;
        char type = '\0';
        float num = 0;
        for(int j = 0; j < n; j++){
            cin >> type >> num;
            totalCount[id - 1] += num;
            if(type == 'A'){
                recipeCount[0] += num;
            }else if(type == 'B'){
                recipeCount[1] += num;
            }else if(type == 'C'){
                recipeCount[2] += num;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ' ' << totalCount[i] << endl;
    }
    for(int i = 0; i < 3; i++){
        char type = '\0';
        if(i == 0){
            type = 'A';
        }else if(i == 1){
            type = 'B';
        }else if(i == 2){
            type = 'C';
        }
        cout << type << ' ' << fixed<<setprecision(2) << recipeCount[i] << endl;
    }
    return 0;
}