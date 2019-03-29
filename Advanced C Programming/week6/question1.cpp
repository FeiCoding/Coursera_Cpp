#include <iostream>
#include <iomanip>
using namespace std;


// 描述
// 某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。

// 现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。

// 输入
// 第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a

// 紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。

// 每个病人的疾病严重程度都不一样。

// 输出
// 要求按照病人的严重程度输出住在重症病房里的病人的编号

int main()
{
    int m = 0;
    float a = 0.0;
    cin >> m >> a;
    int count = 0;
    int code_a[50];
    float num_a[50];
    for (int i = 0; i < m; i++)
    {
        int code = 0;
        float num = 0.0;
        cin >> code >> num;
        if (num > a)
        {
            code_a[count] = code;
            num_a[count] = num;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "None." << endl;
        return 0;
    }
    for(int i = count; i >= 0; i--){
        for(int j = 0; j < i - 1; j++){
            if(num_a[j + 1] > num_a[j]){
                int temp = code_a[j + 1];
                code_a[j + 1] = code_a[j];
                code_a[j] = temp;

                float temp2 = num_a[j + 1];
                num_a[j + 1] = num_a[j];
                num_a[j] = temp2;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << setw(3) << setfill('0') << code_a[i] << ' ';
        cout << fixed << setprecision(1) << num_a[i] << endl;
    }
    return 0;
}