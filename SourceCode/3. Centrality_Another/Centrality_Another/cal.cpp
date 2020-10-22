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

        /*
		//계통 분류
		Result = Test(First, Second);

		//작성
		location = Result.find("_");
		First = Result.substr(0, location);
		Second = Result.substr(location + 1, 20);
        */

		int p1 = atoi(First.c_str());
		int p2 = atoi(Second.c_str());
		pair<int,int> tmpair = make_pair(p1, p2);
		++host[tmpair]; // 값 하나 증가
	}


    for(auto it = host.begin(); it != host.end(); ++it)
    {
        MData << it->first.first << "," << it->first.second << "," << it->second << endl;
    }
    /*
	//map 내용 출력
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
	
	result = res1 + "_" + res2;
	return result;
}