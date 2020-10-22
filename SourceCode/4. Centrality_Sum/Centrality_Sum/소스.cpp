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
int Test(string a);


int main()
{
	ifstream Data("0.csv"); // 지역별 데이터 -> content[0] = 번호_번호 / content[1] = 수
	ofstream MData("1.csv"); // 정리본
	vector<string> content;// 매 줄별 데이터
	unordered_map<int, float> Final;
	string First;
	int Result;
	float centrality;


	cout << "작업시작" << endl;

	for (int i = 1; i < 27; i++)
	{
		Final.insert({i, 0});
	}

	
	while (Data.good())// 제대로 열리면
	{
		content = csv_read_row(Data, ','); // 한줄씩 읽어라
		centrality = stof(content[6]); // Centrality 저장
		First = content[0];

		Result = Test(First);//계통 분류
		Final[Result] = Final[Result] + centrality; // 값 
	}

	for (auto it = Final.begin(); it != Final.end(); ++it)
	{
		MData << it->first << "," << it->second << endl;
	}

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

int Test(string a)
{
	string result;
	string tempstr;
	int res1;

	tempstr = a.at(1) + a.at(2);
	int tempint = atoi(tempstr.c_str());

	switch (a.at(0))
	{
	case 'A':
	{
		if (tempint < 10)
			res1 = 1;
		else if (tempint < 20)
			res1 = 20;
		else if (tempint < 50)
			res1 = 1;
		else if (tempint < 65)
			res1 = 15;
		else if (tempint < 70)
			res1 = 10;
		else if (tempint < 75)
			res1 = 1;
		else if (tempint < 80)
			res1 = 14;
		else if (tempint < 90)
			res1 = 2;
		else
			res1 = 13;
		break;
	}
	case 'B':
	{
		if (tempint < 10)
			res1 = 14;
		else if (tempint < 25)
			res1 = 1;
		else if (tempint < 35)
			res1 = 13;
		else if (tempint < 50)
			res1 = 14;
		else if (tempint < 84)
			res1 = 1;
		else if (tempint < 90)
			res1 = 14;
		else
			res1 = 1;
		break;
	}
	case 'C':
	{
		if (tempint < 15)
			res1 = 14;
		else if (tempint < 27)
			res1 = 1;
		else if (tempint < 40)
			res1 = 13;
		else if (tempint < 42)
			res1 = 5;
		else if (tempint < 45)
			res1 = 14;
		else if (tempint < 50)
			res1 = 2;
		else if (tempint < 59)
			res1 = 10;
		else if (tempint < 69)
			res1 = 15;
		else if (tempint < 73)
			res1 = 12;
		else if (tempint < 81)
			res1 = 1;
		else if (tempint < 97)
			res1 = 19;
		else
			res1 = 1;
		break;
	}
	case 'D':
	{
		if (tempint < 10)
			res1 = 17;
		else if (tempint < 49)
			res1 = 17;
		else
			res1 = 1;
		break;
	}
	case 'E':
	{
		if (tempint < 8)
			res1 = 1;
		else if (tempint < 65)
			res1 = 1;
		else if (tempint < 69)
			res1 = 21;
		else
			res1 = 1;
		break;
	}
	case 'F':
	{
		res1 = 3;
		break;
	}
	case 'G':
	{
		if (tempint < 38)
			res1 = 6;
		else
			res1 = 2;
		break;
	}
	case 'H':
	{
		res1 = 12;
		break;
	}
	case 'I':
	{
		if (tempint < 26)
			res1 = 1;
		else if (tempint < 29)
			res1 = 7;
		else
			res1 = 1;
		break;
	}
	case 'J':
	{
		if (tempint < 19)
			res1 = 7;
		else if (tempint < 48)
			res1 = 13;
		else
			res1 = 7;
		break;
	}
	case 'K':
	{
		res1 = 1;
		break;
	}
	case 'L':
	{
		res1 = 14;
		break;
	}
	case 'M':
	{
		res1 = 5;
		break;
	}
	case 'N':
	{
		if (tempint < 52)
			res1 = 15;
		else
			res1 = 10;
		break;
	}
	case 'O':
	{
		res1 = 10;
		break;
	}
	case 'P':
	{
		if (tempint < 16)
			res1 = 10;
		else
			res1 = 11;
		break;
	}
	case 'Q':
	{
		res1 = 11;
		break;
	}
	case 'R':
	{
		if (tempint < 10)
			res1 = 7;
		else if (tempint < 20)
			res1 = 1;
		else if (tempint < 24)
			res1 = 14;
		else if (tempint < 30)
			res1 = 6;
		else if (tempint < 40)
			res1 = 15;
		else if (tempint < 47)
			res1 = 3;
		else if (tempint < 50)
			res1 = 13;
		else if (tempint < 70)
			res1 = 4;
		else
			res1 = 1;
		break;
	}
	case 'S':
	{
		if (tempint < 10)
			res1 = 8;
		else if (tempint < 20)
			res1 = 5;
		else if (tempint < 30)
			res1 = 7;
		else
			res1 = 5;
		break;
	}
	case 'T':
	{
		if (tempint < 20)
			res1 = 4;
		else if (tempint < 36)
			res1 = 8;
		else if (tempint < 66)
			res1 = 19;
		else
			res1 = 4;

		break;
	}
	case 'U':
	{
		if (tempint < 20)
			res1 = 1;
		else if (tempint < 79)
			res1 = 0;
		else if (tempint < 85)
			res1 = 18;
		else if (tempint < 98)
			res1 = 0;
		else
			res1 = 17;
		break;
	}
	case 'V':
	{
		res1 = 4;
		break;
	}
	case 'W':
	{
		res1 = 4;
		break;
	}
	case 'X':
	{
		res1 = 0;
		break;
	}
	case 'Y':
	{
		res1 = 4;
		break;
	}
	case 'Z':
	{
		res1 = 0;
		break;
	}

	}
	return res1;
}
