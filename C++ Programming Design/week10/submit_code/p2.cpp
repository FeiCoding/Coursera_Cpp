Number(const Number &n){
        num = n.num;
    }

    int& value(){
        return num;
    }

    void operator +(const Number &n){
        num = num + n.num;
    }