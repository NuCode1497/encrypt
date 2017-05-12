#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#define PI 3.14159265
#define MAXFL 255 //max file length NTFS
char get_choice(void);  //menu function
char get_first(void);  //menu function
void encrypt(void);
void decrypt(void);
void fileExist(char fileName[], int copy);

char einstein[8081] = 
"888888888OO888OOOO8O8O88OD88888O8D88DDNDDDDDDDDNDD8DDD888888888888888OOO8888888888O8888Z$OO888888888"
"OO8888888888O8888O88O88O8O88888D8DDDDDDDDDDDDDD8DDD88888DD88888888O8D888888O8O88O88ZZOOOO88OO8888DD8\n"
"OOO88888O888OO88O888O8888888888DDDDNNNDNDNDDD8DDDNDDDDD8DDD88D8888O888888888888OZZO888O888888888DDD8\n"
"888O888888OO8OOO88OOO88O88888DDMZ7ZOOOO88DND8DNDD8DD8O8ND8D88888D8888D888D88OO8OOO888O888888DNDDDNNN\n"
"8O8OO8888888OO8O88OOO8OO88888=8DDOD8N8DND888DO$$$?:+==+~+?OOD8D88DDDDD8OO88888888OOOO888888DDNNNNNMM\n"
"O88OOOO888OOOOO88O888O88O88D+D77O8OO888D8ZODI7+=~OOZ$ZOO$OZ?Z7Z+?OOO8O88888888OO888O8O888DNNNNNNNNMM\n"
"8O8888OO8O888OOOOZZOOO88O88$Z88DO8O8DD8MD8$IZ?,O7Z+8$7+8$OOO$ZO8OO+=$DZO888888D888888DDDNNNNNNNNMMMM\n"
"OO8888OO8O8OOO88888OOOZO88$78OO8888O8DD8OZOZ?~IO78?I+777I+Z$ZZI7?=7OZIOO8888888O8888DNNNNNNNMMMMMMMM\n"
"O8OO8OOOOOOOOOOO8OZ$ZOO8O87ZO88ZO88OZZ8O$$O$~+IOI?:I+7ZII77$77$ZOD~887DID88888888D8DDDNNNNMMMMMMMMMM\n"
"OOOOOOO8OOOO88OZZOZOO77OOZ$Z+7OO77I7$ZZO?$7?=?+?~+$7+?+?~.::::~~:~+?D$O87888DDDDDDDNNNNNMMMMMMMMMMMM\n"
"OOOZO8O8OOOO8OOOOOOZZZZZ$ZZ$ZZZO7$Z7I7OI$II+=?\?=?I7?==::+I=~=+=?III?\?=I8D78DNNDNDNNNNNMMMMMMMMMNNMMM\n"
"OOZOOOOOOOOOZOO88OZ7Z$IZZ$$7I$$$?7?III$?+$+I=7I+$$I=I~?7+=~~:~?I+?+I?$$~7O$OZ8NNNNNNMMMMMMMMMMMMMMMM\n"
"OOOOOOOOOOZOOOOOZ$ZOZZ7I?7OI$7$I++==++?7???++=????+?=I?$$+II+=~~=:~+??+I7+$ZOZONNNMMMMMMMMMMMMMMMMNN\n"
"ZZZOO8ZZOOO$O$OOOZO$7?777Z7?I$III~:+++?II?\?=+?++++I==+++???I?+=~:::~:?7?II+8OOODNNNMMMMMMMMMMNMNNNDD\n"
"ZOOOOO888OOO8OOZZ7IZZ7$$III7$7+I?I+++?++++==+=====+==+=+=++??+?7I?+===?7+:$:=$8DNMMMMMMMMMMMMMMMNNNN\n"
"$ZOOZZOZO8ZOOOZZ88Z$Z$I$$II7$$7?I+++++======~~~~~~~~~~~~~=+=+??II7I?I??~?IO,$~7MNNNMMMMMMMMMMMMNNNNN\n"
"ZOZOOZZOOOOOO$8ZZ$O$ZOZI??8$I?I?\?=+===~===~~~~~==~~::~~~~~~+????7IIII?+==:I$I~?ONNMMMMMMMMMMMMMNNNNN\n"
"7$ZZZZZZZO$OZ$8OOO8Z7I+:+$II?~~++=~~:~~~~~~~~~~:~~~~:~=::~~~+~++?+I+?7?\?==~=7$:78MMMMMMMMMMMMNNNNNNN\n"
"$ZZZZZ$OZZOOO77ZOZ$7+,:8$?~I=:,~=+=====~=~+~~~~~~~:=:.:::~=:~~=+=?+=I+?++===~=?=7DDMMMMMMMMMMNNNNNNN\n"
"7$$Z$ZZ$8O88O$8DOII?==ZZ,?:?=~:~::::::::::,~~:::::,:,,~==:,~~+~=+=++?+I+++=~==Z~+DMMMMMMMMMMMMNMNNND\n"
"I$ZZZZZ8OZ8Z8OO$IZ=?+Z77I+,~=~:,:::::::::::::::::::~,,,::~=+,:~=:=?=?++II~=~~=:ZZ?7ONMMMMMMMMNNNNNNN\n"
"?7ZZOOOZ88D7I7?III+7?IO~?\?==::,,:,,:,,::,,,,,,,....,,::~=~,:===~~==+=++?I+=~~~=~7+D8?ZNMMMMMMNNMMNNN\n"
"I7ZZ$78ODZZ7?+++~IZ788~$=::,,,,,,,,,,,:,,,::::,,,,::::,,,:~=:=~+~=+=+=++?++~:~:=~I8DDNZ8MMMMMNNMNNNN\n"
"I$$Z8O88OZ+,IZI8OI7I8II,I=:,,,,.,,,:,:,,,,,,,:,,,:,:::.,=:,~~=:~~:~+~~=+=+~:+:~~II+NNMMNOMMMMNNMMNNN\n"
"I$OOO88OZ,7$7I7?777ID7I~=,==:::,,,,:,:,,,,,:,,,::,:,,,.,~,~,~~~~=+:=~~=++~~~:==+~+Z=NMMM8ZMMMMMMMMNN\n"
"I$$ZO7O7:Z$II???O?~7D7~ZMMM$I?I~:,,:::::,,:~~=IZ7Z7$+DO$:::~::~~~==~~+====:=~:=+?=OZO7DMNN8MMMMMMNNN\n"
"77ZOODO+ZOZD~?IOZ?=I8$7OD$$?+~~::,,,::::,,:::,:::+$+==~,=:,.=~:==~::==+===::~~=+++=+ZOZD8NOZMMMMMNMN\n"
"I7ZOOZI+$ZO7I=+Z7+~?D+?I~=:=~~:::,,,,,,,,,:,,.,,,,,,,,::,:,:,~~=~~:~~=+==~:,:~=~+?I~7$MZDMMDONNNNMNN\n"
"I7$$$$+$8$O7==I$I~~IN?=~:,:~:~~=:,:,,,,,..,,,,::,,,,,,,,::::=?~~~~~~~:~=+~~::=+++$?7+8IN$NNMMDNMMMNN\n"
"$$$IO88OODI?I?$Z7+:78=:,:~+II~~=+~~,,,,,,,,:::::~~~++:::,:,::+==:~~:~~:::=::,::::=~7I?+I$7OMMMMNNMNN\n"
"ZZOZOO8ODO7?I77$7+=O7~::=:7?I?+=~I?~,,,,,,::::~++~~++:Z+:,::==?=~:~::~:~::::,,:,:~+=7?I~+Z8NMMMNMNNN\n"
"Z$ZO8888887=7ZOZI=+D7:,~ZOMIZD=?=,$O=,:,::,~+~~IZZDZ+:=~?=:~~=+~~~~~~=~:~~~:,:~::,:=?~?+7Z+:DMMNMMMN\n"
"OOOO8DD8DDZ+$7O7?~78?~+ZZ:.8M87?I7+8~,::::=++I??,.ZMNDNI++:~::=~~~~~~~~:~::,::::~?=~++I~?=7$87MMMNNN\n"
"OOOO8DDDNZ7?Z$7Z=~$O===+:I,NNMO,I=~8~:~:~:=,,+=::,NMNM:$?\?=~~:~=~:~===~~~~:~~~:~~:=?\?=~I?=+$NDD8NMNM\n"
"OO8O8O88IO7?ZZ7ZI~$O==,ZO7?==::+:,N+=~~~~~+~~=I+?=77I=I?=~:~~::~~:~~+==::~~~=+====+=??:?+I$?7NNDDNNN\n"
"OO88ODZZ8D=IDZOO$+$Z??O??777I+=++8N+~:~~~::=~+?=?I7I7+=I+=++~:~~~~~~~=~::~~:??+~~:~===$+?+OZI7MM8MMN\n"
"O88OOO8$D8?+88OOO$ZI~7$=+=~~~+=+7DO=::~=~==::~:=+=:::~~~:+~==:~~=~~~===:~=++~=+?7==+~=~7I~+OI7DMMZNN\n"
"OOO7O8DOD+OI8DD888O+?++=::::=+~,DN?=:~===~~::,,,,:,::+=~~==:?=~=I~~=+?=+~+???+~:I~8?~+=~+=++8IONMNNN\n"
"888$8DOD+ZD$888DO88=,=:,~::~:~:=DI=~~~~++=~~::,,,:,,:,::=:::~+:~+~~==+=+~+==7?::=~=Z?$+==+~?~O78ZM8N\n"
"8O888OO?OOZ888DODDD+~:,:,:,:::?DI~~~~=~+?+~:,:::,,,,,,,:,,:,,::====+=??I7?+O?:,:+:I?D:$~~+:=+++ZNNDN\n"
"D8O8DD$OD8D88ND7DDN?:,,,,:::~=?I~:::,:~~=7++:.,:,,,,,,,,,,,,,,:~=?+?=?I$$=7::,,,+~D:,O~I:~~~I~~?87M8\n"
"D888$NZODD8NDDD$NDD+:,,,:::~~.M=:,,,,,::=?=?+:,.,,,,,,,,,,,,,,:~=??\?=+7$7==,::,,:~:~:Z+=,,::+?=~O7NO\n"
"D8D88DNDDDD8888NDDD7,:::~::,,I8I:,,...,:~=:~==::...,,,,:,,,,:,:~=?\?=++777=~.,,.:=,,~,,8~..,:?~+~7IM8\n"
"DDD88D8O88DD888D8DN7::~~:,,,~D8O$:::~:==:~::~?:,=,....,.,,,,,,:~=?++=?I???~:~,:=+=,.~:I:.,:.?+Z:Z~8O\n"
"NDD8DDDD8DDNNDN7DNDI=~~~,,,,~=8DN7===~7,,,:=?~:,,~,.,,,,,::,,7,:=??++7??7:,,~,~=:.~~:==..,:,?Z8~8ID$\n"
"NNNDNNNND=O8$O$IDND7:++:,,,~~~~~=~=::,=.~~:::,,,,,:~.,,,,:,:,:,~+I?++++I?,,,=:===~..~=$ .::,$O?==87D\n"
"NDNNNNNNNNNMNMO8NNDI:++~,:::=::,::,,:+::,:~~::~,,:~=:,,,,:::,,::+?==+++?=:,,=??~?=~:~~:.,~:,$$=+88DD\n"
"DNNNNNNNNNNNNDO8ZDNI:?I:=~=,::,,::,,,::..,:,,,:::=,:,:,,,,::,,::=?~++=+7,,:,~==:=Z77+::~~,?+:=78ODDN\n"
"DDNNDNNNNNNNND8ODNN$:+7~7+~=::,:~~:,~,~,:,:~,:~::,~::~:.,,,,,,::+I+=~=??..,:++7OI===~=+OZ+87DMMNDDND\n"
"8DNDDNDNNNNNNN8DNNM8=+?~I=I=~::,:,:,~~,,:~.:==:~,:.,:,::,,,:,,:==I=~~=?=M,:INMDN887~=+DDO?7NMNNNNNND\n"
"DDDNNDDDDDDNNNNNNNMNI~I:~+77+77+++I=~?=:~+=~=?+::=~:,:~,,,,,,:::=I~:~+?$ODNNNMNNNNNMNNNND8MNDNNNNNDN\n"
"NDDDNNNDDNNNNNNNNNNMI+?+:,~ID8DMII8I$OZ7II?I+7$++I:=:,:,,::,,:::=+,:~??8NMNNNNNNNNNNMNNNNDNNNNNNNNDN\n"
"D8DDNDNDDDDNNNNNNNNND~:$:,.:=87$+++~=++=~=~==+ZM8Z+=,,=,,::,,,,~I=::==NNNMNMNNNNNNNNNNNNNMNNNNNNNNN8\n"
"88DDNNNDNNDNNNNNNNNNM$=:Z,,::=M=~~=:=+~~~=:~~+OO:==,~~:,:::,,,::?,:~IMMNNMNNNNNNNMNNNMNNNNNNNNNNNDOZ\n"
"DNDDNDNNNNDNNNNNNNNNNM+:~=,.,:M~,,~~:::~+=~,I7==~:,,,~,,::,,,,,+,,~MMNNNMNNNNNNNNNMNDMNNNNMNNNNMZ87$\n"
"DDDDNNNNNNDNNNNNNNNNNNM+:Z,,,,M~.,::~,==+~::Z=+=~,,,,:,,::,,,,:::IMNNNNNNNNNNNNNNNMNNNNNNDNNNDNO$ZIZ\n"
"D8DDNNDNNNNDDNDNNNNNNNMM=,I,,,M$:,:~:~~~+:,?I+?~,,,,,,,,=,.,,:~.NNNNNNNNNNNNNDNMN8NNNNNNNNDNMO7DIZ$7\n"
"D88888DDDNDDDNDNNNNNNNMMD,I.,,88:::,:~~++~+$+?::,~,,,,,,+,..,I?NNNNNNNNNNNNNNNNNDNNNNNNNNNDN8ZZZ7+7$\n"
"ZOOOO8DDDDNDNNNNNDNNNNMMM$,$,,IM:,,,+:~=~:++=:,:,,,....,:..:ZMNNNNNNNNDDNNNDNN8NNNDDNNNNDND8$77$I?$7\n"
"ZZOOO88DDDNDDNNNDDNNNNNMMM7=,,:MO~::+:==~+I:::,,,.....,:..:MNNNNNNNNNNDDNNNDDDNDNNDDNNNDD8OI7Z77?7I$\n"
"$Z$ZOO88DNNNNNNDDDDDDDNMMMM=8,:$M+~,=:=:~7:,,,,,......~..+NNNNNNDNNNNNNNNNNNNDD8DDON8DNDOZ7OI777$OZ8\n"
"77$$OO88DNNDNNDDNDDDDDDDNNNM$7:,NM~~=:~=I,,,,,,,.......~NNDNDNMNNNNNNDNDNDD8N88ND8D8DD8$ZIIIZ7IZ7O$Z\n"
"$$$7$Z888NNNNDD8DDDDDDDDNNMMMNN~,8M=+==$...,,,,..... 7DNNNNNNNNNNNDNDNDDDDDDD8DNDNNNNOZZZ7IZ7$777DO8\n"
"7$$$7$ZZO8DNNDD8DDDDD8NDDNMNNMMM~~8MMNO..,,,..,. ,.~NNMDNNNNNNNNNNNNNNDDDDDDDD8NNNNDZZ$III7Z?$+O$OO8\n"
"$Z$77$$ZO8DDDDDD8DDDDNDNNDNMMMMMM+~~~,,,,,,,,,...ZDNNNNDNDNNNNNNNNNNDDDDDDD88DNDNN8DI7777+O7I?I$O88D\n"
"7$Z$7$$8DDDDDDDDDDDDDDNDNNDNMMMMMMO+=::,:::~,,=NNDDDDNNNNNNNNNNNNNDDDDDDDDDDDDDDNO$ZZ?7+ZZI$ZZZO8O8D\n"
"$$$$7D8DDDDDDDDDDDDDDDDNNNNNNNMMNMMM8$I===?+7DNDNNDDNNNNNNNNNNNNND8DDDDDDDDDDDN887$?7II+$7II7IO8ODDO\n"
"$7ZDDD88DDDDDDDDDDDDDNNNDNND8ODM==MMM8~:,:?NNNNNNNNNNNDNNNNDNNNNDDDD8DD8DDDDDNZZ$7$+IZ?~$ZZ77Z8O8DO8\n"
"ZDD8888DDDDDDDDDDDDNNNNDNNND8OOD,.. 7MMMINNNDNNNNMDNNDNDNNNDNNNDDNDDD8D8DDDND$?$?I=?$+IO$$?Z788OD88O\n"
"88D888888DDDDDD8DDDNNNNNNN8OOZM,~OO8$8,MNNNNNNNNNNNNNNNNNNNNNNNDNDDDD8NDDDDDO$7I?$?+IIIZ7OOZ$OOD88O$\n"
"888888888DDDDDDNDNNNNNNNNNOZOD.NDZOZONNNNNNNDNNNNNNNNNNNNNNNDNDNNDDDDDNDNDO$?I$I$II$Z$ZZ7IO$O8D88O7Z\n"
"888888888DDDD8DNDDNNNNNN8Z7ZZ7DOZZZNNNNNNNMNDNNNNNNNNNNNNNDDNNDDD88D8DDNNZOZ7$I7ZI7I7$?I87ZOO8NO8$7$\n"
"888OO888888D8DDNDNDNNND8O$ZZD$OOZMNNNNNNMNMNDNNNNNNNNNNMNNDNNNDDDD8NDNN87O$Z77III+77?ZIIIZO88NO8Z7OD\n"
"88888888D8DDD8DDDDNDN88$O78DN8$MNMMNNNNMMNNNNNNNNNNNNNNNNNNDDDNDDNDDND$7O8$?7$7$?$7$OI7IZZ8ZODOZZDDD\n"
"D8888888888DDDDNNDDNDO$Z$ZOMDNNNNNNMNMNMNNNNNNNNNNNNNNMNNNNNN8NNDDNNN$Z$Z7+III$7ZI$IZ?ZZZOO8DOZNDDND\n"
"88888888888DDDDDNDNO8ZZ8$8NNNNNNNNMNNNNMMMMNNNNNNNNNMNMNNNDNNDNNNDD88O7$+I$7?ZI$7ZZZ$Z$OOO8DDD8DD8DD\n"
"DDD88888888DDDDNDD8Z8Z7$DNNNNNNMMMMMMMMMMNNMMNNNNNNMNMNNNNNMNDDNNNO$Z7I$Z?IZIIII7ZZ778888O8D8DONDD8D\n"
"8DD8D88DDDDDD8DNDO8O$$ZNNNNNMNMMMMMMMMMMMNMMNNNMMNMMNNNNMMNMMMNMNO$ZI7Z$Z$Z7OI7$87ZZZD88ZZ88DDND88OD\n"
"DNN8DDNDDDDDDDNNZ$Z8ONDMNNNNMMMMMMMMMMMMMNMMMMMMNNMMMMNMMMMMMMMN8$O$Z$O$O$OOO$OOINOOO8D8DMM888NDNDDD\n"
"DNNNNNNNDNDDDNN8DOOMMMMMMMMMMMMMMMMMMMMMNNNMMMMNMNMMMMMMMMMMMMNN8O88OOZ8OO$DZZO888888NNMMMMNNDNNDNND\n";


int main()
{
	int choice;

	//menu
	while ( (choice = get_choice()) != '3')
	{
		switch (choice)
		{
		case '1' :
			encrypt();
			break;
		case '2' :
			decrypt();
			break;
		default : 
			printf("Program error!");
			break;
		}
	}
	cout<<endl;
	return 0;
}

char get_choice()
{
	int ch;
	printf("1 for ENCRYPTION\n2 for DECRYPTION\n3 Exit\n");
	ch = get_first();

	while( ch < '1' || ch > '3')
	{
		printf("Bad input. 1 Encryption, 2 Decryption, 3 Exit");
		ch = get_first();
	}
	return ch;
}

char get_first()
{
	int ch;
	//read first char, don't accept '\n' as the first char
	while( (ch = getchar()) == '\n')
		continue;
	while( getchar() != '\n') //skip the rest
		continue;
	return ch;
}

bool inflate()
{
	char ch;
	do
	{
		ch = get_first();
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'Y') return true;
	else return false;
}

void encrypt()
{
	FILE *inFile, *outFile, *keyFile;
	int boggle=0, fch=0, pch=0, ech=0, kch=0, ach=0, e=0, p=0, count=1;
	int passlen, einslen, lim;
	double pbaffle, ebaffle, trash;
	double degrees = 180 / PI;
	char fileName[MAXFL], password[100], keyFileName[MAXFL];
	bool isInflated = false;

	cout << "Input file name for encryption." << endl;
	cin.getline(fileName, 255);
	cout << "Input file name for key." << endl;
	cin.getline(keyFileName, 255);
	cout << "Inflate output? Y/N" << endl;
	isInflated = inflate();

	//setup input
	inFile = fopen(fileName, "rb");
	if (!inFile){
		cout<<"Could not open file. Encryption failed."<<endl;
		return; }

	//setup output
	strcat(fileName, ".encpt");    //filename.encpt
	outFile = fopen(fileName, "wb");
	if (!outFile){
		cout<<"Could not create out file."<<endl;
		return; }

	//setup key file
	keyFile = fopen(keyFileName, "rb");
	if (!keyFile) {
		cout << "Could not open key file. Encryption failed." << endl;
		return;
	}

	//ask for password
	printf("password: ");
	scanf("%s", password);
	passlen = strlen(password);
	einslen = strlen(einstein);
	
	cout<<"encrypting..."<<endl;
	//encrypt and output to file
	while ((fch = getc(inFile)) != EOF )
	{
		if ( p >= passlen) p = 0;  //reset
		if ( e >= einslen) e = 0;
		if ( count >= sizeof(int) - 260) count = 0;
		pch = password[p];
		ech = einstein[e];
		kch = getc(keyFile);
		if (kch == EOF)
		{
			rewind(keyFile);
			kch = getc(keyFile);
		}

		ach = (ech + kch) / 2;

		if (isInflated)
		{
			//adds fluff
			pbaffle = count / modf(atan((double)pch / ach) * degrees, &trash);
			ebaffle = count / modf(atan((double)ach / pch) * degrees, &trash);
			if (pbaffle < ebaffle)
			{
				//generate seed
				for (int i = 1; i <= p; i++)
					lim = rand() % 5 + 1;
				//fluff range 1-3 characters (0-90 / 30)
				for (int i = 0; i < (atan((double)pch / ach) * degrees) / 30; i++)
				{
					//generate random character
					for (int j = 0; j < lim; j++)
						boggle = rand() % 255;
					//output random fluff character
					putc(boggle, outFile);
				}
			}
		}

		//boggle real character
		boggle = fch + (97 * pch * ach)
					 - (100 / modf((atan((double)pch + count) / ach), &trash));
		//output real character
		putc(boggle, outFile);
		p++; e++; count++;
	}

	if (fclose(inFile) != 0 || fclose(outFile) != 0 || fclose(keyFile) != 0)
		fprintf(stderr, "Error in closing files\n");
	else
		cout<<"File successfully encrypted as "<<fileName<<endl;
	return;
}


void decrypt()
{
	FILE *inFile, *outFile, *keyFile;
	int boggle=0, fch=0, pch=0, ech=0, kch=0, ach=0, e=0, p=0, count=1;
	int passlen, namelen, einslen;
	double pbaffle, ebaffle, trash;
	double degrees = 180 / PI;
	char fileName[MAXFL], password[100], oName[MAXFL], keyFileName[MAXFL];
	bool isInflated = false;

	cout<<"Input file name for decryption."<<endl;
	cin.getline(fileName, 255);
	cout << "Input file name for key." << endl;
	cin.getline(keyFileName, 255);
	cout << "Inflated? Y/N" << endl;
	isInflated = inflate();

	//set up input
	inFile = fopen(fileName, "rb");
	if (!inFile){
		cout<<"Could not open file. decryption failed."<<endl;
		return; }

	//set up output
	namelen = strlen(fileName);
	strncpy(fileName, fileName, namelen - 6); //remove .encpt
	fileName[namelen - 6] = '\0';
	strncpy(oName, fileName, namelen - 6); //save original file name
	//rename file if it exists
	fileExist(fileName, 0);
	outFile = fopen(fileName, "wb");
	if (!outFile){
		cout<<"Could not create out file. Tried to open "<<fileName<<endl;
		return; }

	//setup key file
	keyFile = fopen(keyFileName, "rb");
	if (!keyFile) {
		cout << "Could not open key file. Encryption failed." << endl;
		return;
	}

	//ask for password
	printf("password: ");
	scanf("%s", password);
	passlen = strlen(password);
	einslen = strlen(einstein);
	
	cout<<"decrypting..."<<endl;
	//decrypt and output file
	while ((fch = getc(inFile)) != EOF )
	{
		if ( p >= passlen) p = 0;  //reset
		if ( e >= einslen) e = 0;
		if ( count >= sizeof(int) - 260) count = 0;
		pch = password[p];
		ech = einstein[e];
		kch = getc(keyFile);
		if (kch == EOF)
		{
			rewind(keyFile);
			kch = getc(keyFile);
		}

		ach = (ech + kch) / 2;

		if (isInflated)
		{
			//fluff
			pbaffle = count / modf(atan((double)pch / ach) * degrees, &trash);
			ebaffle = count / modf(atan((double)ach / pch) * degrees, &trash);
			if (pbaffle < ebaffle)
			{
				//fluff range 1-3 characters
				for (int i = 0; i < (atan((double)pch / ach) * degrees) / 30; i++)
				{
					//skip fluff
					if ((fch = getc(inFile)) == EOF) cout << "ERROR: Unexpected EOF" << endl;
				}
			}
		}

		//de-boggle real character
		boggle = fch - (97 * pch * ach)
					 + (100 / modf((atan((double)pch + count) / ach), &trash));
		//output real character
		putc(boggle, outFile);
		p++; e++; count++;
	}

	if (fclose(inFile) != 0 || fclose(outFile) != 0 || fclose(keyFile) != 0)
		fprintf(stderr, "Error in closing files\n");
	else
		cout<<"File successfully decrypted as "<<fileName<<endl;
	return;
}


void fileExist(char fileName[], int copy)
{
	//check if file exists
	FILE *file;
	file = fopen(fileName, "r");
	if (!file) return;
	fclose(file);

	//if exists, rename
	copy++;
	int len=strlen(fileName), i=0, j=0;
	int extlen=0, noext = 0;
	char extension[MAXFL], copyNum[5];	
	int c, digits;

	//get extension
	for(i=len-1; fileName[i] != '.' && i > 0; extlen++, i--);
	if(i == 0)noext=1;
	else extlen++;
	for(i=len-extlen, j=0; j<extlen; i++, j++)
		extension[j] = fileName[i];
	extension[extlen]='\0';

	//cut extension
	if(!noext)
	{
		strncpy(fileName, fileName, len - extlen);
		fileName[len - extlen] = '\0';
	}
	//remove copy number
	if(copy > 1) 
	{
		for(c=copy - 1, digits=1; c>=1; digits++)c=c/10;//get #digits
		digits++;
		len = strlen(fileName);
		strncpy(fileName, fileName, len - digits);
		fileName[len - digits] = '\0';
	}
	//add copy number // D:\directory\filename(#).ext
	strcat(fileName, "(");
	itoa(copy, copyNum, 10);
	strcat(copyNum, ")");
	strcat(fileName, copyNum);
	//paste extension
	if(!noext) strcat(fileName, extension);

	//check if copy exists
	fileExist(fileName, copy);
	return;
}
