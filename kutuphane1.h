#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

//GLOBAL TANIMLAR
int can1=750, can2=750, zirh1=0, zirh2=0, saldiri1=10, saldiri2=10, buyu1=1, buyu2=1, direnc1=0, direnc2=0, sans1=2, sans2=2;
int secenek1,secenek2,secenek3,secenek_kontrol=1,a,b,c,sira=1,secenek_secim;
int tur_sayisi=1;
int giris,cikis;
//Oyun gidiþatýný gösteren üstteki yazýlarýn sayýsal deðerleri için
//p harfi player deðeri, a harfi hamleye baðý deðiþken deðeri, s harfi yazýlacak dizgiyi ifade eder.
//harften sonraki ilk sayý deðiþkenin erkanda etkileði x kordinatýný, ikinci sayý y kordinatýný temsil eder.
char playerstring[2];
char fonksiyonstring[10];
char s[8][90];

//FONKSÝYON TANIMLARI
void imlec_konumu(int,int);

//Ilk iki tamsayi temizlenecek kordinatýn x aralýðý, son iki tamsayý temizlenecek kordinatýn y aralýðý
void sayfayi_temizle(int,int,int,int);

//Ilk tamsayi=cizginin cizilecegi x kordinati, ikinci tamsayi=cizginin uzunlugu, ucuncu tamsayi=cizginin cizilmeye baslayacagý y kordinati
void dikeycizgi(int,int,int);

//Ilk tamsayi=cizginin cizilecegi y kordinati, ikinci tamsayi=cizginin uzunlugu, ucuncu tamsayi=cizginin cizilmeye baslayacagý y kordinati
void yataycizgi(int,int,int);

//Oyuna girmeden önceki gelen ekran
void anamenu(void);

void saldiri_yap (int);
void saldiri_arttir (int);
void buyu_yap (int);
void buyu_arttir (int);
void can_arttir (int);
void zirh_arttir (int);
void sans_arttir (int);
void direnc_arttir (int);

void imlec_konumu(int x, int y){
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void sayfayi_temizle (int x,int x2,int y,int y2){
	int sayacx, sayacy;
	for (sayacx=x; sayacx<(x2+1); sayacx++)
	{
		for (sayacy=y; sayacy<(y2+1); sayacy++)
		{
			imlec_konumu(sayacx,sayacy); printf(" ");
		}
	}
}

void dikeycizgi(int x,int s,int y){
	do
	{
		imlec_konumu(x,y); printf("|"); y+=1; s-=1;
	}
	while (s!=0);
}

void yataycizgi(int y,int s,int x){
	do
	{
		imlec_konumu(x,y); printf("-"); x+=1; s-=1;
	}
	while (s!=0);
}

void anamenu (void){
	
	dikeycizgi(1,25,2);
	dikeycizgi(102,25,2);
	yataycizgi(1,102,1);
	yataycizgi(27,102,1);
	
	imlec_konumu(36,18);
	printf("THE MOST LEGENDARY STRATEGY GAME");
	Sleep(100); imlec_konumu(36,19); printf("|");
	Sleep(100); imlec_konumu(36,19); printf("||");
	Sleep(100); imlec_konumu(36,19); printf("|||");
	Sleep(100); imlec_konumu(36,19); printf("||||");
	Sleep(100); imlec_konumu(36,19); printf("|||||");
	Sleep(100); imlec_konumu(36,19); printf("||||||");
	Sleep(100); imlec_konumu(36,19); printf("|||||||");
	Sleep(100); imlec_konumu(36,19); printf("||||||||");
	Sleep(100); imlec_konumu(36,19); printf("|||||||||");
	Sleep(100); imlec_konumu(36,19); printf("||||||||||");
	Sleep(100); imlec_konumu(36,19); printf("|||||||||||");
	Sleep(100); imlec_konumu(36,19); printf("||||||||||||");
	Sleep(100); imlec_konumu(36,19); printf("|||||||||||||");
	Sleep(800); imlec_konumu(36,19); printf("||||||||||||||");
	Sleep(50);  imlec_konumu(36,19); printf("|||||||||||||||");
	Sleep(75);  imlec_konumu(36,19); printf("||||||||||||||||");
	Sleep(100); imlec_konumu(36,19); printf("|||||||||||||||||");
	Sleep(100); imlec_konumu(36,19); printf("||||||||||||||||||");
	Sleep(150); imlec_konumu(36,19); printf("|||||||||||||||||||");
	Sleep(140); imlec_konumu(36,19); printf("||||||||||||||||||||");
	Sleep(130); imlec_konumu(36,19); printf("|||||||||||||||||||||");
	Sleep(120); imlec_konumu(36,19); printf("||||||||||||||||||||||");
	Sleep(110); imlec_konumu(36,19); printf("|||||||||||||||||||||||");
	Sleep(100); imlec_konumu(36,19); printf("||||||||||||||||||||||||");
	Sleep(90);  imlec_konumu(36,19); printf("|||||||||||||||||||||||||");
	Sleep(80);  imlec_konumu(36,19); printf("||||||||||||||||||||||||||");
	Sleep(70);  imlec_konumu(36,19); printf("|||||||||||||||||||||||||||");
	Sleep(60);  imlec_konumu(36,19); printf("||||||||||||||||||||||||||||");
	Sleep(50);  imlec_konumu(36,19); printf("|||||||||||||||||||||||||||||");
	Sleep(40);  imlec_konumu(36,19); printf("||||||||||||||||||||||||||||||");
	Sleep(30);  imlec_konumu(36,19); printf("|||||||||||||||||||||||||||||||");
	Sleep(20);  imlec_konumu(36,19); printf("||||||||||||||||||||||||||||||||");
	Sleep(2000);
	imlec_konumu(33,20); printf("__88888____888888___888888____88___8__");
	imlec_konumu(33,21); printf("_88_888___88888888_88888888__8888_8___");
	imlec_konumu(33,22); printf("___888___888__888_888__888____88_8____");
	imlec_konumu(33,23); printf("____888___888__888_888__888_____8_____");
	imlec_konumu(33,24); printf("____888___888__888_888__888____8__88__");
	imlec_konumu(33,25); printf("____888___88888888_88888888___8__8888_");
	imlec_konumu(33,26); printf("__8888888__888888___888888___8____88__");
	Sleep(1500);
	imlec_konumu(33,18); printf("                                      ");
	imlec_konumu(33,19); printf("                                      ");
	imlec_konumu(33,20); printf("                                      ");
	imlec_konumu(33,21); printf("                                      ");
	imlec_konumu(33,22); printf("                                      ");
	imlec_konumu(33,23); printf("                                      ");
	imlec_konumu(33,24); printf("                                      ");
	imlec_konumu(33,25); printf("                                      ");
	imlec_konumu(33,26); printf("                                      ");
	
	imlec_konumu(30,2); printf("      .eee.");
	imlec_konumu(30,3); printf("     d"   "$b");
	imlec_konumu(30,4); printf("    $ zF $e $$c");
	imlec_konumu(30,5); printf("..e$     ....$$b");
	imlec_konumu(30,6); printf("    ^$$$$$$$$$$$$");
	imlec_konumu(30,7); printf("              '$$b");
	imlec_konumu(30,8); printf("               $$$");
	imlec_konumu(30,9); printf("            z$$$$%");
	imlec_konumu(30,10); printf("         .d$$$$$'");
	imlec_konumu(30,11); printf("       .$$$$$$'");
	imlec_konumu(30,12); printf("      d$$$$$'");
	imlec_konumu(30,13); printf("     $$$$$'");
	imlec_konumu(30,14); printf("    .$$$$' .e$$$$$$$$$e.");
	imlec_konumu(30,15); printf("    4$$b'3$$$$$$$$$$$$$$$$e");
	imlec_konumu(30,16); printf("     $$F  $$$$$$$$$$$$$$$$$$$e");
	imlec_konumu(30,17); printf("     *$$.  $$$$$$$$$$$$$$$$$$$$$c");
	imlec_konumu(30,18); printf("      $$$.  ^$$$$$$$$$$$$$$$$$$$$$$c");
	imlec_konumu(30,19); printf("       *$$c    *$$$$$$$$$$$$$$$$$$$$$$.");
	imlec_konumu(30,20); printf("        ^$$b     ^*$$$$$$$$$$$$$$$$$$$$$$c");
	imlec_konumu(30,21); printf("          *$$c       '*$$$$$$$$$$$$$$$$$$$$$e.");
	imlec_konumu(30,22); printf("            *$$c          ''******'^E''e. '*'");
	imlec_konumu(30,23); printf("              *$$b.               $$$$e. *b. zP.");
	imlec_konumu(30,24); printf("                *$$$e            .*$. *$*4$ '%.  ^");
	imlec_konumu(30,25); printf("                ^$$$$$$c      /'    $c  b. '[  4$@");
	imlec_konumu(25,26); printf("This game was designed by Muhammed Sadun Cakmakli (KONZRALLES).");
	Sleep(4000);
	sayfayi_temizle(1,102,1,27);

	while(1)
	{
	dikeycizgi(1,25,2);
	dikeycizgi(102,25,2);
	yataycizgi(1,102,1);
	yataycizgi(27,102,1);
	
	imlec_konumu(35,15); printf("Oyuna baslamak icin ESC'ye basiniz.");
	Sleep (250);
	

	secenek_secim=getch();
	if(secenek_secim==27) break;
	}
	sayfayi_temizle(1,102,1,27);
	
}

void saldiri_yap (int player) {
	int hasar;
	int a;
	if (player==1)
	{
		hasar=(rand()%sans1)+saldiri1-zirh2;
		sira=2;
		if (hasar>0)
		{
			can2-=hasar;
		}
		else
		{
			//imlec_konumu(2,2); printf("MISS.. Hasar zirh tarafindan tamamen absorbe edildi.");
			strcat(s[0],"MISS.. 1.Oyuncunun yapmis oldugu saldiri zirh tarafindan tamamen absorbe edildi.");
			imlec_konumu(2,2); printf("%s",s[0]);
			imlec_konumu(2,3); printf("%s",s[1]);
			imlec_konumu(2,4); printf("%s",s[2]);
			imlec_konumu(2,5); printf("%s",s[3]);
			imlec_konumu(2,6); printf("%s",s[4]);
			imlec_konumu(2,7); printf("%s",s[5]);
			imlec_konumu(2,8); printf("%s",s[6]);
			imlec_konumu(2,9); printf("%s",s[7]);
			
			for (a=0; a<=5; a++)
			{
			system("color 07");
			Sleep(25);
			system("color 0F");
			}			
		}
	}
	if (player==2)
	{
		hasar=(rand()%sans2)+saldiri2-zirh1;
		sira=1;
		if (hasar>0)
		{
			can1-=hasar;
		}
		else
		{
			//imlec_konumu(2,2); printf("MISS.. Hasar zirh tarafindan tamamen absorbe edildi.");
			strcat(s[0],"MISS.. 2.Oyuncunun yapmis oldugu saldiri zirh tarafindan tamamen absorbe edildi.");
			imlec_konumu(2,2); printf("%s",s[0]);
			imlec_konumu(2,3); printf("%s",s[1]);
			imlec_konumu(2,4); printf("%s",s[2]);
			imlec_konumu(2,5); printf("%s",s[3]);
			imlec_konumu(2,6); printf("%s",s[4]);
			imlec_konumu(2,7); printf("%s",s[5]);
			imlec_konumu(2,8); printf("%s",s[6]);
			imlec_konumu(2,9); printf("%s",s[7]);
			
			for (a=0; a<=5; a++)
			{
				system("color 0F");
				Sleep(25);
				system("color 07");
			}			
		}
	}
	if (hasar>0)
	{
		//imlec_konumu(2,2); printf("Player %d dusman kalesine %d hasar verdi.",player,hasar);
		itoa(player,playerstring,10);
		itoa(hasar,fonksiyonstring,10);
		strcat(s[0],"Player ");
		strcat(s[0],playerstring);
		strcat(s[0]," dusman kalesine ");
		strcat(s[0],fonksiyonstring);
		strcat(s[0]," hasar verdi.");
		imlec_konumu(2,2); printf("%s",s[0]);
		imlec_konumu(2,3); printf("%s",s[1]);
		imlec_konumu(2,4); printf("%s",s[2]);
		imlec_konumu(2,5); printf("%s",s[3]);
		imlec_konumu(2,6); printf("%s",s[4]);
		imlec_konumu(2,7); printf("%s",s[5]);
		imlec_konumu(2,8); printf("%s",s[6]);
		imlec_konumu(2,9); printf("%s",s[7]);
		
		for (a=0; a<=5; a++)
		{
			system("color 0C");
			Sleep(25);
			system("color 07");
		}
	}
	secenek_kontrol=1;
}

void saldiri_arttir (int player) {
	int artan_saldiri;
	if (player==1)
	{
		artan_saldiri=(rand()%(3*sans1))+3+(sans1*2);
		saldiri1+=artan_saldiri;
		sira=2;
	}
	if (player==2)
	{
		artan_saldiri=(rand()%(3*sans2))+3+(sans2*2);
		saldiri2+=artan_saldiri;
		sira=1;
	}
	//imlec_konumu(2,2); printf("Player %d nin saldiri gucune %d eklendi.",player,artan_saldiri);
	itoa(player,playerstring,10);
	itoa(artan_saldiri,fonksiyonstring,10);
	strcat(s[0],"Player ");
	strcat(s[0],playerstring);
	strcat(s[0]," nin saldiri gucune ");
	strcat(s[0],fonksiyonstring);
	strcat(s[0]," eklendi.");
	imlec_konumu(2,2); printf("%s",s[0]);
	imlec_konumu(2,3); printf("%s",s[1]);
	imlec_konumu(2,4); printf("%s",s[2]);
	imlec_konumu(2,5); printf("%s",s[3]);
	imlec_konumu(2,6); printf("%s",s[4]);
	imlec_konumu(2,7); printf("%s",s[5]);
	imlec_konumu(2,8); printf("%s",s[6]);
	imlec_konumu(2,9); printf("%s",s[7]);
	
	secenek_kontrol=1;
}

void buyu_yap (int player) {
	int buyu_hasar;
	if (player==1)
	{
		buyu_hasar=(rand()%(sans1/2))+buyu1-direnc2;
		sira=2;
		if (buyu_hasar>0)
		{
			can2-=buyu_hasar;
		}
		else
		{
			//imlec_konumu(2,2); printf("Hasar buyu direnci tarafindan tamamen absorbe edildi.");
			strcat(s[0],"MISS.. 1.Oyuncunun yapmis oldugu buyu direnci tarafindan tamamen absorbe edildi.");
			imlec_konumu(2,2); printf("%s",s[0]);
			imlec_konumu(2,3); printf("%s",s[1]);
			imlec_konumu(2,4); printf("%s",s[2]);
			imlec_konumu(2,5); printf("%s",s[3]);
			imlec_konumu(2,6); printf("%s",s[4]);
			imlec_konumu(2,7); printf("%s",s[5]);
			imlec_konumu(2,8); printf("%s",s[6]);
			imlec_konumu(2,9); printf("%s",s[7]);
			
			for (a=0; a<=5; a++)
			{
				system("color 0F");
				Sleep(25);
				system("color 07");
			}			
		}
	}
	if (player==2)
	{
		buyu_hasar=(rand()%(sans2/2))+buyu2-direnc1;
		sira=1;
		if (buyu_hasar>0)
		{
			can1-=buyu_hasar;
		}
		else
		{
			//imlec_konumu(2,2); printf("Hasar buyu direnci tarafindan tamamen absorbe edildi.");
			strcat(s[0],"MISS.. 2.Oyuncunun yapmis oldugu buyu direnci tarafindan tamamen absorbe edildi.");
			imlec_konumu(2,2); printf("%s",s[0]);
			imlec_konumu(2,3); printf("%s",s[1]);
			imlec_konumu(2,4); printf("%s",s[2]);
			imlec_konumu(2,5); printf("%s",s[3]);
			imlec_konumu(2,6); printf("%s",s[4]);
			imlec_konumu(2,7); printf("%s",s[5]);
			imlec_konumu(2,8); printf("%s",s[6]);
			imlec_konumu(2,9); printf("%s",s[7]);
			
			for (a=0; a<=5; a++)
			{
				system("color 0F");
				Sleep(25);
				system("color 07");
			}			
		}
	}
	if (buyu_hasar>0)
	{
		//imlec_konumu(2,2); printf("Player %d dusman kalesine %d buyu hasari verdi.",player,buyu_hasar);
		itoa(player,playerstring,10);
		itoa(buyu_hasar,fonksiyonstring,10);
		strcat(s[0],"Player ");
		strcat(s[0],playerstring);
		strcat(s[0]," dusman kalesine ");
		strcat(s[0],fonksiyonstring);
		strcat(s[0]," buyu hasari verdi.");
		imlec_konumu(2,2); printf("%s",s[0]);
		imlec_konumu(2,3); printf("%s",s[1]);
		imlec_konumu(2,4); printf("%s",s[2]);
		imlec_konumu(2,5); printf("%s",s[3]);
		imlec_konumu(2,6); printf("%s",s[4]);
		imlec_konumu(2,7); printf("%s",s[5]);
		imlec_konumu(2,8); printf("%s",s[6]);
		imlec_konumu(2,9); printf("%s",s[7]);
		int a;
		for (a=0; a<=5; a++)
		{
			system("color 0C");
			Sleep(25);
			system("color 07");
		}
	}
	secenek_kontrol=1;
}

void buyu_arttir (int player) {
	int artan_buyu;
	if (player==1)
	{
		artan_buyu=(rand()%(sans1*2))+1+sans1;
		buyu1+=artan_buyu;
		sira=2;
	}
	if (player==2)
	{
		artan_buyu=(rand()%(sans2*2))+1+sans2;
		buyu2+=artan_buyu;
		sira=1;
	}
	//imlec_konumu(2,2); printf("Player %d nin buyu gucune %d eklendi.",player,artan_buyu);
	itoa(player,playerstring,10);
	itoa(artan_buyu,fonksiyonstring,10);
	strcat(s[0],"Player ");
	strcat(s[0],playerstring);
	strcat(s[0]," nin buyu gucune ");
	strcat(s[0],fonksiyonstring);
	strcat(s[0]," eklendi.");
	imlec_konumu(2,2); printf("%s",s[0]);
	imlec_konumu(2,3); printf("%s",s[1]);
	imlec_konumu(2,4); printf("%s",s[2]);
	imlec_konumu(2,5); printf("%s",s[3]);
	imlec_konumu(2,6); printf("%s",s[4]);
	imlec_konumu(2,7); printf("%s",s[5]);
	imlec_konumu(2,8); printf("%s",s[6]);
	imlec_konumu(2,9); printf("%s",s[7]);
	
	secenek_kontrol=1;
}

void can_arttir (int player) {
	int artan_can;
	if (player==1)
	{
		artan_can=(rand()%(sans1*7))+10+(sans1*4);
		can1+=artan_can;
		sira=2;
	}
	if (player==2)
	{
		artan_can=(rand()%(sans2*7))+10+(sans2*4);
		can2+=artan_can;
		sira=1;
	}
	//imlec_konumu(2,2); printf("Player %d nin can puanina %d eklendi.",player,artan_can);
	itoa(player,playerstring,10);
	itoa(artan_can,fonksiyonstring,10);
	strcat(s[0],"Player ");
	strcat(s[0],playerstring);
	strcat(s[0]," nin can puanina ");
	strcat(s[0],fonksiyonstring);
	strcat(s[0]," eklendi.");
	imlec_konumu(2,2); printf("%s",s[0]);
	imlec_konumu(2,3); printf("%s",s[1]);
	imlec_konumu(2,4); printf("%s",s[2]);
	imlec_konumu(2,5); printf("%s",s[3]);
	imlec_konumu(2,6); printf("%s",s[4]);
	imlec_konumu(2,7); printf("%s",s[5]);
	imlec_konumu(2,8); printf("%s",s[6]);
	imlec_konumu(2,9); printf("%s",s[7]);
	
	secenek_kontrol=1;
}

void zirh_arttir (int player) {
	int artan_zirh;
	if (player==1)
	{
		artan_zirh=(rand()%(sans1*3))+10+(sans1*2);
		zirh1+=artan_zirh;
		sira=2;
	}
	if (player==2)
	{
		artan_zirh=(rand()%(sans2*3))+10+(sans2*2);
		zirh2+=artan_zirh;
		sira=1;
	}
	//imlec_konumu(2,2); printf("Player %d nin zirhi %d kadar guclendi.",player,artan_zirh);
	itoa(player,playerstring,10);
	itoa(artan_zirh,fonksiyonstring,10);
	strcat(s[0],"Player ");
	strcat(s[0],playerstring);
	strcat(s[0]," nin zirhi ");
	strcat(s[0],fonksiyonstring);
	strcat(s[0]," kadar guclendi.");
	imlec_konumu(2,2); printf("%s",s[0]);
	imlec_konumu(2,3); printf("%s",s[1]);
	imlec_konumu(2,4); printf("%s",s[2]);
	imlec_konumu(2,5); printf("%s",s[3]);
	imlec_konumu(2,6); printf("%s",s[4]);
	imlec_konumu(2,7); printf("%s",s[5]);
	imlec_konumu(2,8); printf("%s",s[6]);
	imlec_konumu(2,9); printf("%s",s[7]);
	
	secenek_kontrol=1;
}

void sans_arttir (int player) {
	int artan_sans;
	artan_sans=(rand()%2)+2;
	if (player==1)
	{
		if (sans1 > sans2)
		{
			sans1+=artan_sans;
			sira=2;	
		}
		else
		{
			artan_sans+=1;
			sans1+=artan_sans;
			sira=2;	
		}
	}
	if (player==2)
	{
		if (sans1 > sans2)
		{
			artan_sans+=1;
			sans2+=artan_sans;
			sira=1;
		}
		else
		{
			sans2+=artan_sans;
			sira=1;
		}
	}
	//imlec_konumu(2,2); printf("Player %d nin zekasina %d eklendi.",player,artan_sans);
	itoa(player,playerstring,10);
	itoa(artan_sans,fonksiyonstring,10);
	strcat(s[0],"Player ");
	strcat(s[0],playerstring);
	strcat(s[0]," nin zekasina ");
	strcat(s[0],fonksiyonstring);
	strcat(s[0]," eklendi.");
	imlec_konumu(2,2); printf("%s",s[0]);
	imlec_konumu(2,3); printf("%s",s[1]);
	imlec_konumu(2,4); printf("%s",s[2]);
	imlec_konumu(2,5); printf("%s",s[3]);
	imlec_konumu(2,6); printf("%s",s[4]);
	imlec_konumu(2,7); printf("%s",s[5]);
	imlec_konumu(2,8); printf("%s",s[6]);
	imlec_konumu(2,9); printf("%s",s[7]);
	
	secenek_kontrol=1;
}

void direnc_arttir (int player) {
	int artan_direnc;
	if (player==1)
	{
		artan_direnc=(rand()%(sans1*2))+sans1;
		direnc1+=artan_direnc;
		sira=2;
	}
	if (player==2)
	{
		artan_direnc=(rand()%(sans2*2))+sans2;
		direnc2+=artan_direnc;
		sira=1;
	}
	//imlec_konumu(2,2); printf("Player %d nin buyu direnci %d kadar guclendi.",player,artan_direnc);
	{
		itoa(player,playerstring,10);
		itoa(artan_direnc,fonksiyonstring,10);
		strcat(s[0],"Player ");
		strcat(s[0],playerstring);
		strcat(s[0]," nin buyu direnci ");
		strcat(s[0],fonksiyonstring);
		strcat(s[0]," kadar guclendi.");
		imlec_konumu(2,2); printf("%s",s[0]);
		imlec_konumu(2,3); printf("%s",s[1]);
		imlec_konumu(2,4); printf("%s",s[2]);
		imlec_konumu(2,5); printf("%s",s[3]);
		imlec_konumu(2,6); printf("%s",s[4]);
		imlec_konumu(2,7); printf("%s",s[5]);
		imlec_konumu(2,8); printf("%s",s[6]);
		imlec_konumu(2,9); printf("%s",s[7]);
	}
	
	secenek_kontrol=1;
}
