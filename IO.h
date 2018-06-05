template <class T>
class IO
{
	private:
		deque<T> container;
public:
	IO()
	{
	}
	IO(string f)
	{
		getFromFile(f);
	}
	void getFromFile(string file) 
	{
		cout << "Загружаем " << file << endl;
		ifstream myfile(file);
		istream_iterator<T> file_iter(myfile);
		istream_iterator<T> end_of_stream;
		copy(file_iter, end_of_stream, back_inserter(container));
		cout << "Загружено " << container.size() << " записей" << endl;
	}
	void toScreen(string shift)
	{
		cout << shift;
		ostream_iterator<T> ositer(cout, shift.c_str());
		copy(container.begin(), container.end(), ositer);
		cout << endl << endl;
	}
	deque<T> getDeque()
	{
		return container;
	}
	void setDeque(deque<T> a)
	{
		container = a;
	}
	void setVector(vector<T> v)
	{
		container = v;
	}
	void toFile(string file)
	{
		ofstream myfile(file);
		ostream_iterator<T> ositer(myfile, "");
		copy(container.begin(), container.end(), ositer);
		cout << container.size() << " записей помещено в файл " << file << endl;
	}
	void resultToFile(string file)
	{
			deque<Result> output;
			deque<Result>::iterator it = output.begin();
			int k = container.size();
			for (int i = 0; i<k; i++)
			{
				Result current = container.front();
				current.setOutput("file");
				container.pop_front();
				container.push_back(current);
			}
			ofstream myfile(file);
			ostream_iterator<T> ositer(myfile, "");
			copy(container.begin(), container.end(), ositer);
			cout << container.size() << " записей помещено в файл " << file << endl;
	}
	
	map<T, int> toRandomMap(int r)
	{
		map<Person, int> display;
		for (int i = 0; i < container.size(); i++)
		{
			Person per = container[i];
			per.setId(i);
			int rar = rand() % r + 1;
			per.setVar(rar);
			display.insert(make_pair(per, i));
		}
		return display;
	}
	void mapToDeque(map<T, int>& mp)
	{
		container.clear();
		map<Person, int>::iterator iter;
		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			T el= iter->first;
			cout << "" << el;
			container.push_back(el);
		}
	}
};
	