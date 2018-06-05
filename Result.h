class Result
{
private:
	//to Screen by default
	boolean toScreen=true;
	int regn;
	int num_sc;
	string dt;
	string iitg;
public:
	Result(int r,int n, string d, string i)
	{
		regn = r;
		num_sc = n;
		dt=d;
		iitg=i;
	}
	string toString()
	{
		string str = regn + ";";
		str += num_sc + ";" + dt + ";" + iitg;
		return str;
	}
	void setOutput(string way)
	{
		if (way == "screen")
		{
			toScreen = true;
		}
		if (way == "file")
		{
			toScreen = false;
		}
	}
	friend ostream& operator << (ostream&, const Result&);
	friend istream& operator >> (istream& in, Result& res);
};

ostream& operator << (ostream& out, const Result& res)
{
	string dt;
	string dh;
	dt = res.dt.substr(1, 1);
	if (dt == ".")
	{
		dt = "0" + res.dt.substr(0, 9);
	}
	else
	{
		dt = res.dt.substr(0, 10);
	}
	dh = dt.substr(4, 1);
	if (dh == ".")
	{
		dh = "0" + dt.substr(3, 7);
	}
	else
	{
		dh = dt.substr(3, 7);
	}
	if (res.toScreen)
	{
		out << dt.substr(0, 3) + dh << "\t" << atoi(res.iitg.c_str()) << endl;
	}
	else out << res.regn << "\t" << res.num_sc << "\t" << dt.substr(0, 3) + dh << "\t" << atoi(res.iitg.c_str()) << endl;
	return out;
}

istream& operator >> (istream& in, Result& res)
{
	char ch;
	in >> res.num_sc >> ch >> res.dt >> ch >> res.iitg >> ch >> res.regn;
	
	return in;
}