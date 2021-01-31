#include "Util.h"
#include <string>
string convertDoubleToString(double x)
{
	string s = to_string(x);
	int decimalSepPos = s.find('.');
	if (decimalSepPos != string::npos)
	{
		int len = s.length() - 1;
		while (s[len] == '0')
		{
			len--;
		}
		if (len == decimalSepPos)
		{
			s = s.substr(0, len);
		}
		else
		{
			s = s.substr(0, len + 1);
		}
	}
	return s;
}

bool verifiDate(string x)
{
	string delim = "/";
	int pos = x.find(delim);
	int  zi= stod(x.substr(0, pos));
	x = x.erase(0, pos + 1);
	pos = x.find(delim);
	int  luna = stod(x.substr(0, pos));
	x = x.erase(0, pos + 1);
	 pos = x.find(delim);
	int  an = stod(x.substr(0, pos));
	x = x.erase(0, pos + 1);
	int ok1=1, ok2=1, ok3=1;
	if (zi > 31)
		ok1 = 0;
	if (luna > 12)
		ok2 = 0;
	if (an < 1999)//consider ca magazinu s a deschis in 2000
		ok3 = 0;
	if (ok1 == ok2 == ok3 == 1)
		return true;
	return false;
}
