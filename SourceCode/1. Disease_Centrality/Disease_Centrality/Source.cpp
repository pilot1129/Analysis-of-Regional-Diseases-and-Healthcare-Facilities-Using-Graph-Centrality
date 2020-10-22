#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<istream>
#include<unordered_map>
using namespace std;

vector<string> csv_read_row(istream &file, char delimiter);

/*데이터 추출 순서
	* 1. 시도별로 데이터를 분류[시도코드,주상병,부상병,수]
	* 2. 시도별 그래프 작성
*/
int main()
{
	//입력 Data
	ifstream Data("Data.csv"); // 총 데이터

	//출력 Data
	ofstream FileOut11("11서울특별시.csv"); //노드엣지데이터
	ofstream FileOut26("26부산광역시.csv"); //노드엣지데이터
	ofstream FileOut27("27대구광역시.csv"); //노드엣지데이터
	ofstream FileOut28("28인천광역시.csv"); //노드엣지데이터
	ofstream FileOut29("29광주광역시.csv"); //노드엣지데이터
	ofstream FileOut30("30대전광역시.csv"); //노드엣지데이터
	ofstream FileOut31("31울산광역시.csv"); //노드엣지데이터
	ofstream FileOut36("36세종시.csv"); //노드엣지데이터
	ofstream FileOut41("41경기도.csv"); //노드엣지데이터
	ofstream FileOut42("42강원도.csv"); //노드엣지데이터
	ofstream FileOut43("43충청북도.csv"); //노드엣지데이터
	ofstream FileOut44("44충청남도.csv"); //노드엣지데이터
	ofstream FileOut45("45전라북도.csv"); //노드엣지데이터
	ofstream FileOut46("46전라남도.csv"); //노드엣지데이터
	ofstream FileOut47("47경상북도.csv"); //노드엣지데이터
	ofstream FileOut48("48경상남도.csv"); //노드엣지데이터
	ofstream FileOut49("49제주도.csv"); //노드엣지데이터

	//Variables
	vector<string> content;// 매 줄별 데이터
	string CurCode; // 현재 주상병_부상병
	int count = 0;
	unordered_map<string, int> hospital11; // 진료과
	vector <string> List11;//병리스트
	unordered_map<string, int> hospital26; // 진료과
	vector <string> List26;//병리스트
	unordered_map<string, int> hospital27; // 진료과
	vector <string> List27;//병리스트
	unordered_map<string, int> hospital28; // 진료과
	vector <string> List28;//병리스트
	unordered_map<string, int> hospital29; // 진료과
	vector <string> List29;//병리스트
	unordered_map<string, int> hospital30; // 진료과
	vector <string> List30;//병리스트
	unordered_map<string, int> hospital31; // 진료과
	vector <string> List31;//병리스트
	unordered_map<string, int> hospital36; // 진료과
	vector <string> List36;//병리스트
	unordered_map<string, int> hospital41; // 진료과
	vector <string> List41;//병리스트
	unordered_map<string, int> hospital42; // 진료과
	vector <string> List42;//병리스트
	unordered_map<string, int> hospital43; // 진료과
	vector <string> List43;//병리스트
	unordered_map<string, int> hospital44; // 진료과
	vector <string> List44;//병리스트
	unordered_map<string, int> hospital45; // 진료과
	vector <string> List45;//병리스트
	unordered_map<string, int> hospital46; // 진료과
	vector <string> List46;//병리스트
	unordered_map<string, int> hospital47; // 진료과
	vector <string> List47;//병리스트
	unordered_map<string, int> hospital48; // 진료과
	vector <string> List48;//병리스트
	unordered_map<string, int> hospital49; // 진료과
	vector <string> List49;//병리스트
	
	cout << "작업시작" << endl;
	//content[9] = 주상병 / content[10] = 부상병 / content[8] = 진료과목 / content[5] = 시도코드
	while (Data.good())// 제대로 열리면
	{
		content = csv_read_row(Data, ','); // 한줄씩 읽어라

		if (content[0] != "2016")
			continue;
		CurCode = content[9] + "_" + content[10]; // 주상병_부상병 형태

		switch (stoi(content[5]))
		{
		case 11:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital11.find(CurCode);
			if (got == hospital11.end()) // 없으면
			{
				hospital11.insert({ CurCode,1 });
				List11.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital11[CurCode]; // 하나 증가
			/*
			if (!(hospital11.insert({ CurCode,1 }).second))//없을경우 추가.
				++hospital11[{CurCode}]; // 있을경우 +1
			*/
			break;
		}
		case 26:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital26.find(CurCode);
			if (got == hospital26.end()) // 없으면
			{
				hospital26.insert({ CurCode,1 });
				List26.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital26[CurCode]; // 하나 증가
			break;
		}
		case 27:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital27.find(CurCode);
			if (got == hospital27.end()) // 없으면
			{
				hospital27.insert({ CurCode,1 });
				List27.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital27[CurCode]; // 하나 증가
			break;
		}
		case 28:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital28.find(CurCode);
			if (got == hospital28.end()) // 없으면
			{
				hospital28.insert({ CurCode,1 });
				List28.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital28[CurCode]; // 하나 증가
			break;
		}
		case 29:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital29.find(CurCode);
			if (got == hospital29.end()) // 없으면
			{
				hospital29.insert({ CurCode,1 });
				List29.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital29[CurCode]; // 하나 증가
			break;
		}
		case 30:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital30.find(CurCode);
			if (got == hospital30.end()) // 없으면
			{
				hospital30.insert({ CurCode,1 });
				List30.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital30[CurCode]; // 하나 증가
			break;
		}
		case 31:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital31.find(CurCode);
			if (got == hospital31.end()) // 없으면
			{
				hospital31.insert({ CurCode,1 });
				List31.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital31[CurCode]; // 하나 증가
			break;
		}
		case 36:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital36.find(CurCode);
			if (got == hospital36.end()) // 없으면
			{
				hospital36.insert({ CurCode,1 });
				List36.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital36[CurCode]; // 하나 증가
			break;
		}
		case 41:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital41.find(CurCode);
			if (got == hospital41.end()) // 없으면
			{
				hospital41.insert({ CurCode,1 });
				List41.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital41[CurCode]; // 하나 증가
			break;
		}
		case 42:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital42.find(CurCode);
			if (got == hospital42.end()) // 없으면
			{
				hospital42.insert({ CurCode,1 });
				List42.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital42[CurCode]; // 하나 증가
			break;
		}
		case 43:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital43.find(CurCode);
			if (got == hospital43.end()) // 없으면
			{
				hospital43.insert({ CurCode,1 });
				List43.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital43[CurCode]; // 하나 증가
			break;
		}
		case 44:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital44.find(CurCode);
			if (got == hospital44.end()) // 없으면
			{
				hospital44.insert({ CurCode,1 });
				List44.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital44[CurCode]; // 하나 증가
			break;
		}
		case 45:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital45.find(CurCode);
			if (got == hospital45.end()) // 없으면
			{
				hospital45.insert({ CurCode,1 });
				List45.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital45[CurCode]; // 하나 증가
			break;
		}
		case 46:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital46.find(CurCode);
			if (got == hospital46.end()) // 없으면
			{
				hospital46.insert({ CurCode,1 });
				List46.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital46[CurCode]; // 하나 증가
			break;
		}
		case 47:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital47.find(CurCode);
			if (got == hospital47.end()) // 없으면
			{
				hospital47.insert({ CurCode,1 });
				List47.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital47[CurCode]; // 하나 증가
			break;
		}
		case 48:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital48.find(CurCode);
			if (got == hospital48.end()) // 없으면
			{
				hospital48.insert({ CurCode,1 });
				List48.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital48[CurCode]; // 하나 증가
			break;
		}
		case 49:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital49.find(CurCode);
			if (got == hospital49.end()) // 없으면
			{
				hospital49.insert({ CurCode,1 });
				List49.push_back(CurCode); // 리스트에 추가
			}
			else // 있으면
				++hospital49[CurCode]; // 하나 증가
			break;
		}
		}
		count++;
		if (count % 10000 == 0)
			cout << count / 10000 << "행 완료" << endl;
		if (count == 5000000)
			break;
	}
	Data.close();
	cout << "데이터 추출 완료" << endl;

	//데이터 분배
	vector<string>::iterator viter; // 벡터 이터레이터
	
	//11
	for (viter = List11.begin(); viter != List11.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital11.find(*viter);
		FileOut11 << got->first << ',' << got->second << endl;
	}

	//26
	for (viter = List26.begin(); viter != List26.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital26.find(*viter);
		FileOut26 << got->first << ',' << got->second << endl;
	}

	//27
	for (viter = List27.begin(); viter != List27.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital27.find(*viter);
		FileOut27 << got->first << ',' << got->second << endl;
	}

	//28
	for (viter = List28.begin(); viter != List28.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital28.find(*viter);
		FileOut28 << got->first << ',' << got->second << endl;
	}

	//29
	for (viter = List29.begin(); viter != List29.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital29.find(*viter);
		FileOut29 << got->first << ',' << got->second << endl;
	}

	//30
	for (viter = List30.begin(); viter != List30.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital30.find(*viter);
		FileOut30 << got->first << ',' << got->second << endl;
	}

	//31
	for (viter = List31.begin(); viter != List31.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital31.find(*viter);
		FileOut31 << got->first << ',' << got->second << endl;
	}

	//36
	for (viter = List36.begin(); viter != List36.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital36.find(*viter);
		FileOut36 << got->first << ',' << got->second << endl;
	}

	//41
	for (viter = List41.begin(); viter != List41.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital41.find(*viter);
		FileOut41 << got->first << ',' << got->second << endl;
	}

	//42
	for (viter = List42.begin(); viter != List42.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital42.find(*viter);
		FileOut42 << got->first << ',' << got->second << endl;
	}

	//43
	for (viter = List43.begin(); viter != List43.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital43.find(*viter);
		FileOut43 << got->first << ',' << got->second << endl;
	}

	//44
	for (viter = List44.begin(); viter != List44.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital44.find(*viter);
		FileOut44 << got->first << ',' << got->second << endl;
	}

	//45
	for (viter = List45.begin(); viter != List45.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital45.find(*viter);
		FileOut45 << got->first << ',' << got->second << endl;
	}

	//46
	for (viter = List46.begin(); viter != List46.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital46.find(*viter);
		FileOut46 << got->first << ',' << got->second << endl;
	}

	//47
	for (viter = List47.begin(); viter != List47.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital47.find(*viter);
		FileOut47 << got->first << ',' << got->second << endl;
	}

	//48
	for (viter = List48.begin(); viter != List48.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital48.find(*viter);
		FileOut48 << got->first << ',' << got->second << endl;
	}

	//49
	for (viter = List49.begin(); viter != List49.end(); ++viter)
	{
		std::unordered_map<std::string, int>::const_iterator got = hospital49.find(*viter);
		FileOut49 << got->first << ',' << got->second << endl;
	}

	cout << "Clear" << endl;
	system("pause");
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