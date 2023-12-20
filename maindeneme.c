#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct kullanicibilgi {                        // tüm kullanicilarin verisinin tutuldugu kisim
    int kullanicisayi;
    char kullaniciadi[100][10];
    char kullanicisifre[100][10];
};

struct ilanekle {                                   // ilan bilgilerinin tutuldugu kisim
    char il[100][16];
    char ilce[100][20];
    char mahalle[100][20];
    char sokak[100][20];
    char no[100][20];
    // yukarisi adres için
    char tip[100][10];                   // tip 1 = daire&müstakil
    char tip2[100][10];                  //tip2=satilik&kiralik
    char fiat[100][50], kare[100][50];      // fiat = mülkün fiyati kare=mülkün metre karesi
    char tur[100][10];                      // Arsami ev mi tarlami olayi
    char oda[100][5];                       // Evin kaç odali oldugunu sormak icin sadece tur=ev olunca calisiyor
    char telno[100][12];                    // iletisim numarasi icin
    int ilanno;                            // ilan numarasi her uygulama açildiginda 0'dan baslar max 100 üye kayit olabilir artirmak için void kayittan artirabilirsiniz
};

void ilanekleme(struct ilanekle *ilanlar) {
    printf("                                         -------------Gelisim Emlak------------- \n");
    printf("                                         |             Ilan Ekleme             |\n");
    printf("                                         |Mulkunuzun tipini giriniz            |\n");
    printf("                                         |Ev                                   |\n");
    printf("                                         |Arsa                                 |\n");
    printf("                                         |Tarla                                |\n");
    printf("                                         ---------------------------------------\n");
    printf("                                         [Isleminizi giriniz: ");
    scanf("%s", ilanlar->tur[ilanlar->ilanno]);
    system("cls");
    
    if (strcmp(ilanlar->tur[ilanlar->ilanno], "Ev") != 0 && strcmp(ilanlar->tur[ilanlar->ilanno], "ev") != 0 &&
        strcmp(ilanlar->tur[ilanlar->ilanno], "EV") != 0 && strcmp(ilanlar->tur[ilanlar->ilanno], "Arsa") != 0 && 
		strcmp(ilanlar->tur[ilanlar->ilanno], "ARSA") != 0 && strcmp(ilanlar->tur[ilanlar->ilanno], "arsa") != 0 &&
		strcmp(ilanlar->tur[ilanlar->ilanno], "TARLA") != 0 && strcmp(ilanlar->tur[ilanlar->ilanno], "tarla") != 0 &&
		strcmp(ilanlar->tur[ilanlar->ilanno], "Tarla") != 0) {
			printf("                                         Hatali secim!!!\n");                           // arsa tarla ev disinda bir sey girilirse hata verilen kisim
            sleep(2);
            system("cls");
            ilanekleme(ilanlar);
	}
    if (strcmp(ilanlar->tur[ilanlar->ilanno], "Ev") == 0 || strcmp(ilanlar->tur[ilanlar->ilanno], "ev") == 0 ||  // evin her türlü giris secenegi icin bu sekilde yazildi
        strcmp(ilanlar->tur[ilanlar->ilanno], "EV") == 0) {                                                      // Farkli secenekler eklenicekse su sekilde eklenebilir
        printf("                                         -------------Gelisim Emlak------------- \n");           //|| strcmp(ilanlar->tur[ilanlar->ilanno], "secenek") == 0
		printf("                                         |             Ilan Ekleme             |\n");
		printf("                                         |Evinizin tipini giriniz              |\n");
		printf("                                         |Daire                                |\n");
		printf("                                         |Mustakil                             |\n");
	//	printf("|                                |\n");        Buraya ilerde bir sey ekleyebilmek icin biraktik
		printf("                                         ---------------------------------------\n");
		printf("                                         [Isleminizi giriniz: ");
        scanf("%s", ilanlar->tip[ilanlar->ilanno]);
		system("cls");
        if (strcmp(ilanlar->tip[ilanlar->ilanno], "Daire") == 0 || strcmp(ilanlar->tip[ilanlar->ilanno], "daire") == 0 ||  // Evdeki olayin aynisi
            strcmp(ilanlar->tip[ilanlar->ilanno], "Mustakil") == 0 || strcmp(ilanlar->tip[ilanlar->ilanno], "mustakil") == 0) {
        printf("                                         -------------Gelisim Emlak------------- \n");
		printf("                                         |             Ilan Ekleme             |\n");
		printf("                                         |Satis tipini giriniz                 |\n");
		printf("                                         |Satilik                              |\n");
		printf("                                         |Kiralik                              |\n");
	//	printf("|                                |\n");        Buraya ilerde bir sey ekleyebilmek icin biraktik
		printf("                                         ---------------------------------------\n");
		printf("                                         [Isleminizi giriniz: ");
            scanf("%s", ilanlar->tip2[ilanlar->ilanno]);
            system("cls");

            if (strcmp(ilanlar->tip2[ilanlar->ilanno], "satilik") != 0 && strcmp(ilanlar->tip2[ilanlar->ilanno], "Satilik") != 0 &&// evdeki olayin aynisi sadece burada satilik yada kiralik 
                strcmp(ilanlar->tip2[ilanlar->ilanno], "kiralik") != 0 && strcmp(ilanlar->tip2[ilanlar->ilanno], "Kiralik") != 0) {// disinda bir sey yazilirsa hatali giris diyor
                printf("                                         Hatali secim!!!\n");
                sleep(2);
                system("cls");
                ilanekleme(ilanlar);
            }
        } else {
            printf("                                         Hatali secim!!!\n");        // daire&ev disinda bir sey girilirse hata verilen kisim
            sleep(2);
            system("cls");
            ilanekleme(ilanlar);
        }
    }
    printf("                                         Ilan Adresini sirasiyla giriniz (il-ilce-mahalle-sokak-no)\n");         
    printf("                                         Il: ");
    scanf("%s", ilanlar->il[ilanlar->ilanno]);
    printf("                                         Ilce: ");
    scanf("%s", ilanlar->ilce[ilanlar->ilanno]);
    printf("                                         Mahalle: ");
    scanf("%s", ilanlar->mahalle[ilanlar->ilanno]);
    printf("                                         Sokak: ");
    scanf("%s", ilanlar->sokak[ilanlar->ilanno]);
    printf("                                         No: ");
    scanf("%s", ilanlar->no[ilanlar->ilanno]);

    printf("                                         %s'nizin metre karesini giriniz: ", ilanlar->tur[ilanlar->ilanno]);
    scanf("%s", ilanlar->kare[ilanlar->ilanno]);
    
    if (strcmp(ilanlar->tur[ilanlar->ilanno], "Ev") == 0 || strcmp(ilanlar->tur[ilanlar->ilanno], "ev") == 0 ||
        strcmp(ilanlar->tur[ilanlar->ilanno], "EV") == 0) {
        	printf("                                         Evinizin oda sayisini giriniz(orn:3+1,2+1): ");
        	scanf("%s",ilanlar->oda[ilanlar->ilanno]);
        }
        

    printf("                                         %s'nizin fiyatini giriniz: ", ilanlar->tur[ilanlar->ilanno]);
    scanf("%s", ilanlar->fiat[ilanlar->ilanno]);
    
    printf("                                         Iletisim Numarasi giriniz: " );
    scanf("%s", ilanlar->telno[ilanlar->ilanno]);

    printf("                                         Ilan Basariyla eklendi ilan numarasi: %d\n", ilanlar->ilanno+1);
    ilanlar->ilanno++;                                                                                                  // her ilan eklendikten sonra bu satirda ilan numarasi artiriliyor
    sleep(1);
    system("cls");
}

void ilankaldir(struct ilanekle *ilanlar) {
	
    int ilankaldir;                       //kaldirilicak ilanin numarasini almak içino lan degisken
    int i;

    if (ilanlar->ilanno == 0) {
        printf("                                         Silinecek bir ilan yok!\n");
    } else {
        printf("                                         Silmek istediginiz ilan numarasini giriniz: ");
        scanf("%d", &ilankaldir);

        if (ilankaldir < 1 || ilankaldir > ilanlar->ilanno) {                                           // eger ilankaldir = -sayi & ilankaldir > ilansayisindan olursa hata verir
            printf("                                         Hatali ilan numarasi girildi!\n");
        } else {
            for (i = ilankaldir - 1; i < ilanlar->ilanno - 1; ++i) {
                strcpy(ilanlar->il[i], ilanlar->il[i + 1]);                                    // buradaki temel mantik mesela 1. numarada bir ilan var biz bunu kaldirmak istiyoruz
                strcpy(ilanlar->ilce[i], ilanlar->ilce[i + 1]);                                // 1.deki ilanin üstüne 2. numaradaki ilanin bilgilerini yaziyor(Aslinda degistiriyor)
                strcpy(ilanlar->mahalle[i], ilanlar->mahalle[i + 1]);                         
                strcpy(ilanlar->sokak[i], ilanlar->sokak[i + 1]);
                strcpy(ilanlar->no[i], ilanlar->no[i + 1]);
                strcpy(ilanlar->tip[i], ilanlar->tip[i + 1]);
                strcpy(ilanlar->tip2[i], ilanlar->tip2[i + 1]);
                strcpy(ilanlar->fiat[i], ilanlar->fiat[i + 1]);
                strcpy(ilanlar->oda[i], ilanlar->oda[i + 1]);
                strcpy(ilanlar->kare[i], ilanlar->kare[i + 1]);
                strcpy(ilanlar->tur[i], ilanlar->tur[i + 1]);
                strcpy(ilanlar->telno[i], ilanlar->telno[i + 1]);
            }

            ilanlar->ilanno--;             // ilan numarasi bir eksiliyor 

            strcpy(ilanlar->il[ilanlar->ilanno], "");                                        // en sondaki ilan numarasinin içini null degere ceviriyor 
            strcpy(ilanlar->ilce[ilanlar->ilanno], "");
            strcpy(ilanlar->mahalle[ilanlar->ilanno], "");
            strcpy(ilanlar->sokak[ilanlar->ilanno], "");
            strcpy(ilanlar->no[ilanlar->ilanno], "");
            strcpy(ilanlar->tip[ilanlar->ilanno], "");
            strcpy(ilanlar->tip2[ilanlar->ilanno], "");
            strcpy(ilanlar->fiat[ilanlar->ilanno], "");
            strcpy(ilanlar->kare[ilanlar->ilanno], "");
            strcpy(ilanlar->oda[ilanlar->ilanno], "");
            strcpy(ilanlar->tur[ilanlar->ilanno], "");
            strcpy(ilanlar->telno[ilanlar->ilanno], "");

            printf("                                         Ilan basariyla kaldirildi!\n");
        }
    }
    sleep(2);
    system("cls");
}

void ilanlisteleme(struct ilanekle *ilanlar) {
    int p;
    char c;
    printf("                                         -------------Gelisim Emlak------------- \n");
	printf("                                          ------------Ilan Listesi-------------\n");
	for(p=0;p<ilanlar->ilanno;p++){
		printf("                                         %d.Ilanin bilgileri\n",p+1);
    	printf("                                         Adres: %s/%s %s Mahallesi NO: %s\n", ilanlar->il[p], ilanlar->ilce[p], ilanlar->mahalle[p], ilanlar->no[p]);
    	printf("                                         Mulkun turu: %s\n", ilanlar->tur[p]);
    	if (strcmp(ilanlar->tur[p], "Ev") == 0 || strcmp(ilanlar->tur[p], "ev") == 0 || strcmp(ilanlar->tur[p], "EV") == 0) {
       	 	printf("                                         Evin tipi: %s\n", ilanlar->tip[p]);
    	}
    	if (strcmp(ilanlar->tur[p], "Ev") == 0 || strcmp(ilanlar->tur[p], "ev") == 0 || strcmp(ilanlar->tur[p], "EV") == 0) {
        	printf("                                         Satis turu: %s\n", ilanlar->tip2[p]);
    	}
    	if (strcmp(ilanlar->tur[p], "Ev") == 0 || strcmp(ilanlar->tur[p], "ev") == 0 || strcmp(ilanlar->tur[p], "EV") == 0) {
        	printf("                                         Oda Sayisi: %s\n", ilanlar->oda[p]);
    	}
    	printf("                                         Metrekare: %sm2\n", ilanlar->kare[p]);
    	printf("                                         Fiyat: %s TL\n", ilanlar->fiat[p]);
    	printf("                                         Iletisim Numarasi: %s\n",ilanlar->telno[p]);
    	printf("                                         Ilan Numarasi: %d\n", p+1);
    	printf("\n\n\n");
	}
	if(ilanlar->ilanno == 0){
		printf("                                         Ilan bulunamadi veya eklenmemis!!\n");
	}
	printf("                                         Cikis yapmak için klavyeden herhangi bir deger girin: ");
	scanf("%s",&c);
	if(c==1){
		printf("                                         Cikis yapiliyor....");
		sleep(2);
		system("cls");
	}
	else{
		printf("                                         Cikis yapiliyor....");
		sleep(2);
		system("cls");
	}
}

void olcer(struct ilanekle *menuilan){
	int mulk,sm;
	float kira,bedel,alan;
	int birim = 330;  //                                                      <----------------------------------- Bu degeri güncel tarihe göre degistirebiliriniz 
	printf("                                         -------------Gelisim Emlak------------- \n");
    printf("                                         |        Mulk Degeri Hesaplama        |\n");
    printf("                                         |Mulkunuzun tipini seciniz            |\n");
    printf("                                         |[1] Ev                               |\n");
    printf("                                         |[2] Arsa                             |\n");
    printf("                                         |[3] Tarla                            |\n");
    printf("                                         ---------------------------------------\n");
    printf("                                         [Isleminizi giriniz: ");
	scanf("%d",&mulk);
	system("cls");
	switch(mulk){
		case 1: 
		  	printf("                                         -------------Gelisim Emlak------------- \n");
    		printf("                                         |        Mulk Degeri Hesaplama        |\n");
   			printf("                                         |Evinizin segmentini giriniz          |\n");
		    printf("                                         |[1] Dusuk                            |\n");
		    printf("                                         |[2] Orta                             |\n");
		    printf("                                         |[3] Yuksek                           |\n");
		    printf("                                         ---------------------------------------\n");
    printf("                                         [Isleminizi giriniz: ");
		  scanf("%d",&sm);
		  system("cls");
		  if(sm==1){                                                     //Dusuk Segment Ev
		  	printf("                                         Evinizin ortalama aylik kira bedeli: ");
		  	scanf("%f",&kira);
		  	system("cls");
		  	printf("                                         Evinizin bedeli hesaplaniyor.\n");
		  	sleep(2);
		  	system("cls");
		  	bedel=kira*214*130/100;         //                <-----------------------------------Buradaki 214 degeri evin 214 kirasini belirtmektedir yani  214 adet kira demek 
		  	printf("                                         Evinizin ortalama bedeli %.2f TL",bedel);
		  }
		  else if(sm==2){                                                //Orta Segment Ev
		  	printf("                                         Evinizin ortalama aylik kira bedeli: ");
		  	scanf("%f",&kira);
		  	system("cls");
		  	printf("                                         Evinizin bedeli hesaplaniyor.\n");
		  	sleep(2);
		  	system("cls");
		  	bedel=kira*214*160/100;
		  	printf("                                         Evinizin ortalama bedeli %.2f TL",bedel);
		  }
		  else if(sm==3){                                                //yüksek segment Ev
		  	printf("                                         Evinizin ortalama aylik kira bedeli: ");
		  	scanf("%f",&kira);
		  	system("cls");
		  	printf("                                         Evinizin bedeli hesaplaniyor.\n");
		  	sleep(2);
		  	system("cls");
		  	bedel=kira*214*200/100;
		  	printf("                                         Evinizin ortalama bedeli %.2f TL",bedel);
		  }
		  else{
		  	printf("                                         Hatali segment girisi");
		  }
		  break;
		case 2:
          printf("                                         Arsanizin metrekaresi ?: ");
          scanf("%f", &alan);
          system("cls");
          bedel = alan*birim*130/100;                                                                         // 130 /100 katki deger payi olarak hesaplaniyor
          printf("                                         Fiyat hesaplaniyor...");
          sleep(3);
          system("cls");
          printf("                                         Arsanizin ortalama fiyati %.2f TL", bedel);    
		case 3:
		  printf("                                         Tarlanizin metrekaresi ?: ");
          scanf("%f", &alan);
          system("cls");
          bedel = alan * birim;
          printf("                                         Fiyat hesaplaniyor...");
          sleep(3);
          system("cls");
          printf("                                         Tarlanizin ortalama fiyati %.2f TL", bedel);
		  break;
		default:
		  printf("                                         Hatali mulk girisi!!!!");
	}
	sleep(3);
	system("cls");
	normalMenu(menuilan);
}

void adminMenu(struct kullanicibilgi *kullanicilar, struct ilanekle *menuilan) {
    int secim,x,c;

    do {
        printf("                                         -------------Admin Menu----------------\n");
        printf("                                         |[1] Kullanici Listele                |\n");
        printf("                                         |[2] Kullanici Kaldir                 |\n");
		printf("                                         |[3] Ilan Ekle                        |\n");
    	printf("                                         |[4] Ilan Kaldir                      |\n");
    	printf("                                         |[5] Ilan listele                     |\n");
    	printf("                                         |[6] Ilan Deger Hesaplayici           |\n");
    	printf("                                         |[7] Oturum Kapatma                   |\n");	
        printf("                                         |[8] Cikis                            |\n");
        printf("                                         ---------------------------------------\n");
        printf("                                         [Isleminizi giriniz: ");
        scanf("%d", &secim);
        system("cls");

        switch (secim) {
            case 1:                                          // kullanici listeleme kismi
            	if(kullanicilar->kullanicisayi>0){
            		for(x=0;x<kullanicilar->kullanicisayi;x++){
            			printf("                                         %d.Kullanicinin Adi: %s\n",x+1,kullanicilar->kullaniciadi[x]);
            			printf("                                         %d.Kullanicinin Sifresi: %s\n\n",x+1,kullanicilar->kullanicisifre[x]);
					}
					printf("                                         Cikis yapmak için klavyeden herhangi bir deger girin: ");
					scanf("%s",&c);
					if(c==1){
						printf("                                         Cikis yapiliyor....");
						sleep(2);
						system("cls");
						}
						else{
						printf("                                         Cikis yapiliyor....");
						sleep(2);
						system("cls");
						}
				}
				else{
					printf("                                        Listelenecek kullanici bulunamadi");
					sleep(2);
					system("cls");
				}
                
                break;
            case 2:                                            // kullanici kaldirma kismi
            	kullanicikaldir(kullanicilar,menuilan);
                break;
            case 3:
            	ilanekleme(menuilan);
            	break;
            case 4:
            	ilankaldir(menuilan);
            	break;
            case 5:                                            // ilan listeleme kismi
            	ilanlisteleme(menuilan);
                break;
            case 6:
            	olcer(menuilan);
            	break;
            case 7:
            	printf("                                         Oturum Kapatiliyor!!");
    			sleep(2);
    			system("cls");
    			return 0;
            case 8:                                                                          // cikis kismi
                printf("                                         Cikis yapiliyor...\n");
                exit(0);
				break;                                                                  
            default:
                printf("                                         Gecersiz secim!\n");
                sleep(3);
                system("cls");
        }

    } while (secim != 4);
}

void kullanicikaldir(struct kullanicibilgi *kullanicilar, struct ilanekle *menuilan){
	int kullanicikaldir;
    int i;

    if (kullanicilar->kullanicisayi == 0) {
        printf("                                         Silinecek bir kullanici yok!\n");                 // bu fonksiyonun genelindeki mantik ilan kaldir ile ayni 
    } else {
        printf("                                         Silmek istediginiz kullanicinin numarasini giriniz: ");
        scanf("%d", &kullanicikaldir);

        if (kullanicikaldir < 1 || kullanicikaldir > kullanicilar->kullanicisayi) {
            printf("                                         Hatali ilan numarasi girildi!\n");
        } else {
            for (i = kullanicikaldir - 1; i < kullanicilar->kullanicisayi - 1; i++) {
                strcpy(kullanicilar->kullaniciadi[i], kullanicilar->kullaniciadi[i + 1]);
                strcpy(kullanicilar->kullanicisifre[i], kullanicilar->kullanicisifre[i + 1]);
            }

            kullanicilar->kullanicisayi--;

            strcpy(kullanicilar->kullaniciadi[kullanicilar->kullanicisayi], "");
            strcpy(kullanicilar->kullanicisifre[kullanicilar->kullanicisayi], "");

            printf("                                         Kullanici basariyla kaldirildi!\n");
        }
    }
    sleep(2);
    system("cls");
}

void kayitMenu() {
    printf("                                         -------------Gelisim Emlak------------- \n");
    printf("                                         |[1] Giris Yap                        |\n");
    printf("                                         |[2] Kayit Ol                         |\n");
    printf("                                         |[3] Cikis                            |\n");
    printf("                                         ---------------------------------------\n");
}

void normalMenu(struct ilanekle *menuilan) {
    int m;

    printf("                                         -------------Gelisim Emlak------------- \n");
    printf("                                         |[1] Ilan Ekle                        |\n");
    printf("                                         |[2] Ilan Kaldir                      |\n");
    printf("                                         |[3] Ilan listele                     |\n");
    printf("                                         |[4] Ilan Deger Hesaplayici           |\n");
    printf("                                         |[5] Oturum Kapatma                   |\n");
    printf("                                         |[6] Cikis                            |\n");
    printf("                                         ---------------------------------------\n");
    printf("                                         [Isleminizi giriniz: ");
    scanf("%d", &m);
    system("cls");

    if (m == 1) {
        ilanekleme(menuilan);
    } else if (m == 2) {
        ilankaldir(menuilan);
        
    } else if (m == 3) {
        ilanlisteleme(menuilan);
    } else if (m == 4) {
       	olcer(menuilan);
    } else if(m == 5){                               // burada oturum kapatilip kayit menüsüne atiliyor 
    	printf("                                         Oturum Kapatiliyor!!");
    	sleep(2);
    	system("cls");
    	return 0;
	}
	else if (m == 6) {
        printf("                                         Cikis yapiliyor...\n");
        sleep(2);
        exit(0);
    } else {
        printf("                                         Hatali giris yapildi\n");
    }
    sleep(3);
    system("cls");
    normalMenu(menuilan);
}

void kayit(struct kullanicibilgi *kullanicilar) {
	int p;
	char kayitad[10],kayitsifre[10];
    if (kullanicilar->kullanicisayi < 100) {                                                                // if'in içindeki 100 degerini artirirsak max kullanicida artar fakat struct
        printf("                                         Kullanici adi giriniz (max 10 karakter): ");        // kullanicibilgi deki kullaniciadi ve kullanicisifre dizisininde icini 
        scanf("%s", kayitad);                                // de degistirmek gerekiyor aksi takdirde burda degismemiz bir önem teskil etmeyecektir
        for(p=0;p<kullanicilar->kullanicisayi+1;p++){
        	if(strcmp(kayitad, kullanicilar->kullaniciadi[p])== 0){
        		printf("                                         Bu kullanici adi kullaniliyor lutfen baska bir kullanici adi giriniz");
        		sleep(3);
        		system("cls");
        		return 0;
			}
		}
        // buraya eger önceden ayni kullanici adi kullanildiysa o kullanici adini kullanamama eklenicek
        
        if(strcmp(kayitad, "admin")!=0){                            // buradaki admin ismini giristeki admin bilgilerine göre güncelleyebilirsiniz
        	printf("                                         Sifre giriniz (max 10 karakter): ");
	        scanf("%s", kayitsifre);
	        
	        
	
	        printf("                                         Kayit Basarili!!\n");
	        strcpy(kullanicilar->kullaniciadi[kullanicilar->kullanicisayi], kayitad);                 //kayit addan alinan bilgiyi dizinin bos kismina yaziyor
            strcpy(kullanicilar->kullanicisifre[kullanicilar->kullanicisayi], kayitsifre);               // ayni sekil
	        sleep(3);
	        system("cls");
	        kullanicilar->kullanicisayi++;
		}
		else {
			printf("                                         Bu kullanici adini kullanamazsiniz!!!");
			sleep(3);
			system("cls");
		}
        
    } else {
        printf("                                         Kullanici limiti asildi!!!\n");
    }
}

void giris(struct kullanicibilgi *kullanicilar, struct ilanekle *menuilan) {
    char sorguad[10], sorgusifre[10]; //sorgu için
    char adminAd[]="admin",adminSifre[]="admin";  //Admin menüsü için giris bilgileri burada 
	int i;
	
    printf("                                         Kullanici Adiniz : ");
    scanf("%s", sorguad);
    printf("                                         Kullanici Sifreniz: ");
    scanf("%s", sorgusifre);

    
    if(strcmp(sorguad, adminAd)==0 && strcmp(sorgusifre, adminSifre)== 0){          // admin menüsü girisi icin
    	printf("                                         Hosgeldin Admin");
    	sleep(2);
    	system("cls");
    	adminMenu(kullanicilar, menuilan);                              // admin menüsü 
	}
	else{
		for (i = 0; i < kullanicilar->kullanicisayi; i++) {         // normal kullanicilar için
        if (strcmp(sorguad, kullanicilar->kullaniciadi[i]) == 0) {
            if (strcmp(sorgusifre, kullanicilar->kullanicisifre[i]) == 0) {
                printf("                                            Giris basarili!\n");
                printf("                                              Hosgeldin %s",sorguad);
                sleep(3);
                system("cls");
                normalMenu(menuilan);                               // normal menüye bu kisimda atiliyor
                return;
            } else {
                printf("                                         Sifre yanlis ; sifrenizi unuttuysaniz yetkililerle iletisime gecebilirsiniz.\n");
                sleep(3);
                system("cls");
                return;
            }
        }
    }
    printf("                                         Kullanici Bulunamadi!!!\n");              // bu satiri sakin else disina cikarmayin yoksa admin giris yaptiginda kullanici bulunamadi diyor
	}

    
    
    sleep(3);
    system("cls");
}

int main() {
    struct kullanicibilgi kullanicilar; // kullanici bilgilerinin çekildigi kisim
    struct ilanekle menuilan;          // ilan bilgilerinin çekildigi kesim
    kullanicilar.kullanicisayi = 0;   // kullanici sayisinin tutuldugu kisim !!!!  buradaki sayiyi hiç bir sekilde ellemeyiniz  !!!!

    int secim;
    printf(" .. .  . Abdulaziz  . .. .  . .  . .. .  .@@ .  . .. .  . .. . .. .  . .. .  . .   ... .  . .  . .. .  . . \n");
	printf(" .. .  . .. .  . .  . .. .  . .  . .. .  @@@@ .  . .. .  . .. . .. .  . .. .  . .  ... .  . .  . .. .  . . \n");
	printf(" .. .  . .. .  . .  . .. .  . .  . .. .@@@@@@@@ . .. .  . .. . .. ..    . .. .   .  .  .... .  . .  . ..   \n");
	printf(" .. .  . .. .  . .  . .. .  . .  . .@@@@@@@@@@@@@ . . . .. . .. . => ISTANBUL GELISIM UNIVERSITESI .  . . .\n");
	printf(" .. .  . .. .  . .  . .. .  . .  .@@@@@@@ . @@@@@@@ .  . .. . . ... . .. .  . .. .   .  .  .... .  . .  . .\n"); 
	printf(" .. .  . Bedirhan.  . .. .  . . @@@@@@  . . . @@@@@@@  . .. . .. .  . .. .   .  .  .... .  . .  . .. .  . .\n");
	printf(" .. .  . .. .  . .  . .. .  .@@@@@@@. .  . . .   @@@@@@@ .. . .. .  . .. .    .                            \n");
	printf(" .. .  . .. .  . .  . .. . @@@@@@ .. .  . .  . ..  @@@@@@@. . .. .  . .. . . .  => BILGISAYAR PROGRAMCILIGI\n");
	printf(" .. .  . .. .  . .  . ..@@@@@@@  . .. .  . .  . .. . @@@@@@@ .. .  . .. .   .                              \n");
	printf(" .. .Asli.. .  . .  . @@@@@@@ .  . .. .  . .  . .. .  .@@@@@@@. .  . .. .  . . .. . .  . .  . . .. .  . . .\n");
	printf("  . . .. .  . .. .  @@@@@@ . . .. .  . .. .  . .  . .. .  @@@@@@@   . .. .  . . .. . .  . .  . . .. .  . . \n");
	printf(" .. . .. .  . .  .@@@@@@@. .. . .. .  . .. .  . .  . .. .  . @@@@@@@ .  . ..  . .. ... . . .  . .. . . .. .\n");
	printf(" .. . .. .  . .@@@@@@@@@ . .. . .. .  . .. .  . .  . .. .  . .@@@@@@@@  . ..  .. . ..  . .  . .. .  . ... .\n");
	printf(" .. . .. . @@@@@@@@@@@@ . .. . .. .  . .. .  . .  . .. .  . .  @@@@@@@@@@@@ .. .  .  ..  . .  . .. . . .. .\n");
	printf(" .. . .. .  . .  . @@@@@ . .. . .. .  . .. .  . .  . .. .  .  @@@@@. .  . .  .. .  ..  . .  . .. .  . .. ..\n");
	printf(" .. . .. .  . .  . @@@@@ . .. . ..@@@@@@@@@@@@@@@@@ .. .  . . @@@@@. .  .                                  \n");
	printf(" .. . .. .  . .  . @@@@@ . .. . ..@@ . .. .  . . @@ .. .  . . @@@@@. .  .  => PROGRAMLAMA TEMELLERI . . . .\n");
	printf(" .. . .. .  . .  . @@@@@ . .. . ..@@ . .. .  . . @@ .. .  . . @@@@@. .  .                                  \n");
	printf(" .. . Efekan. .  . @@@@@ . .. . ..@@ . .. .  . . @@ .. .  . . @@@@@. .  . ..  . .. ..  . .  . .. . . .. . .\n");
	printf(" .. . .. .  . .  . @@@@@. .. . .. @@ . .. .  . . @@ .. .  . . @@@@@. .  . .  . .. .                        \n");
	printf(" .. . .. .  . .  . @@@@@. .. . .. @@ . .. .  . . @@ .. .  . . @@@@@. . . . . .. . .  => EMLAKCI OTOMASYONU \n");
	printf(" .. .  . .. .  . . @@@@@ .  . .  .@@. .  . .  . .@@.  . .. .  @@@@@ . .. .  . ..  .                        \n");
	printf(" .. .  . .. .  . . @@@@@ .  . .  .@@@@@@@@@@@@@@@@@.  . .. .  @@@@@ . .. .  . .. . ..  . .  . .. .  . .. ..\n");
	printf(" .. .  . .. .  . . @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.. . . . .. ... ..  . .  . .. .  . .. ..\n\n\n");
	
	printf(" ******************** HOSGELDINIZ 2 SANIYE ICERISINDE OTOMASYONA YONLENDIRILICEKSINIZ *********************");
	sleep(2); 
	system("cls");

    do {
        kayitMenu();
        printf("                                         [Isleminizi giriniz: ");
        scanf("%d", &secim);
        system("cls");

        switch (secim) {
		    case 1:// giris
		        giris(&kullanicilar, &menuilan);
		        break;
		    case 2:// kayit
		        kayit(&kullanicilar);
		        break;
		    case 3:// cikis
		        printf("                                         Cikis yapiliyor...\n");
		        sleep(2);
		        break;
		    default:
		        printf("                                         Gecersiz secim! Lutfen tekrar deneyin.\n");
		        sleep(3);
		        system("cls");
		        break;
		}

    } while (secim != 3);

    return 0;
}

