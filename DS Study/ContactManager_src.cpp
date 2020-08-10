#include "ContactManager.h"

void main()
{
	HashTable ht(4);

	ht.GetData();
	ht.Display();
	ht.Insert("Alan", "010-1234-5678", "", "", "everimind4@gmail.com", "19940426");
	ht.Insert("Crystal", "010-XXXX-XXXX", "", "", "choisj2205@gmail.com", "19960322");
	ht.Insert("Hyojeong", "010-8367-0120", "", "", "", "19960222");
	ht.Insert("Jeongwook", "010-6331-4287", "", "", "", "");
	ht.Display();
}