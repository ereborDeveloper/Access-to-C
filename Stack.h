class Stack
{
private:
	static const int MAX = 8;
	COORD st[MAX];
	int s = 0;
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(COORD var)
	{
		s++;
		st[++top] = var;
		
	}
	COORD pop()
	{
		s--;
		cout << "\n����� � ������������ (" << st[top].X << ", " << st[top].Y << ") ��������� �� �����";
		return st[top--];
	}
	int size()
	{
		return s;
	}
};