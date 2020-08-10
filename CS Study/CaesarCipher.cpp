#include <iostream>
#include <string>

using namespace std;

void main()
{
	char str[100];
	int key = 0, len = 0;
	while (1)
	{
		int mode = 0;
		while (1)
		{
			cout << "Select mode - 1(Encryption), 2(Decryption) : "; cin >> mode;
			if (mode == 1 || mode == 2)
				break;
			else
				cout << endl << "Wrong number. Try again." << endl << endl;
		}
		cout << endl << "key : "; cin >> key;
		getchar();
		cout << endl << "string (q to quit): "; cin.get(str, 100);
		len = strlen(str);
		if (mode == 1)
		{
			for (int i = 0; i < len; i++)
			{
				if (str[0] == 'q')
					return;
				if (str[i] == ' ')
					continue;
				if ((str[i] >= 'A') && (str[i] <= 'Z'))
				{
					str[i] = str[i] - 'A';
					if ((str[i] + key) < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] + key) % 26;
					str[i] = str[i] + 'A';
				}
				else if ((str[i] >= 'a') && (str[i] <= 'z'))
				{
					str[i] = str[i] - 'a';
					if ((str[i] + key) < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] + key) % 26;
					str[i] = str[i] + 'a';
				}
			}
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (str[0] == 'q')
					return;
				if (str[i] == ' ')
					continue;
				if ((str[i] >= 'A') && (str[i] <= 'Z'))
				{
					str[i] = str[i] - 'A';
					if ((str[i] - key) < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] - key) % 26;
					str[i] = str[i] + 'A';
				}
				else if ((str[i] >= 'a') && (str[i] <= 'z'))
				{
					str[i] = str[i] - 'a';
					if ((str[i] - key) < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] - key) % 26;
					str[i] = str[i] + 'a';
				}
			}
		}
		cout << endl;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				cout << ' ';
				continue;
			}
			cout << str[i];
		}
		cout << endl << endl;
	}
}