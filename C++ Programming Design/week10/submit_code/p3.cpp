int sum(const int* a, int n, int (*func)(int n)){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += func(a[i]);
    }
    return sum;
}