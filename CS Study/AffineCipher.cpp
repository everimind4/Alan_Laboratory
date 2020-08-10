#include <iostream>
#include <string>

using namespace std;

void main()
{
	char str[100];
	int key1 = 0, key2 = 0, len = 0, key1_i = 0;
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
		cout << endl << "key 1 : "; cin >> key1;
		key1_i; //¿€º∫¡ﬂ
		cout << endl << "key 2 : "; cin >> key2;
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
					str[i] -= 'A';
					str[i] *= key1;
					str[i] += key2;
					str[i] %= 26;					
					str[i] += 'A';
				}
				else if ((str[i] >= 'a') && (str[i] <= 'z'))
				{
					str[i] -= 'a';
					str[i] *= key1;
					str[i] += key2;
					str[i] %= 26;
					str[i] += 'a';
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
					str[i] -= 'A';
					str[i] -= key2;
					if (str[i] < 0)
						str[i] += 26;
					
					str[i] += 'A';
				}
				else if ((str[i] >= 'a') && (str[i] <= 'z'))
				{
					str[i] -= 'a';
					str[i] -= key2;
					if (str[i] < 0)
						str[i] += 26;
					
					str[i] += 'a';
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