#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void newList(vector< list<int> > &lst){
    int id = 0;
    cin >> id;
}

void addList(vector< list<int> > &lst){
    int id, num;
    cin >> id >> num;
    lst[id].push_back(num);
}


void mergeList(vector< list<int> > &lst){
    int id1, id2;
    cin >> id1 >> id2;
    lst[id1].splice(lst[id1].end(), lst[id2]);
}


void uniqueList(vector< list<int> > &lst){
    int id;
    cin >> id;
    lst[id].sort();
    lst[id].unique();
}

void printList(vector< list<int> > &lst){
    int id;
    cin >> id;
    lst[id].sort();
    list<int>::const_iterator li;
    li = lst[id].begin();
    while(li != lst[id].end()){
        cout << *li << " ";
        li++;
    }
    cout << endl;
}

int main(){
    int loop = 0;
    cin >> loop;
    vector< list<int> > lst(100000);
    for(int i = 0; i < loop; i++){
        string operation;
        cin >> operation;
        if(operation == "new"){
            newList(lst);
        }
        else if(operation == "unique"){
            uniqueList(lst);
        }
        else if(operation == "add"){
            addList(lst);
        }
        else if(operation == "merge"){
            mergeList(lst);
        }
        else if(operation == "out"){
            printList(lst);
        }
    }
    return 0;
}