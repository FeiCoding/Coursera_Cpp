// 在此处补充你的代码
struct Print{
    void operator()(A& a){
        cout << a << " ";
    }
};
template <class T, class Func>
void Show(T init, T end, Func fun){
    for(;init != end; init++){
        fun(*init);
    }
}

template <class T>
struct MyLarge{
    bool operator()(const T &t1, const T &t2){
        return t1.get_name() < t2.get_name();
    }
};

bool operator <(const A &a1, const A &a2){
    return a1.get_size() < a2.get_size();
}