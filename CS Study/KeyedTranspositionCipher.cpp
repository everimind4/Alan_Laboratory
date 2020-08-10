#include <iostream>
#include <string>

using namespace std;

#define BLOCK_SIZE 6

void main()
{
	char p_text[20] = { '\0', }, c_text[20] = { '\0', };
	int key[BLOCK_SIZE] = { 3,5,1,6,4,2 };
	int block_num, select;
	while (1)
	{
		cout << "Select menu - 1) Encryption 2) Decryption : ";
		cin >> select;
		if (select == 1)
		{
			cout << endl << "Enter plain text : ";
			cin >> p_text;
			cout << endl;
			size_t str_size = strlen(p_text);
			if (str_size % BLOCK_SIZE)
			{
				block_num = str_size / BLOCK_SIZE + 1;
				for (int i = str_size; i < block_num * BLOCK_SIZE; i++)
					p_text[i] = 'x';

			}
			else block_num = str_size / BLOCK_SIZE;
			for (int i = 0; i < block_num; i++)
				for (int j = 0; j < BLOCK_SIZE; j++)
					c_text[i * BLOCK_SIZE + j] = p_text[(key[j] - 1) + i * BLOCK_SIZE];
			for (int i = 0; i < str_size; i++)
				cout << c_text[i];
		}
		else if (select == 2)
		{
			cout << endl << "Enter cipher text : ";
			cin >> c_text;
			cout << endl;
			size_t str_size = strlen(c_text);
			if (str_size % BLOCK_SIZE)
			{
				block_num = str_size / BLOCK_SIZE + 1;
				for (int i = str_size; i < block_num * BLOCK_SIZE; i++)
					c_text[i] = 'x';
			}
			else block_num = str_size / BLOCK_SIZE;
			for (int i = 0; i < block_num; i++)
				for (int j = 0; j < BLOCK_SIZE; j++)
					p_text[(key[j] - 1) + i * BLOCK_SIZE] = c_text[i * BLOCK_SIZE + j];
			for (int i = 0; i < str_size; i++)
				cout << p_text[i];
		}
		cout << endl << endl;
	}
}