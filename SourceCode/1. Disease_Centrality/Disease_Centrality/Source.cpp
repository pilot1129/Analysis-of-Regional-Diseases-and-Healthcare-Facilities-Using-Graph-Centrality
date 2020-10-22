#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<istream>
#include<unordered_map>
using namespace std;

vector<string> csv_read_row(istream &file, char delimiter);

/*������ ���� ����
	* 1. �õ����� �����͸� �з�[�õ��ڵ�,�ֻ�,�λ�,��]
	* 2. �õ��� �׷��� �ۼ�
*/
int main()
{
	//�Է� Data
	ifstream Data("Data.csv"); // �� ������

	//��� Data
	ofstream FileOut11("11����Ư����.csv"); //��忧��������
	ofstream FileOut26("26�λ걤����.csv"); //��忧��������
	ofstream FileOut27("27�뱸������.csv"); //��忧��������
	ofstream FileOut28("28��õ������.csv"); //��忧��������
	ofstream FileOut29("29���ֱ�����.csv"); //��忧��������
	ofstream FileOut30("30����������.csv"); //��忧��������
	ofstream FileOut31("31��걤����.csv"); //��忧��������
	ofstream FileOut36("36������.csv"); //��忧��������
	ofstream FileOut41("41��⵵.csv"); //��忧��������
	ofstream FileOut42("42������.csv"); //��忧��������
	ofstream FileOut43("43��û�ϵ�.csv"); //��忧��������
	ofstream FileOut44("44��û����.csv"); //��忧��������
	ofstream FileOut45("45����ϵ�.csv"); //��忧��������
	ofstream FileOut46("46���󳲵�.csv"); //��忧��������
	ofstream FileOut47("47���ϵ�.csv"); //��忧��������
	ofstream FileOut48("48��󳲵�.csv"); //��忧��������
	ofstream FileOut49("49���ֵ�.csv"); //��忧��������

	//Variables
	vector<string> content;// �� �ٺ� ������
	string CurCode; // ���� �ֻ�_�λ�
	int count = 0;
	unordered_map<string, int> hospital11; // �����
	vector <string> List11;//������Ʈ
	unordered_map<string, int> hospital26; // �����
	vector <string> List26;//������Ʈ
	unordered_map<string, int> hospital27; // �����
	vector <string> List27;//������Ʈ
	unordered_map<string, int> hospital28; // �����
	vector <string> List28;//������Ʈ
	unordered_map<string, int> hospital29; // �����
	vector <string> List29;//������Ʈ
	unordered_map<string, int> hospital30; // �����
	vector <string> List30;//������Ʈ
	unordered_map<string, int> hospital31; // �����
	vector <string> List31;//������Ʈ
	unordered_map<string, int> hospital36; // �����
	vector <string> List36;//������Ʈ
	unordered_map<string, int> hospital41; // �����
	vector <string> List41;//������Ʈ
	unordered_map<string, int> hospital42; // �����
	vector <string> List42;//������Ʈ
	unordered_map<string, int> hospital43; // �����
	vector <string> List43;//������Ʈ
	unordered_map<string, int> hospital44; // �����
	vector <string> List44;//������Ʈ
	unordered_map<string, int> hospital45; // �����
	vector <string> List45;//������Ʈ
	unordered_map<string, int> hospital46; // �����
	vector <string> List46;//������Ʈ
	unordered_map<string, int> hospital47; // �����
	vector <string> List47;//������Ʈ
	unordered_map<string, int> hospital48; // �����
	vector <string> List48;//������Ʈ
	unordered_map<string, int> hospital49; // �����
	vector <string> List49;//������Ʈ
	
	cout << "�۾�����" << endl;
	//content[9] = �ֻ� / content[10] = �λ� / content[8] = ������� / content[5] = �õ��ڵ�
	while (Data.good())// ����� ������
	{
		content = csv_read_row(Data, ','); // ���پ� �о��

		if (content[0] != "2016")
			continue;
		CurCode = content[9] + "_" + content[10]; // �ֻ�_�λ� ����

		switch (stoi(content[5]))
		{
		case 11:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital11.find(CurCode);
			if (got == hospital11.end()) // ������
			{
				hospital11.insert({ CurCode,1 });
				List11.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital11[CurCode]; // �ϳ� ����
			/*
			if (!(hospital11.insert({ CurCode,1 }).second))//������� �߰�.
				++hospital11[{CurCode}]; // ������� +1
			*/
			break;
		}
		case 26:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital26.find(CurCode);
			if (got == hospital26.end()) // ������
			{
				hospital26.insert({ CurCode,1 });
				List26.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital26[CurCode]; // �ϳ� ����
			break;
		}
		case 27:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital27.find(CurCode);
			if (got == hospital27.end()) // ������
			{
				hospital27.insert({ CurCode,1 });
				List27.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital27[CurCode]; // �ϳ� ����
			break;
		}
		case 28:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital28.find(CurCode);
			if (got == hospital28.end()) // ������
			{
				hospital28.insert({ CurCode,1 });
				List28.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital28[CurCode]; // �ϳ� ����
			break;
		}
		case 29:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital29.find(CurCode);
			if (got == hospital29.end()) // ������
			{
				hospital29.insert({ CurCode,1 });
				List29.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital29[CurCode]; // �ϳ� ����
			break;
		}
		case 30:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital30.find(CurCode);
			if (got == hospital30.end()) // ������
			{
				hospital30.insert({ CurCode,1 });
				List30.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital30[CurCode]; // �ϳ� ����
			break;
		}
		case 31:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital31.find(CurCode);
			if (got == hospital31.end()) // ������
			{
				hospital31.insert({ CurCode,1 });
				List31.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital31[CurCode]; // �ϳ� ����
			break;
		}
		case 36:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital36.find(CurCode);
			if (got == hospital36.end()) // ������
			{
				hospital36.insert({ CurCode,1 });
				List36.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital36[CurCode]; // �ϳ� ����
			break;
		}
		case 41:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital41.find(CurCode);
			if (got == hospital41.end()) // ������
			{
				hospital41.insert({ CurCode,1 });
				List41.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital41[CurCode]; // �ϳ� ����
			break;
		}
		case 42:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital42.find(CurCode);
			if (got == hospital42.end()) // ������
			{
				hospital42.insert({ CurCode,1 });
				List42.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital42[CurCode]; // �ϳ� ����
			break;
		}
		case 43:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital43.find(CurCode);
			if (got == hospital43.end()) // ������
			{
				hospital43.insert({ CurCode,1 });
				List43.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital43[CurCode]; // �ϳ� ����
			break;
		}
		case 44:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital44.find(CurCode);
			if (got == hospital44.end()) // ������
			{
				hospital44.insert({ CurCode,1 });
				List44.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital44[CurCode]; // �ϳ� ����
			break;
		}
		case 45:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital45.find(CurCode);
			if (got == hospital45.end()) // ������
			{
				hospital45.insert({ CurCode,1 });
				List45.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital45[CurCode]; // �ϳ� ����
			break;
		}
		case 46:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital46.find(CurCode);
			if (got == hospital46.end()) // ������
			{
				hospital46.insert({ CurCode,1 });
				List46.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital46[CurCode]; // �ϳ� ����
			break;
		}
		case 47:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital47.find(CurCode);
			if (got == hospital47.end()) // ������
			{
				hospital47.insert({ CurCode,1 });
				List47.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital47[CurCode]; // �ϳ� ����
			break;
		}
		case 48:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital48.find(CurCode);
			if (got == hospital48.end()) // ������
			{
				hospital48.insert({ CurCode,1 });
				List48.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital48[CurCode]; // �ϳ� ����
			break;
		}
		case 49:
		{
			std::unordered_map<std::string, int>::const_iterator got = hospital49.find(CurCode);
			if (got == hospital49.end()) // ������
			{
				hospital49.insert({ CurCode,1 });
				List49.push_back(CurCode); // ����Ʈ�� �߰�
			}
			else // ������
				++hospital49[CurCode]; // �ϳ� ����
			break;
		}
		}
		count++;
		if (count % 10000 == 0)
			cout << count / 10000 << "�� �Ϸ�" << endl;
		if (count == 5000000)
			break;
	}
	Data.close();
	cout << "������ ���� �Ϸ�" << endl;

	//������ �й�
	vector<string>::iterator viter; // ���� ���ͷ�����
	
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