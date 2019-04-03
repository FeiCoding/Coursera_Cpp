    Complex & operator =(const char *s){
        char *real = new char[strlen(s) + 1];
        char *imag = new char[strlen(s) + 1];
        int index = 0;
        while(s[index] != '+'){
            real[index] = s[index];
            index++;
        }
        index++;
        int imag_index = 0;
        while(s[index] != 'i'){
            imag[imag_index++] = s[index++];
        }
        r = atoi(real);
        i = atoi(imag);
        delete []real;
        delete []imag;
        return *this;
    }