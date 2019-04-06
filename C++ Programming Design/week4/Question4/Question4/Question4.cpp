#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void delete_zero(string &num) {
	int index = 0;
	while (num[index] == '0') {
		index++;
	}
	if (index == num.length())
		num = "0";
	else
		num = num.substr(index);
}

void swap(string &s1, string &s2) {
	string temp = s1;
	s1 = s2;
	s2 = temp;
}


int padding(string &s1, string &s2) {
	int maxLen = s1.length() > s2.length() ? s1.length() : s2.length();
	while (s1.length() < maxLen) {
		s1.insert(0, "0");
	}
	while (s2.length() < maxLen) {
		s2.insert(0, "0");
	}
	return maxLen;
}

class BigNumber {
	string num;
	char sign;
public:
	BigNumber(string n_str = "0") {
		if (n_str[0] == '-') {
			num = n_str.substr(1, n_str.length() - 1);
			sign = '-';
		}
		else {
			sign = '+';
			num = n_str;
		}
		delete_zero(num);
	}
	BigNumber(const BigNumber &bn) {
		num = bn.num;
		sign = bn.sign;
		if (num == "0") {
			sign = '+';
		}
	}
	BigNumber operator +(const BigNumber &bn);
	BigNumber operator -(const BigNumber &bn);
	BigNumber operator *(const BigNumber &bn);
	BigNumber operator /(const BigNumber &bn);
	friend ostream& operator <<(ostream &o, const BigNumber &bn);
};



ostream& operator <<(ostream &o, const BigNumber &bn){
	if (bn.sign == '+') {
		o << bn.num;
	}
	else {
		o << "-" << bn.num;
	}
	return o;
}
BigNumber BigNumber::operator +(const BigNumber &bn) {
	if (bn.num == "0") {
		return *this;
	}
	else if (num == "0") {
		return BigNumber(bn);
	}
	else if (sign == '-' && bn.sign == '+') {
		BigNumber temp1(bn);
		BigNumber temp2(*this);
		temp2.sign = '+';
		return temp1 - temp2;
	}
	else if (sign == '+' && bn.sign == '-') {
		BigNumber temp(bn);
		temp.sign = '+';
		return *this - temp;
	}
	else {
		string t_num = bn.num;
		int maxLen = padding(num, t_num);
		int cur = 0;
		string result = "";
		for (int i = maxLen - 1; i >= 0; i--) {
			int add1 = num[i] - '0';
			int add2 = t_num[i] - '0';
			int res = (add1 + add2 + cur) % 10;
			cur = (add1 + add2 + cur) / 10;
			result.insert(0, to_string(res));
		}
		if (cur) {
			result.insert(0, "0");
		}
		BigNumber temp(result);
		temp.sign = sign;
		return temp;
	}
}
BigNumber BigNumber::operator -(const BigNumber &bn) {
	if (bn.num == "0") {
		return *this;
	}
	else if (num == "0") {
		BigNumber temp(bn);
		if (bn.sign == '-')
			temp.sign = '+';
		else
			temp.sign = '-';
		return temp;
	}
	if (sign == '-' && bn.sign == '+') {
		BigNumber temp(bn);
		temp.sign = '-';
		return temp + *this;
	}
	else if (sign == '+' && bn.sign == '-') {
		BigNumber temp(bn);
		temp.sign = '+';
		return temp + *this;
	}
	else {
		string t_num = bn.num;
		if (t_num == num) {
			return BigNumber("0");
		}
		char new_sign = '+';
		int maxLen = padding(num, t_num);
		if (num.length() < t_num.length() || num < t_num) {
			new_sign = '-';
			swap(num, t_num);
		}
		while (t_num.length() < maxLen) {
			t_num.insert(0, "0");
		}
		int cur = 0;
		string result = "";
		for (int i = maxLen - 1; i >= 0; i--) {
			int min1 = num[i] - '0';
			int min2 = t_num[i] - '0';
			int res = 0;
			if (min1 - cur >= min2) {
				res = min1 - min2 - cur;
				cur = 0;
			}
			else {
				res = min1 + 10 - min2 - cur;
				cur = 1;
			}
			result.insert(0, to_string(res));
		}
		BigNumber temp(result);
		temp.sign = new_sign;
		return temp;
	}

}
BigNumber BigNumber::operator *(const BigNumber &bn) {
	BigNumber result;
	string t_num = bn.num;
	int res = 0;
	BigNumber temp;
	for (int i = 0; i < t_num.length(); i++) {
		temp.num = "0";
		for (int j = 0; j < t_num[i] - '0'; j++) {
			temp = temp + *this;
		}
		temp.num.resize(temp.num.length() + t_num.length() - 1 - i, '0');
		result = result + temp;
	}
	if (sign == bn.sign)
		result.sign = '+';
	else
		result.sign = '-';
	return result;
}
BigNumber BigNumber::operator /(const BigNumber &bn) {
	if(bn.num == "0"){
		return bn;
	}
	string operand1 = num;
	string operand2 = bn.num;
	BigNumber quotient;
	quotient.sign = '+';
	int maxLen = padding(operand1, operand2);
	if (operand1.length() < operand2.length() || operand1 < operand2)
	{
		quotient.num = "0";
		return quotient;
	}

	int m = operand1.length() - operand2.length();
	for (int i = 0; i < m; i++) {
		operand2.insert(0, "0");
	}
	BigNumber dividend(operand1);
	BigNumber divisor(operand2);
	quotient.num = "";
	for (int i = 0; i <= m; i++)
	{
		int tmp = 0;
		while ((dividend - divisor).sign != '-')
		{
			tmp++;
			dividend = dividend - divisor;
		}
		quotient.num.insert(0, to_string(tmp));
		divisor.num.resize(divisor.num.length() - 1);
	}
	while (quotient.num[0] == '0')
	{
		quotient.num.erase(quotient.num.begin());
	}

	if (sign == bn.sign)
		quotient.sign = '+';
	else
		quotient.sign = '-';
	return quotient;
}

int main() {
		string s1, s2;
		char Operator;
		cin >> s1 >> Operator >> s2;
		BigNumber a(s1);
		BigNumber b(s2);
		BigNumber result;

		switch (Operator)
		{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		}
		cout << result << endl;
		return 0;
}
