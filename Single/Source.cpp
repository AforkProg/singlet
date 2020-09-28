#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
using namespace std;
class single
{
private:
	single() = default;
	~single() = default;
	single(const single&) = delete;
	single& operator=(const single&) = delete;
	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;
	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;
public:
	static single& inst()
	{
		static single object;
		return object;
	}
};

void changeInfo(string path)
{
	auto& ob = single::inst();
	vector <string> parameters;
	string dock;
	ifstream dock_read(path);
	if (dock_read.is_open())
	{
		while (getline(dock_read, dock))
		{
			cout << dock << endl;
			parameters.push_back(dock);
		}
		dock_read.close();
		string newInfo;
		string info;
		string saveInfo;
		cout << "Type which info you want change (TYPE LIKE IN DOCUMENT): ";
		cin >> info;
		cout << "Type new info: ";
		cin >> newInfo;
		for (int a = 0; a < parameters.size(); a++)
		{
			cmatch result;
			regex regular(info + "(\.)");
			if (regex_search(parameters[a].c_str(), result, regular))
			{
				saveInfo = parameters[a];
				for (int b = saveInfo.size() - 1; ; b--)
				{
					if (saveInfo[saveInfo.size() - 1] == ' ')
					{
						for (int c = 0; c < newInfo.size(); c++)
							saveInfo.push_back(newInfo[c]);
						parameters[a] = saveInfo;
						break;
					}
					saveInfo.pop_back();
				}
			}
		}
		ofstream newInfoDoc;
		newInfoDoc.open(path);
		newInfoDoc.seekp(1);
		for (int a = 0; a < parameters.size(); a++)
		{
			newInfoDoc << parameters[a] << endl;
		}
	}
	else
		cout << "Wrong file name. lol" << endl;
}
void deleteInfo(string path)
{
	auto& ob = single::inst();
	vector <string> parameters;
	string dock;
	ifstream dock_read(path);
	if (dock_read.is_open())
	{
		while (getline(dock_read, dock))
		{
			cout << dock << endl;
			parameters.push_back(dock);
		}
		dock_read.close();
		string info;
		string saveInfo;
		cout << "Type which info you want delete (TYPE LIKE IN DOCUMENT): " << endl;
		cin >> info;
		for (int a = 0; a < parameters.size(); a++)
		{
			cmatch result;
			regex regular(info + "(\.)");
			if (regex_search(parameters[a].c_str(), result, regular))
			{
				saveInfo = parameters[a];
				for (int b = saveInfo.size() - 1; ; b--)
				{
					if (saveInfo[saveInfo.size() - 1] == ' ')
					{
						parameters[a] = saveInfo;
						break;
					}
					saveInfo.pop_back();
				}
			}
		}
		ofstream newInfo;
		newInfo.open(path);
		newInfo.seekp(1);
		for (int a = 0; a < parameters.size(); a++)
		{
			newInfo << parameters[a] << endl;
		}
	}
	else
		cout << "Wrong file name. kek" << endl;
}

int main()
{
	auto& object = single::inst();
	int cho;
	cout << "Choose your destiny" << endl << "1. Delete info" << endl << "2. Change info" << endl;
	string path;
	cin >> cho;
	if (cho == 1)
	{
		cout << "Enter path fo file (example.config): ";
		cin >> path;
		cmatch result;
		regex regular("(\.)""(.config)");
		if (!regex_search(path.c_str(), result, regular))
		{
			cout << "Wrong type of file" << endl;
			system("pause");
			return 0;
		}
		deleteInfo(path);
	}
	else if (cho == 2)
	{
		cout << "Enter path fo file (example.config)";
		cin >> path;
		cmatch result;
		regex regular("(\.)""(.config)");
		if (!regex_search(path.c_str(), result, regular))
		{
			cout << "Wrong type of file" << endl;
			system("pause");
			return 0;
		}
		changeInfo(path);
	}
	else
		cout << "Wrong request" << endl;
	system("pause");
	return 0;
}