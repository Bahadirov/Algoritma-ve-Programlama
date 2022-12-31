#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// bu kod bir araba galerisindeki ara� bilgilerini tutan k�sa kod par�as�d�r
typedef struct kredi
{
    int oran;
    int vade;
}kredi;

typedef struct arac
{
    char marka[15];
    int yil;
    int km;
    int fiyat;
    kredi credi;
}arac;

int main()
{
    srand(time(NULL));
    printf("kac arac olacak: ");
    int i,sayi;
    scanf("%d",&sayi);
    //kullan�c� ka� ara� girdiyse ona g�re dinamik bellek ile RAMden yer ayr�lm��t�r
    arac *cars=(arac*)malloc(sayi*sizeof(arac));
    for(i=0;i<sayi;i++){
        printf("%d. arac markasi: ",i+1);
        scanf("%s",&cars[i].marka);

        printf("%d. arac yili: ",i+1);
        scanf("%d",&cars[i].yil);

        printf("%d. arac KM: ",i+1);
        scanf("%d",&cars[i].km);

        printf("%d. arac fiyati: ",i+1);
        scanf("%d",&cars[i].fiyat);


        printf("\n------------------------\n");
    }

    //kullan�c�dan girilen ara� bilgileri ekrana yazd�r�l�r
    for(i=0;i<sayi;i++){
        printf("%d. arac markasi: %s\n",i+1,cars[i].marka);
        printf("%d. arac yili: %d\n",i+1,cars[i].yil);
        printf("%d. arac km: %d\n",i+1,cars[i].km);
        printf("%d. arac fiyat: %d\n",i+1,cars[i].fiyat);

        printf("%d. arac orani: %d\n",i+1,cars[i].credi.oran=rand()%9+7); //7-15 arasinda rastgele sayi �retir
        printf("%d. arac vadesi: %d\n",i+1,cars[i].credi.vade=rand()%49+12);//12-60 ay arasinda

        printf("\n------------------------\n");
    }

    return 0;
}
