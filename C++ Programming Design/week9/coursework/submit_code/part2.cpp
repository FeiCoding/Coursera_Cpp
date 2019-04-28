template <class T>
class CMyistream_iterator{
    istream &in;
    T content;

    public:
        CMyistream_iterator(istream &i):in(i){
            in >> content;
        }
        T operator *(){
            return content;
        }
        void operator ++(int){ // ++(int)重载后缀的++
            in >> content;
        }
};