#include "kutuphane1.h"
int main (void)
{
	anamenu();
	srand(time(NULL));
	while (can1>0&&can2>0)
	{
		//Oyunun oynandýgý cerceve icin
		dikeycizgi(1,25,2);
		dikeycizgi(102,25,2);
		yataycizgi(1,102,1);
		yataycizgi(27,102,1);
		yataycizgi(17,100,2);
		yataycizgi(22,100,2);
		dikeycizgi(50,4,18);
		dikeycizgi(50,4,23);
		yataycizgi(10,100,2);
		
		
		//Alt kisimdaki gostergeler icin
		{
			/*Temizleme satýrý*/ sayfayi_temizle(2,49,23,23);
		imlec_konumu(2,23); printf("1. oyuncu Can:%d",can1);
			/*Temizleme satýrý*/ sayfayi_temizle(2,49,24,24);
		imlec_konumu(2,24); printf("Guc:%d Buyu Gucu:%d",saldiri1, buyu1);
			/*Temizleme satýrý*/ sayfayi_temizle(2,49,25,25);
		imlec_konumu(2,25); printf("Zirh:%d Buyu Direnci:%d Zeka:%d",zirh1,direnc1,sans1);
			/*Temizleme satýrý*/ sayfayi_temizle(51,101,23,23);
		imlec_konumu(51,23); printf("2. oyuncu Can:%d",can2);
			/*Temizleme satýrý*/ sayfayi_temizle(51,101,24,24);
		imlec_konumu(51,24); printf("Guc:%d Buyu Gucu:%d",saldiri2, buyu2);
			/*Temizleme satýrý*/ sayfayi_temizle(51,101,25,25);
		imlec_konumu(51,25); printf("Zirh:%d Buyu Direnci:%d Zeka:%d",zirh2,direnc2,sans2);
		}
		//Oyuncunun kendi sýrasýnda yapacagý hamle icin
		int sayac;
		for (sayac=1; sayac<=3; sayac++)
		{
			secenek1=(rand()%8);
			secenek2=(rand()%8);
			do
			{
				if (secenek2==secenek1)
				{
					secenek2=(rand()%8);
				}
			}
			while (secenek2==secenek1);
			secenek3=(rand()%8);
			do
			{
				if (secenek3==secenek2||secenek3==secenek1)
				{
					secenek3=(rand()%8);
				}
			}
			while (secenek3==secenek2||secenek3==secenek1);
		}
		if (secenek_kontrol)
		{
			a=secenek1;
			b=secenek2;
			c=secenek3;
			
			strcpy(s[7],s[6]);
			strcpy(s[6],s[5]);
			strcpy(s[5],s[4]);
			strcpy(s[4],s[3]);
			strcpy(s[3],s[2]);
			strcpy(s[2],s[1]);
			strcpy(s[1],s[0]);
			
			int sayacs;
			for (sayacs=0;sayacs<90;sayacs++)
			{
				s[0][sayacs]='\0';
			}
			
			secenek_kontrol=0;
			
			tur_sayisi+=1;
			
			if (sira==1)
			system("color A");
			else
			system("color B");
			
		}
		
		//DEBUG MODE
		sayfayi_temizle(2,101,11,14); //Debug alaný temizliði !
		imlec_konumu(2,11);int x=rand(); printf("RANDOM:%d",x);
		imlec_konumu(2,13); printf("A:%d,B:%d,C:%d",a,b,c);
		imlec_konumu (2,14); printf ("Secenek kontrol %d",secenek_kontrol);
		imlec_konumu(2,12); printf("%d,%d,%d",secenek1,secenek2,secenek3);
		
		imlec_konumu (90,2); printf("%d.Hamle",(tur_sayisi-1));
		imlec_konumu (90,3); printf("%d.Tur",(tur_sayisi/2));
	
		//Secenek secim bölgesini temizleme (Üstten 3. Kýsým-Alttan 2. Kýsým)
		sayfayi_temizle(2,49,18,21); //1.Oyuncu bölgesini temizleme
		sayfayi_temizle(51,101,18,21); //2.Oyuncu bölgesini temizleme
		
		if (sira==1) imlec_konumu (2,18);
		else imlec_konumu (51,18);
		printf("%d.OYUNCUNUN SIRASI",sira);
		
		if (sira==1) imlec_konumu (2,19);
		else imlec_konumu (51,19);
		
		if (a==0)
		{
			printf("Saldiri yap.");
		}
		if (a==1)
		{
			printf("Gucunu arttir.");
		}
		if (a==2)
		{
			printf("Buyu yap.");
		}
		if (a==3)
		{
			printf("Buyu gucunu arttir.");
		}
		if (a==4)
		{
			printf("Can puanini arttir.");
		}
		if (a==5)
		{
			printf("Zirhini guclendir.");
		}
		if (a==6)
		{
			printf("Zekayi arttir.");
		}
		if (a==7)
		{
			printf("Buyu direncini arttir.");
		}
		
		if (sira==1) imlec_konumu (2,20);
		else imlec_konumu (51,20);
		if (b==0)
		{
			printf("Saldiri yap.");
		}
		if (b==1)
		{
			printf("Gucunu arttir.");
		}
		if (b==2)
		{
			printf("Buyu yap.");
		}
		if (b==3)
		{
			printf("Buyu gucunu arttir.");
		}
			if (b==4)
		{
			printf("Can puanini arttir.");
		}
		if (b==5)
		{
			printf("Zirhini guclendir.");
		}
		if (b==6)
		{
			printf("Zekayi arttir.");
		}
		if (b==7)
		{
			printf("Buyu direncini arttir.");
		}
		
		if (sira==1) imlec_konumu (2,21);
		else imlec_konumu (51,21);
		if (c==0)
		{
			printf("Saldiri yap.");
		}
		if (c==1)
		{
			printf("Gucunu arttir.");
		}
		if (c==2)
		{
			printf("Buyu yap.");
		}
		if (c==3)
		{
			printf("Buyu gucunu arttir.");
		}
		if (c==4)
		{
			printf("Can puanini arttir.");
		}
		if (c==5)
		{
			printf("Zirhini guclendir.");
		}
		if (c==6)
		{
			printf("Zekayi arttir.");
		}
		if (c==7)
		{
			printf("Buyu direncini arttir.");
		}
		Sleep(250);
	
		//DEÐÝÞTÝRÝLEN BÖLGE (0.4.0)
		secenek_secim=getch();
		giris=sira;
		if (secenek_secim==49||secenek_secim==50||secenek_secim==51)
		{
			sayfayi_temizle(2,101,2,9);  //Oyun Özeti Bölgesi temizleme (En üst kýsým)
		}
		if (secenek_secim==49)
		{
			if (a==0)
			{
				if (sira==1)
				{
					saldiri_yap (1);
					//sira=2;
				}
				else
				{
					saldiri_yap (2);
					//sira=1;
				}
			}
			else if (a==1)
			{
				if (sira==1)
				{
					saldiri_arttir (1);
					//sira=2;
				}
				else
				{
					saldiri_arttir (2);
					//sira=1;
				}
			}
			else if (a==2)
			{
				if (sira==1)
				{
					buyu_yap (1);
					//sira=2;
				}
				else
				{
					buyu_yap (2);
					//sira=1;
				}
			}
			else if (a==3)
			{
				if (sira==1)
				{
					buyu_arttir (1);
					//sira=2;
				}
				else
				{
					buyu_arttir (2);
					//sira=1;
				}
			}
			else if (a==4)
			{
				if (sira==1)
				{
					can_arttir (1);
					//sira=2;
				}
				else
				{
					can_arttir (2);
					//sira=1;
				}
			}
			else if (a==5)
			{
				if (sira==1)
				{
					zirh_arttir (1);
					//sira=2;
				}
				else
				{
					zirh_arttir (2);
					//sira=1;
				}
			}
			else if (a==6)
			{
				if (sira==1)
				{
					sans_arttir (1);
					//sira=2;
				}
				else
				{
					sans_arttir (2);
					//sira=1;
				}
			}
			else if (a==7)
			{
				if (sira==1)
				{
					direnc_arttir (1);
					//sira=2;
				}
				else
				{
					direnc_arttir (2);
					//sira=1;
				}
			}
		}
		else if (secenek_secim==50)
		{
			if (b==0)
			{
				if (sira==1)
				{
					saldiri_yap(1);
					//sira=2;
				}
				else
				{
					saldiri_yap(2);
					//sira=1;
				}
			}
			else if (b==1)
			{
				if (sira==1)
				{
					saldiri_arttir(1);
					//sira=2;
				}
				else
				{
					saldiri_arttir(2);
					//sira=1;
				}
			}
			else if (b==2)
			{
				if (sira==1)
				{
					buyu_yap(1);
					//sira=2;
				}
				else
				{
					buyu_yap(2);
					//sira=1;
				}
			}
			else if (b==3)
			{
				if (sira==1)
				{
					buyu_arttir(1);
					//sira=2;
				}
				else
				{
					buyu_arttir(2);
					//sira=1;
				}
			}
			else if (b==4)
			{
				if (sira==1)
				{
					can_arttir(1);
					//sira=2;
				}
				else
				{
					can_arttir(2);
					//sira=1;
				}
			}
			else if (b==5)
			{
				if (sira==1)
				{
					zirh_arttir(1);
					//sira=2;
				}
				else
				{
					zirh_arttir(2);
					//sira=1;
				}
			}
			else if (b==6)
			{
				if (sira==1)
				{
					sans_arttir(1);
					//sira=2;
				}
				else
				{
					sans_arttir(2);
					//sira=1;
				}
			}
			else if (b==7)
			{
				if (sira==1)
				{
					direnc_arttir(1);
					//sira=2;
				}
				else
				{
					direnc_arttir(2);
					//sira=1;
				}
			}
		}
		else if (secenek_secim==51)
		{
			if (c==0)
			{
				if (sira==1)
				{
					saldiri_yap(1);
					//sira=2;
				}
				else
				{
					saldiri_yap(2);
					//sira=1;
				}
			}
			else if (c==1)
			{
				if (sira==1)
				{
					saldiri_arttir(1);
					//sira=2;
				}
				else
				{
					saldiri_arttir(2);
					//sira=1;
				}
			}
			else if (c==2)
			{
				if (sira==1)
				{
					buyu_yap(1);
					//sira=2;
				}
				else
				{
					buyu_yap(2);
					//sira=1;
				}
			}
			else if (c==3)
			{
				if (sira==1)
				{
					buyu_arttir(1);
					//sira=2;
				}
				else
				{
					buyu_arttir(2);
					//sira=1;
				}
			}
			else if (c==4)
			{
				if (sira==1)
				{
					can_arttir(1);
					//sira=2;
				}
				else
				{
					can_arttir(2);
					//sira=1;
				}
			}
				else if (c==5)
			{
				if (sira==1)
				{
					zirh_arttir(1);
					//sira=2;
				}
				else
				{
					zirh_arttir(2);
					//sira=1;
				}
			}
			else if (c==6)
			{
				if (sira==1)
				{
					sans_arttir(1);
					//sira=2;
				}
				else
				{
					sans_arttir(2);
					//sira=1;
				}
			}
			else if (c==7)
			{
				if (sira==1)
				{
					direnc_arttir(1);
					//sira=2;
				}
				else
				{
					direnc_arttir(2);
					//sira=1;
				}
			}
		}
	}
//KAZANMA KOÞULLARI
if (can1<0)
{
	//100 Satýrlýk temizleme
	imlec_konumu(2,10); printf("                                                                                                    ");
	imlec_konumu(2,10); printf("2.Oyuncu Kazandi. Cikmak icin ESC");
}
if (can2<0)
{
	//100 Satýrlýk temizleme
	imlec_konumu(2,10); printf("                                                                                                    ");
	imlec_konumu(2,10); printf("1.Oyuncu Kazandi. Cikmak icin ESC");
}
int ESCAPE;
do
{
	ESCAPE=getch();
}
while(ESCAPE!=27);
return(0);
}


