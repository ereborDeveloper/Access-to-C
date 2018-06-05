class Money
{
private:
	int static const size = 19;
	string values[size];
public:
	Money()
	{
	}
	void setFields(int i, string n)
	{
		values[i] = n;
	}
	void printData()
	{	
		string dt;
		string dh;
		dt = values[16].substr(1, 1);
		if (dt == ".")
		{
			dt = "0"+values[16].substr(0, 9);
		}
		else
		{
			dt = values[16].substr(0, 10);
		}
		dh = dt.substr(4, 1);
		if (dh == ".")
		{
			dh = "0"+dt.substr(3, 7);
		}
		else
		{
			dh = dt.substr(3, 7);
		}
		cout << dt.substr(0,3)+dh <<"\t"<<values[15]<<endl;
	}
	string getValue(int index)
	{
		return values[index];
	}
	friend ostream& operator << (ostream&, const Money&);
	friend istream& operator >> (istream& in, Money& money);
};

ostream& operator << (ostream& out, const Money& money)
{
	out << money.values[0];
	for (int i = 0; i < 19; i++)
	{
		out << " " << money.values[i];
	}
	out << endl;
	return out;
}
istream& operator >> (istream& in, Money& money)
{
	char ch;
	for (int i = 0; i < 19; i++)
	{	
		in >> money.values[i];
	}
	return in;
}