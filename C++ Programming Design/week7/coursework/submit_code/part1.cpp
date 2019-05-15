template <class T>
class CArray3D{
    T ***p;
    T x;
    T y;
    T z;
    public:
    CArray3D(int x, int y, int z):x(x),y(y),z(z){
        if(x == 0 || y == 0 || z == 0){
            p = NULL;
        }
        p = new T**[x];
        for(int i = 0; i < x; i++){
            p[i] = new T*[y];      
            for(int j = 0; j < y; j++){
                p[i][j] = new T[z];
            }
        }
        
    }
    ~CArray3D(){
        if(p){
            for(int i = 0; i < x; i++){
                for(int j = 0; j < y; j++){
                    delete []p[i][j];
                }
                delete [] p[i];
            }
        }
    }
    
    T** operator [](int i){
        return p[i];
    }

};