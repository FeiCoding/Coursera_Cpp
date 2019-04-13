class MyString :public string {
public:
	MyString(const char *p):string(p){}
	MyString(const string s):string(s){}
	MyString() :string() {}
	MyString(MyString &s):string(s){}
	MyString operator()(int i, int j) {
		return this->substr(i, j);
	}
	
};