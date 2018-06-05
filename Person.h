class Person
{
private:
	int id;
	string name;
	string surname;
	int var;
	friend ostream& operator << (ostream&, const Person&);
	friend istream& operator >> (istream& in, Person& person);
public:
	Person(int i)
	{
		id=i;
	}
	Person()
	{
	}
	int getId()
	{
		return id;
	}
	void setId(int i)
	{
		id = i;
	}
	void setVar(int v)
	{
		var = v;
	}
	int getVar()
	{
		return var;
	}
	bool operator < (const Person& per) const
	{
		return id < per.id;
	}
	string getData()
	{
		return name + " " + surname;
	}
};

ostream& operator << (ostream& out, const Person& person)
{
	string tab;
	tab = person.name + person.surname;
	if (tab.size() < 15) tab = "\t\t";
	else tab = "\t";
	out << person.name << " " << person.surname << tab<< person.var<< endl;
	return out;
}
istream& operator >> (istream& in, Person& person)
{
	in >> person.name >> person.surname;
	return in;
}