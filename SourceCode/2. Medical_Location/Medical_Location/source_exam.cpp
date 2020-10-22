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
	ifstream Data("Data.csv"); // 지역별 데이터 -> content[0] = 번호_번호 / content[1] = 수
	ofstream MData("Medical.csv"); // 정리본
	vector<string> content;// 매 줄별 데이터
	unordered_map<pair<int,int>, int,pair_hash> host; // 진료과[진료-진료코드 , 수] 다른 엑셀 파일 순서.
	string First; // 주진료
	string Second; // 부진료
	string Result;
	int count;
	int location;

	cout << "작업시작" << endl;

	//기본 map 목록 장착.
	for (int i = 1; i < 27; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			host.insert(make_pair(make_pair(i, j), 0));
		}
	}

	while (Data.good())// 제대로 열리면
	{
		content = csv_read_row(Data, ','); // 한줄씩 읽어라
		count = stoi(content[1]);

		//문자 구분
		location = content[0].find("_");
		First = content[0].substr(0, location); // 0부터 location까지
		Second = content[0].substr(location+1,20); // location부터 끝까지

		//계통 분류
		Result = Test(First, Second);

		//작성
		location = Result.find("_");
		First = Result.substr(0, location);
		Second = Result.substr(location + 1, 20);

		int p1 = atoi(First.c_str());
		int p2 = atoi(Second.c_str());
		pair<int,int> tmpair = make_pair(p1, p2);
		++host[tmpair]; // 값 하나 증가
	}

	//map 내용 출력
	for (int i = 1; i < 27; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			unordered_map<pair<int, int>, int, pair_hash>::const_iterator got = host.find(make_pair(i, j));
			MData << i << "," << j << "," << got->second << endl;
		}
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

string Test(string a, string b)
{
	string result;
	string tempstr;
	string res1;
	string res2;
	//알파벳 하나인지 체크
	if (a.size() == 1 || b.size() == 1)
		return "0_0";

	tempstr = a.at(1) + a.at(2);
	int tempint = atoi(tempstr.c_str());
	
	switch (a.at(0))
	{
	case 'A':
	{
		if(tempint<10)
			res1 = "1";
		else if(tempint<20)
			res1 = "20";
		else if(tempint<50)
			res1 = "1";
		else if(tempint<65)
			res1 = "15";
		else if(tempint<70)
			res1 = "10";
		else if(tempint<75)
			res1 = "1";
		else if(tempint<80)
			res1 = "14";
		else if(tempint<90)
			res1 = "2";
		else
			res1 = "13";
		break;
	}
	case 'B':
	{
		if(tempint<10)
			res1 = "14";
		else if(tempint<25)
			res1 = "1";
		else if(tempint<35)
			res1 = "13";
		else if(tempint<50)
			res1 = "14";
		else if(tempint<84)
			res1 = "1";
		else if(tempint<90)
			res1 = "14";
		else
			res1 = "1";
		break;
	}
	case 'C':
	{
		if(tempint<15)
			res1 = "14";
		else if(tempint<27)
			res1 = "1";
		else if(tempint<40)
			res1 = "13";
		else if(tempint<42)
			res1 = "5";
		else if(tempint<45)
			res1 = "14";
		else if(tempint<50)
			res1 = "2";
		else if(tempint<59)
			res1 = "10";
		else if(tempint<69)
			res1 = "15";
		else if(tempint<73)
			res1 = "12";
		else if(tempint<81)
			res1 = "1";
		else if(tempint<97)
			res1 = "19";
		else
			res1 = "1";
		break;
	}
	case 'D':
	{
		if(tempint<10)
			res1 = "17";
		else if(tempint<49)
			res1 = "17";
		else
			res1 = "1";
		break;
	}
	case 'E':
	{
		if(tempint<8)
			res1 = "1";
		else if(tempint<65)
			res1 = "1";
		else if(tempint<69)
			res1 = "21";
		else
			res1 = "1";
		break;
	}
	case 'F':
	{
		res1 = "3";
		break;
	}
	case 'G':
	{
		if(tempint<38)
			res1 = "6";
		else
			res1 = "2";
		break;
	}
	case 'H':
	{
		res1 = "12";
		break;
	}
	case 'I':
	{
		if(tempint<26)
			res1 = "1";
		else if(tempint<29)
			res1 = "7";
		else
			res1 = "1";
		break;
	}
	case 'J':
	{
		if(tempint<19)
			res1 = "7";
		else if(tempint<48)
			res1 = "13";
		else
			res1 = "7";
		break;
	}
	case 'K':
	{
		res1 = "1";
		break;
	}
	case 'L':
	{
		res1 = "14";
		break;
	}
	case 'M':
	{
		res1 = "5";
		break;
	}
	case 'N':
	{
		if(tempint<52)
			res1 = "15";
		else
			res1 = "10";
		break;
	}
	case 'O':
	{
		res1 = "10";
		break;
	}
	case 'P':
	{
		if(tempint<16)
			res1 = "10";
		else
			res1 = "11";
		break;
	}
	case 'Q':
	{
		res1 = "11";
		break;
	}
	case 'R':
	{
		if (tempint < 10)
			res1 = "7";
		else if (tempint < 20)
			res1 = "1";
		else if (tempint < 24)
			res1 = "14";
		else if(tempint<30)
			res1 = "6";
		else if(tempint<40)
			res1 = "15";
		else if(tempint<47)
			res1 = "3";
		else if(tempint<50)
			res1 = "13";
		else if(tempint<70)
			res1 = "4";
		else
			res1 = "1";
		break;
	}
	case 'S':
	{
		if (tempint < 10)
			res1 = "8";
		else if (tempint < 20)
			res1 = "5";
		else if (tempint<30)
			res1 = "7";
		else
			res1 = "5";
		break;
	}
	case 'T':
	{
		if (tempint < 20)
			res1 = "4";
		else if (tempint < 36)
			res1 = "8";
		else if (tempint < 66)
			res1 = "19";
		else
			res1 = "4";

		break;
	}
	case 'U':
	{
		res1 = "0";
		break;
	}
	case 'V':
	{
		res1 = "4";
		break;
	}
	case 'W':
	{
		res1 ="4";
		break;
	}
	case 'X':
	{
		res1 = "0";
		break;
	}
	case 'Y':
	{
		res1 = "4";
		break;
	}
	case 'Z':
	{
		res1 = "0";
		break;
	}

	}

	switch (b.at(0))
	{
	case 'A':
	{
		if (tempint < 10)
			res2 = "1";
		else if (tempint < 20)
			res2 = "20";
		else if (tempint < 50)
			res2 = "1";
		else if (tempint < 65)
			res2 = "15";
		else if (tempint < 70)
			res2 = "10";
		else if (tempint < 75)
			res2 = "1";
		else if (tempint < 80)
			res2 = "14";
		else if (tempint < 90)
			res2 = "2";
		else
			res2 = "13";
		break;
	}
	case 'B':
	{
		if (tempint < 10)
			res2 = "14";
		else if (tempint < 25)
			res2 = "1";
		else if (tempint < 35)
			res2 = "13";
		else if (tempint < 50)
			res2 = "14";
		else if (tempint < 84)
			res2 = "1";
		else if (tempint < 90)
			res2 = "14";
		else
			res2 = "1";
		break;
	}
	case 'C':
	{
		if (tempint < 15)
			res2 = "14";
		else if (tempint < 27)
			res2 = "1";
		else if (tempint < 40)
			res2 = "13";
		else if (tempint < 42)
			res2 = "5";
		else if (tempint < 45)
			res2 = "14";
		else if (tempint < 50)
			res2 = "2";
		else if (tempint < 59)
			res2 = "10";
		else if (tempint < 69)
			res2 = "15";
		else if (tempint < 73)
			res2 = "12";
		else if (tempint < 81)
			res2 = "1";
		else if (tempint < 97)
			res2 = "19";
		else
			res2 = "1";
		break;
	}
	case 'D':
	{
		if (tempint < 10)
			res2 = "17";
		else if (tempint < 49)
			res2 = "17";
		else
			res2 = "1";
		break;
	}
	case 'E':
	{
		if (tempint < 8)
			res2 = "1";
		else if (tempint < 65)
			res2 = "1";
		else if (tempint < 69)
			res2 = "21";
		else
			res2 = "1";
		break;
	}
	case 'F':
	{
		res2 = "3";
		break;
	}
	case 'G':
	{
		if (tempint < 38)
			res2 = "6";
		else
			res2 = "2";
		break;
	}
	case 'H':
	{
		res2 = "12";
		break;
	}
	case 'I':
	{
		if (tempint < 26)
			res2 = "1";
		else if (tempint < 29)
			res2 = "7";
		else
			res2 = "1";
		break;
	}
	case 'J':
	{
		if (tempint < 19)
			res2 = "7";
		else if (tempint < 48)
			res2 = "13";
		else
			res2 = "7";
		break;
	}
	case 'K':
	{
		res2 = "1";
		break;
	}
	case 'L':
	{
		res2 = "14";
		break;
	}
	case 'M':
	{
		res2 = "5";
		break;
	}
	case 'N':
	{
		if (tempint < 52)
			res2 = "15";
		else
			res2 = "10";
		break;
	}
	case 'O':
	{
		res2 = "10";
		break;
	}
	case 'P':
	{
		if (tempint < 16)
			res2 = "10";
		else
			res2 = "11";
		break;
	}
	case 'Q':
	{
		res2 = "11";
		break;
	}
	case 'R':
	{
		if (tempint < 10)
			res2 = "7";
		else if (tempint < 20)
			res2 = "1";
		else if (tempint < 24)
			res2 = "14";
		else if (tempint < 30)
			res2 = "6";
		else if (tempint < 40)
			res2 = "15";
		else if (tempint < 47)
			res2 = "3";
		else if (tempint < 50)
			res2 = "13";
		else if (tempint < 70)
			res2 = "4";
		else
			res2 = "1";
		break;
	}
	case 'S':
	{
		if (tempint < 10)
			res2 = "8";
		else if (tempint < 20)
			res2 = "5";
		else if (tempint < 30)
			res2 = "7";
		else
			res2 = "5";
		break;
	}
	case 'T':
	{
		if (tempint < 20)
			res2 = "4";
		else if (tempint < 36)
			res2 = "8";
		else if (tempint < 66)
			res2 = "19";
		else
			res2 = "4";

		break;
	}
	case 'U':
	{
		res2 = "0";
		break;
	}
	case 'V':
	{
		res2 = "4";
		break;
	}
	case 'W':
	{
		res2 = "4";
		break;
	}
	case 'X':
	{
		res2 = "0";
		break;
	}
	case 'Y':
	{
		res2 = "4";
		break;
	}
	case 'Z':
	{
		res2 = "0";
		break;
	}

	}

	result = res1 + "_" + res2;
	return result;
}