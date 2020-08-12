#include "ContactManager.h"

void main()
{
	HashTable ht(4);

	ht.Load();
	ht.DisplayAll();
	ht.Insert("Alan", "010-2431-8782", "", "", "everimind4@gmail.com", "19940426");
	ht.Insert("Crystal", "010-4931-2205", "", "", "choisj2205@gmail.com", "19960322");
	ht.Insert("Hyovely", "010-8367-0120", "", "", "", "19960222");
	ht.Insert("Vaan Zhang", "010-6331-4287", "", "", "", "19950526");
	ht.DisplayAll();
	ht.Sync();
}