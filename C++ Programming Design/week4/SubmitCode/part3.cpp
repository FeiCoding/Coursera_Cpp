class Array2{
    int row;
    int col;
    int **ptr;
    public:
    Array2(int i = 0, int j = 0):row(i),col(j){
        if(row == 0 || col == 0)
            ptr = NULL;
        else{
            ptr = new int*[row];
            for(int i = 0; i < row; i++)
                ptr[i] = new int[col];
        }
    }
    ~Array2(){
        if(ptr){
            for(int i = 0; i < row; i++)
                delete []ptr[i];
            delete []ptr;
        }
    }
    int *operator[](int i){ return ptr[i]; }
    int &operator()(int i, int j){ return ptr[i][j]; }
    Array2 &operator =(const Array2 &ar){
        if(ar.ptr == ptr){
            return *this;
        }
        if(ptr){
            for(int i = 0; i < row; i++)
                delete []ptr[i];
            delete []ptr;
        }
        if(row < ar.row || col < ar.col){
            row = ar.row;
            col = ar.col;
            ptr = new int * [row];
            for(int i = 0; i < row; i++){
                ptr[i] = new int[col]; 
                memcpy(ptr[i], ar.ptr[i], sizeof(int)*ar.col);
            }
            return *this;
        }
    }

};