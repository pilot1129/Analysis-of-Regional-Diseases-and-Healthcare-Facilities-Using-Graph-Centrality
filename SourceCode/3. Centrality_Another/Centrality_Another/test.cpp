#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<istream>
#include<unordered_map>
#include<utility>
#include<functional>
using namespace std;

vector<string> csv_read_row(istream &file, char delimiter);
string Test(string a, string b);

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};

int main()
{
	ifstream Data("Data.csv"); // ������ ������ -> content[0] = ��ȣ_��ȣ / content[1] = ��
	ofstream MData("Medical.csv"); // ������
	vector<string> content;// �� �ٺ� ������
	unordered_map<pair<string, string>, int, pair_hash> host; // �����[����-�����ڵ� , ��] �ٸ� ���� ���� ����.
	string First; // ������
	string Second; // ������
	string Result;
	int count;
	int location;

	cout << "�۾�����" << endl;

	while (Data.good())// ����� ������
	{
		content = csv_read_row(Data, ','); // ���پ� �о��
		count = stoi(content[1]);

		//���� ����
		location = content[0].find("_");
		First = content[0].substr(0, location); // 0���� location����
		Second = content[0].substr(location + 1, 20); // location���� ������

		First.erase(std::find(First.begin(), First.end(), '_'));
		First.erase(std::find(First.begin(), First.end(), '_'));
		Second.erase(std::find(Second.begin(), Second.end(), '_'));
		Second.erase(std::find(Second.begin(), Second.end(), '_'));

		if (First.length() == 1)
			First = First + "00";
		if (Second.length() == 1)
			Second = Second + "00";

		pair<string, string> tmpair = make_pair(First, Second);
		++host[tmpair]; // �� �ϳ� ����
	}


	for (auto it = host.begin(); it != host.end(); ++it)
	{
		MData << it->first.first << "," << it->first.second << "," << it->second << endl;
	}
	/*
	//map ���� ���
	for (int i = 1; i < 27; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			unordered_map<pair<int, int>, int, pair_hash>::const_iterator got = host.find(make_pair(i, j));
			MData << i << "," << j << "," << got->second << endl;
		}
	}
	*/

	return 0;
}

vector<string> csv_read_row(istream &file, char delimiter)
{
	stringstream ss;
	bool inquotes = false;
	vector<string> row;

	while (file.good())
	{
		char c = file.get();
		if (!inquotes && c == '"')
			inquotes = true;
		else if (inquotes && c == '"')
		{
			if (file.peek() == '"')
				ss << (char)file.get();
			else
				inquotes = false;
		}
		else if (!inquotes&& c == delimiter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && (c == '\r' || c == '\n'))
		{
			if (file.peek() == '\n')
				file.get();
			row.push_back(ss.str());
			return row;
		}
		else
			ss << c;
	}
}
