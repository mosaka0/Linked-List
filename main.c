//Sefa Mert GÜNGÖR 180201086
//Miraç Onur SAKA 180201081
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sehir{
    int plaka;
    char sehir_adi[20];
    char bolge[20];
    int komsu_sayisi;
    struct sehir *next;
    struct komsu *komsusu;
};
struct komsu{
    int plaka;
    struct komsu *next;
};

struct sehir *ilk=NULL,*son=NULL;
struct komsu *ilk2=NULL,*son2=NULL;
void sehir_ekle(char a[],int komsu){
    struct sehir *yeni = (struct sehir*) malloc(sizeof(struct sehir));
    int sayac=0;
    char *tok = strtok(a," ,-.");
    while(tok!=NULL){
        if(sayac==0){
        yeni->plaka=atoi(tok);
        //printf("PLAKA : %d\n",yeni->plaka);
        sayac++;
        continue;
        }
        tok = strtok(NULL," ,-.");
        if(sayac==1){
            strcpy(yeni->sehir_adi,tok);
           // printf("SEHIR ADI : %s\n",yeni->sehir_adi);
            sayac++;
            continue;
        }
        else if(sayac==2){
            strcpy(yeni->bolge,tok);
            //printf("BOLGE : %s\n",yeni->bolge);
            sayac++;
            continue;
        }
    }
    yeni->komsu_sayisi=komsu-2;
    //printf("KOMSU SAYISI : %d\n",yeni->komsu_sayisi);
    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->next=NULL;
    }
    else
    {
        son->next=yeni;
        son=yeni;
        son->next=NULL;
    }
}
void Listele()
{
struct sehir *liste;
liste=ilk;
while(liste!=NULL)
{
printf("%d ",liste->plaka);
liste=liste->next;
}
liste=ilk;
printf("\n");
while(liste!=NULL)
{
printf("%s\n",liste->sehir_adi);
liste=liste->next;
}
liste=ilk;
printf("\n");
while(liste!=NULL)
{
printf("%s\n",liste->bolge);
liste=liste->next;
}
/*while(liste!=NULL)
{
printf("%d\n",liste->komsusu->plaka);
liste=liste->next;
}*/
}
int ss=0;
void Listele2()
{
struct sehir *liste2;
liste2=ilk;
while(liste2!=NULL)
{
printf("%d",liste2->komsusu->plaka);
printf("\n");
liste2=liste2->next;
}
}

struct sehir *start;
///KOMSU EKLEME OLAYLARI
void add(struct komsu **al, int gelen){

    struct komsu *yeni = (struct komsu*) malloc(sizeof(struct komsu));
    struct komsu *sonuncu = *al;
    yeni->plaka = gelen;
    yeni->next = NULL;
    if (*al == NULL)
    {
    *al = yeni;
    return;
    }
    while (sonuncu->next != NULL)
    sonuncu = sonuncu->next;
    sonuncu->next = yeni;
    return;
}

void komsuluk_olustur(){
    FILE *dosya2 = fopen("sehirler.txt","r");
    start=ilk;
    int i,j,virgul;
    char bal[200];
    char komsu_sehirler[50][50];
    int size=0;
    while(!feof(dosya2)){
        int kom=0;
        i=0;
        virgul=0;
        size=0;
        j=0;
        int k=0;
        char city[50];
        fgets(bal,100,dosya2);
    if(bal[strlen(bal)-1]=='\n'){
        bal[strlen(bal)-1]='\0';
    }
    else{
        bal[strlen(bal)]='\0';
    }
        while(bal[i]!='\n' && bal[i]!='\0'){
                    if(bal[i]==',' && virgul<1) {
                            i++;
                            j=0;
                        while(bal[i]!=',' && bal[i]!='\0'){
                            city[j]=bal[i];
                            i++;
                            j++;
                        }
                        city[j]='\0';
                        virgul++;
                        i--;
                    }
            else if(virgul==1) virgul++;
            else if(bal[i]==',' && virgul>=2){
                    i++;
                    j=0;
                while(bal[i]!=',' && bal[i]!='\0'){
                    komsu_sehirler[size][j]=bal[i];
                    i++;
                    j++;
                }
                komsu_sehirler[size][j]='\0';
                size++;
                virgul++;
                i--;
            }
            i++;
        }



        int degistir[size];

        for(k=0;k<size;k++){
        while(start->next!=NULL)
        {
        if(strcmp(start->sehir_adi,komsu_sehirler[k])==0)
        {
            degistir[kom]=start->plaka;
            kom++;
            break;
        }
        start=start->next;
        }
        start=ilk;
    }

        for(i=0;i<kom;i++){
            for(j=0;j<kom-1;j++){
                if(degistir[j]>degistir[j+1]){
                    int t=degistir[j];
                    degistir[j]=degistir[j+1];
                    degistir[j+1]=t;
                }
            }

        }
        while(start!=NULL){
            if(strcmp(start->sehir_adi,city)==0)
            {
                struct komsu *temp=NULL;
                for(i=0;i<kom;i++){
                add(&temp,degistir[i]);
                }
                start->komsusu=temp;
            break;
            }
            if(start==NULL) break;
            start=start->next;
        }
            start=ilk;
    }

}


void yeni_sehir_ekle(char eklenen[],char bolge[],int p,int komsu_say){
    struct sehir *bul=ilk;
    int m=0,j,i;
    while(bul!=NULL){
        if(strcmp(bul->sehir_adi,eklenen)==0){
            printf("AYNI ISIMLE BIR SEHIR VARDIR BUNU EKLEYEMESSIN");
            return;
        }
        bul=bul->next;
    }
    struct sehir *yeni = (struct sehir*) malloc(sizeof(struct sehir));
    strcpy(yeni->sehir_adi,eklenen);
    strcpy(yeni->bolge,bolge);
    yeni->plaka=p;
    yeni->komsu_sayisi=komsu_say;
    son->next=yeni;
    son=yeni;
    son->next=NULL;
}

void Listele3(){
struct sehir *liste2;
struct komsu *listele3=NULL;
liste2=ilk;
while(liste2!=NULL)
{
listele3=liste2->komsusu;
while(listele3!=NULL){
    printf("%d ",listele3->plaka);
    listele3=listele3->next;
}
printf("\n");
liste2=liste2->next;
}
}

void yeni_komsu_ekle(char eklenen[],char istenen[]){
    struct sehir *bul=ilk;
    struct komsu *kyeri=NULL;
    struct komsu *skyeri=NULL;
    struct komsu *ykomsu = (struct komsu*) malloc(sizeof(struct komsu));
    int tmp,a=0,i,j,m=0;
    int tut[20];
    while(bul!=NULL){
        if(strcmp(bul->sehir_adi,eklenen)==0){
            tmp=bul->plaka;
            break;
        }
        bul=bul->next;
    }
    bul=ilk;
    while(bul!=NULL){
        if(strcmp(bul->sehir_adi,istenen)==0){
            a=1;
            break;
        }
        bul=bul->next;
    }
    if(a==0){
        printf("BOYLE BIR SEHIR YOK KOMSU EKLENEMEZ\n");
        return;
    }
    kyeri=bul->komsusu;
    while(kyeri!=NULL){
        if(kyeri->plaka==tmp){
        printf("BU SEHIR ZATEN KOMSULUKTADIR EKLEYEMESSINIZ\n");
        return;
        }
        kyeri=kyeri->next;
    }
    bul->komsu_sayisi++;

    kyeri=bul->komsusu;
    int dizitmp[bul->komsu_sayisi];
    skyeri=kyeri;
    ykomsu->plaka=tmp;
    if(kyeri==NULL)
    {
     skyeri=kyeri;
     skyeri=ykomsu;
     skyeri->next=NULL;

    }
    else{
    while(kyeri->next!=NULL){
        skyeri=skyeri->next;
        kyeri=kyeri->next;
    }
    }
    kyeri=bul->komsusu;
    if(kyeri==NULL)
    {
     skyeri=kyeri;
     skyeri=ykomsu;
     skyeri->next=NULL;
    }
    else
    {
    skyeri->next=ykomsu;
    skyeri=ykomsu;
    skyeri->next=NULL;
    }
    kyeri=bul->komsusu;
    while(kyeri!=NULL){
        tut[m]=kyeri->plaka;
        m++;
        kyeri=kyeri->next;
    }
    for(i=0;i<m;i++){
            for(j=0;j<m-1;j++){
                if(tut[j]>tut[j+1]){
                    int t=tut[j];
                    tut[j]=tut[j+1];
                    tut[j+1]=t;
                }
            }
}
    kyeri=bul->komsusu;
    for(i=0;i<m;i++){
        kyeri->plaka=tut[i];
        kyeri=kyeri->next;
    }
}

void menu(){
    int secim;
    int t;
    char sehir_tut[20];
    char bolge_tut[5];
    int plaka_tut;
    int komsu_say_tut;
    char komsu_tut[20];
    don:
    printf("\n------------------------HOS GELDINIZ------------------------");
    printf("\n1-Yeni bir sehir-komsuluk ekle");
    printf("\n2-Sehir bilgisi");
    printf("\n3-Bir sehir-komsuluk dugumu cikar");
    printf("\n4-Bolgeye gore sehir bilgileri goruntule");
    printf("\n5-Komsu sayisina gore sehir goruntule");
    printf("\n6-Belli bir sayi araliginda komsu sayisina sahip sehirlerden belirli ortak komsulara sahip olan sehirlerin listele");
    printf("\nCikis yapmak icin 0'a basiniz");
    printf("\nIslem seciniz:");
    scanf("%d",&secim);
    switch(secim){
    case 0:
        return;
        break;
        case 1:
        printf("Sehir eklemek icin 1'e komsu eklemek icin 2'ye basin:");
        scanf("%d",&t);
        if(t==1){
            printf("Plakasini girin:");
            scanf("%d",&plaka_tut);
            printf("Sehir adini girin:");
            scanf("%s",sehir_tut);
            printf("Bolgeyi girin:");
            scanf("%s",bolge_tut);
            printf("Komsu sayisini girin:");
            scanf("%d",&komsu_say_tut);
            yeni_sehir_ekle(sehir_tut,bolge_tut,plaka_tut,komsu_say_tut);
        }
        else if(t==2){
            printf("Hangi sehire komsu eklemek istiyosunuz:");
            scanf("%s",sehir_tut);
            printf("Komsu eklenen sehrin adi:");
            scanf("%s",komsu_tut);
            yeni_komsu_ekle(komsu_tut,sehir_tut);
            Listele3();
        }
        goto don;
        break;
        case 2:
            printf("Sehir ismine gore aratmak icin 1'e basin Plakaya gore aratmak icin 2'ye basin:");
            scanf("%d",&t);
            if(t==1){
                printf("Sehrin ismini girin:");
                scanf("%s",sehir_tut);
                sehir_aratma(sehir_tut);
            }
            else if(t==2){
                printf("Plaka numarasini girin:");
                scanf("%d",&plaka_tut);
                sehir_aratma_plaka(plaka_tut);
            }

            goto don;
            break;
        case 3:
            printf("Sehir silmek icin 1'e basin Komsuluk silmek icin 2'ye basin:");
            scanf("%d",&t);
            if(t==1){
                printf("Sehrin adini girin:");
                scanf("%s",sehir_tut);
                sehir_sil(sehir_tut);
                Listele();
            }
            else if(t==2){
                printf("Hangi sehrin komsusu silinecekse girin:");
                scanf("%s",sehir_tut);
                printf("Komsuluk adini girin:");
                scanf("%s",komsu_tut);
                komsu_sil(sehir_tut,komsu_tut);
                Listele3();
            }
            goto don;
            break;
        case 4:
            printf("Hangi bolgedeki sehir listesini istiyosaniz girin:");
            scanf("%s",bolge_tut);
            bolgeye_gore_listele(bolge_tut);
            goto don;
            break;
        case 5:
            printf("Kac komsu sayisi ustune sahip sehirlerin gosterilmesini istersiniz:");
            scanf("%d",&komsu_say_tut);
            komsu_sayisina_gore_listele(komsu_say_tut);
            goto don;
            break;
        case 6:
            printf("Komsu oldugu birinci sehir:");
            scanf("%s",komsu_tut);
            printf("Komsu oldugu ikinci sehir:");
            scanf("%s",sehir_tut);
            printf("Komsu sayisi kac ustu olsun:");
            scanf("%d",&komsu_say_tut);
            printf("Komsu sayisi kac alti olsun:");
            scanf("%d",&plaka_tut);
            komsu_sayisi_komsuluk_ara(komsu_tut,sehir_tut,komsu_say_tut,plaka_tut);
            goto don;
            break;
        default:
            goto don;
    }
}

void sehir_aratma(char sadi[20]){
    struct sehir *stut=ilk;
    struct sehir *stut2=ilk;
    struct komsu *ktut=NULL;
    int a=0,b=0;
    char sehir_tut[20];
    char bolge_tut[5];
    int plaka_tut;
    int komsu_say_tut;
    while(stut!=NULL){
        if(strcmp(stut->sehir_adi,sadi)==0){
            a=1;
            break;
        }
        stut=stut->next;
    }
    if(a==0){
        printf("Sehir yok eklemek istiyorsaniz 1'e istemiyorsaniz 2'ye basin:");
        scanf("%d",&b);
        if(b==1){
        printf("Plakasini girin:");
            scanf("%d",&plaka_tut);
            printf("Sehir adini girin:");
            scanf("%s",sehir_tut);
            printf("Bolgeyi girin:");
            scanf("%s",bolge_tut);
            printf("Komsu sayisini girin:");
            scanf("%d",&komsu_say_tut);
            yeni_sehir_ekle(sehir_tut,bolge_tut,plaka_tut,komsu_say_tut);
            return;
        }
        else if(b==2)
            return;
    }
    ktut=stut->komsusu;
    printf("Plaka = %d\nSehir adi = %s\nBolge = %s\nKomsu sayisi = %d",stut->plaka,stut->sehir_adi,stut->bolge,stut->komsu_sayisi);
    printf("\n\n");
    while(stut2!=NULL){
        ktut=stut->komsusu;
        while(ktut!=NULL){
            if(stut2->plaka==ktut->plaka)
                printf("Plaka = %d\nSehir adi = %s\nBolge = %s\nKomsu sayisi = %d\n",stut2->plaka,stut2->sehir_adi,stut2->bolge,stut2->komsu_sayisi);
            ktut=ktut->next;
        }
        stut2=stut2->next;
    }
}
void sehir_aratma_plaka(int splaka){
    struct sehir *stut=ilk;
    struct sehir *stut2=ilk;
    struct komsu *ktut=NULL;
    int a=0,b=0;
    char sehir_tut[20];
    char bolge_tut[5];
    int plaka_tut;
    int komsu_say_tut;
    while(stut!=NULL){
        if(stut->plaka==splaka){
            int a=1;
            break;
        }
        stut=stut->next;
    }
    if(a==0){
        printf("Sehir yok eklemek istiyorsaniz 1'e istemiyorsaniz 2'ye basin:");
        scanf("%d",&b);
        if(b==1){
        printf("Plakasini girin:");
            scanf("%d",&plaka_tut);
            printf("Sehir adini girin:");
            scanf("%s",sehir_tut);
            printf("Bolgeyi girin:");
            scanf("%s",bolge_tut);
            printf("Komsu sayisini girin:");
            scanf("%d",&komsu_say_tut);
            yeni_sehir_ekle(sehir_tut,bolge_tut,plaka_tut,komsu_say_tut);
            return;
        }
        else if(b==2)
            return;
    }
    ktut=stut->komsusu;
    printf("Plaka = %d\nSehir adi = %s\nBolge = %s\nKomsu sayisi = %d",stut->plaka,stut->sehir_adi,stut->bolge,stut->komsu_sayisi);
    printf("\n\n");
    while(stut2!=NULL){
        ktut=stut->komsusu;
        while(ktut!=NULL){
            if(stut2->plaka==ktut->plaka)
                printf("Plaka = %d\nSehir adi = %s\nBolge = %s\nKomsu sayisi = %d\n",stut2->plaka,stut2->sehir_adi,stut2->bolge,stut2->komsu_sayisi);
            ktut=ktut->next;
        }
        stut2=stut2->next;
    }
}

void sehir_sil(char sadi[])
{
struct sehir *sil=ilk,*once=NULL;
while(sil!=NULL)
{
if(strcmp(sil->sehir_adi,sadi)==0) break;
else
{
once=sil;
sil=sil->next;
}
}
if(sil!=NULL)
{
if(sil==ilk)
{
ilk=ilk->next;
}
else if(sil==son)
{
son=once;
son->next=NULL;
}
else
{
once->next=sil->next;
}

free(sil);
}

}

void komsu_sil(char sadi[],char kadi[])
{
    int tmp,a=0,b=0;
    struct sehir *sil=ilk,*kontrol=ilk;
    struct komsu *kyeri=NULL,*once=NULL,*kyeri2=NULL,*kyeri3=NULL;
    while(kontrol!=NULL){
        if(strcmp(kontrol->sehir_adi,sadi)==0){
                a=1;
            break;
        }
        kontrol=kontrol->next;
    }
    kontrol=ilk;
    while(kontrol!=NULL){
        if(strcmp(kontrol->sehir_adi,kadi)==0){
                b=1;
            break;
        }
        kontrol=kontrol->next;
    }
    if(a==0){
        printf("BELIRTTIGINIZ SEHIR BULUNMAMAKTADIR");
        return;
    }
    if(b==0){
        printf("BELIRTTIGINIZ KOMSULUK BULUNMAMAKTADIR");
        return;
    }
    while(sil!=NULL){
        if(strcmp(sil->sehir_adi,kadi)==0){
            tmp=sil->plaka;
            break;
        }
        sil=sil->next;
    }
    sil=ilk;
    while(sil!=NULL){
        if(strcmp(sil->sehir_adi,sadi)==0){
            break;
        }
        sil=sil->next;
    }
    kyeri=sil->komsusu;
    kyeri2=sil->komsusu;
    while(kyeri->next!=NULL){
            kyeri=kyeri->next;
            if(kyeri->next==NULL){
                kyeri3=kyeri;
            }
    }
    kyeri=sil->komsusu;
while(kyeri!=NULL)
{
if(kyeri->plaka==tmp) break;
else
{
once=kyeri;
kyeri=kyeri->next;
}
}
if(kyeri!=NULL)
{
if(kyeri==kyeri2)
{
kyeri2=kyeri2->next;
}
else if(kyeri==kyeri3)
{
kyeri3=once;
kyeri3->next=NULL;
}
else
{
once->next=kyeri->next;
}

free(kyeri);
}
sil->komsu_sayisi--;
}

void bolgeye_gore_listele(char blg[]){
    struct sehir *bliste=ilk;
    printf("%s BOLGESINDE BULUNAN SEHIRLER\n\n",blg);
    while(bliste!=NULL){
        if(strcmp(bliste->bolge,blg)==0){
            printf("Plaka = %d\nSehir adi = %s\nKomsu Sayisi = %d\n\n",bliste->plaka,bliste->sehir_adi,bliste->komsu_sayisi);
        }
        bliste=bliste->next;
    }
}

void komsu_sayisina_gore_listele(int ks){
    struct sehir *kliste=ilk;
    printf("KOMSU SAYISI %d'DEN FAZLA OLAN ILLER\n",ks);
    while(kliste!=NULL){
        if(kliste->komsu_sayisi>ks){
            printf("Plaka = %d\nSehir adi = %s\nKomsu Sayisi = %d\n\n",kliste->plaka,kliste->sehir_adi,kliste->komsu_sayisi);
        }
        kliste=kliste->next;
    }
}

void komsu_sayisi_komsuluk_ara(char shr[],char shr2[],int sayi,int sayi2){
    struct sehir *sara=ilk,*kara=ilk,*kara2=ilk;
    struct komsu *kom=NULL,*kom2=NULL;
    int tut[10],tut2[10];
    int i=0,j=0,a=0,b=0,c=0;
    int tmp[10];
    while(kara!=NULL){
        if(strcmp(kara->sehir_adi,shr)==0)
            break;
        kara=kara->next;
    }
    while(kara2!=NULL){
        if(strcmp(kara2->sehir_adi,shr2)==0)
            break;
        kara2=kara2->next;
    }
    kom=kara->komsusu;
    kom2=kara2->komsusu;
    while(kom!=NULL){
        tut[a]=kom->plaka;
        kom=kom->next;
        i++;
        a++;
    }
    a=0;
    while(kom2!=NULL){
        tut2[a]=kom2->plaka;
        kom2=kom2->next;
        j++;
        a++;
    }
    for(a=0;a<i;a++){
        for(b=0;b<j;b++){
            if(tut[a]==tut2[b]){
                tmp[c]=tut[a];
                c++;
            }
        }
    }
    while(sara!=NULL){
        for(a=0;a<c;a++){
            if(sara->plaka==tmp[a] && sara->komsu_sayisi>sayi && sara->komsu_sayisi<sayi2){
                printf("%s ",sara->sehir_adi);
            }
        }
        sara=sara->next;
    }

}

void yazdir(){
    struct sehir *syaz=ilk;
    struct komsu *kyaz=NULL;
    FILE *dosya3 = fopen("cikti.txt","w");
    while(syaz!=NULL){
        fprintf(dosya3,"Plaka kodu: %d\nSehir adi: %s  ",syaz->plaka,syaz->sehir_adi);
        kyaz=syaz->komsusu;
        while(kyaz!=NULL){
            fprintf(dosya3,"›");
            fprintf(dosya3,"%d",kyaz->plaka);
            kyaz=kyaz->next;
        }
    fprintf(dosya3,"\n");
    fprintf(dosya3,"Bolge: %s\n",syaz->bolge);
    fprintf(dosya3,"\n");
    syaz=syaz->next;
    }
}


///MAIN FONKSYYONU
int main(){
    int i,virgul=0,asil;
    char a[200];
    //char c[200];
    FILE *dosya = fopen("sehirler.txt","r");
    for(asil=0;asil<81;asil++){
    fgets(a,100,dosya);
    printf
    sehir_ekle(a,virgul);
    virgul=0;
    }
    fclose(dosya);
    komsuluk_olustur();

    menu();
    yazdir();

    return 0;
}
