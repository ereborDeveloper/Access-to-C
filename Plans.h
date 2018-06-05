class Plans
{
private:
	int static const fields = 3;
	string values[fields];
public:
	Plans()
	{
	}
	void setFields(int i, string n)
	{
		values[i] = n;
	}
	void printData()
	{
		for (int i = 0; i<3; i++)
			cout << values[i] << " ";
		cout << endl;
	}
	int getNumberOfFields()
	{
		return fields;
	}
	string getValue(int index)
	{
		return values[index];
	}
	friend ostream& operator << (ostream&, const Plans&);
	friend istream& operator >> (istream& in, Plans& plan);
};

ostream& operator << (ostream& out, const Plans& plan)
{
	out << plan.values[0];
	for (int i = 0; i < 2; i++)
	{
		out<<";"<< plan.values[i];
	}	
	return out;
}
istream& operator >> (istream& in, Plans& plan)
{
	char ch;
	for (int i = 0; i < 2; i++)
	{
		in  >> plan.values[i];
	}
	getline(in, plan.values[2]);
	return in;
}