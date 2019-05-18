class CType{
    int num;
    public:
    void setvalue(int n){
        num = n;
    }
    int operator ++(int){
        return num;
    }
    friend ostream& operator <<(ostream& o, const CType &ct);

};

ostream& operator <<(ostream& o, const CType &ct){
        int nn = ct.num * ct.num;
        o << nn;
        return o;
}