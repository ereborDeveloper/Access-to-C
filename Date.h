class Date
{
private:
	int hh;
	int mm;
	int ss;
public:
	Date()
	{
		hh = 0;
		mm = 0;
		ss = 0;
	}
	Date(int h, int m, int s)
	{
		hh = h;
		mm = m;
		ss = s;
	}
	void showData()
	{
		cout << hh<<":" << mm<<":" << ss;
	}
	void getData(int h,int m,int s)
	{
		hh=h;
		mm=m;
		ss=s;
	}
};