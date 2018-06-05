class Names
{
private:
	int id;
	string name;
public:
	Names()
	{
	}
	void setFields(int i, string n)
	{
		id = i;
		name = n;
	}
	void printData()
	{
		cout <<name<<endl;
	}
	int getId()
	{
		return id;
	}
	string getName()
	{
		return name;
	}
	string toString()
	{
		string str = id + ";" + name;
		return str;
	}
	friend ostream& operator << (ostream&, const Names&);
	friend istream& operator >> (istream& in, Names& name);
	bool operator > (Names& one)
	{
		if (this->id > one.id) return true;
		else return false;
	}
};

ostream& operator << (ostream& out, const Names& name)
{
	out << name.id << "\t" << name.name<<endl;
	return out;
}
istream& operator >> (istream& in, Names& name)
{
	char ch;
	in >> name.id >> ch >> ch >> ch >> ch; getline(in, name.name);
	return in;
}