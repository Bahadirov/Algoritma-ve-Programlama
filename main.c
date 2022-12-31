#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ALGORİTMALAR VE PROGRAMLAMA DERSİ DÖNEM PROJESİ
// - Suhrab BAHADIROV
// - Amadou BAH

// cevap anahtari ureten fonksiyon
void cevap_anahtari_uret(char cevap_anahtari[], int S){
    int i;
    char dogru_cevap;
    srand(time(NULL));
    for(i=0;i<S;i++){
        dogru_cevap = 'A' + rand() % 5;
        cevap_anahtari[i] = dogru_cevap;
    }
    cevap_anahtari_yazdir(cevap_anahtari,S);
}

// cevap anahtarini ekrana yazdiran fonksiyon
void cevap_anahtari_yazdir(char cevap_anahtari[], int S){
    printf("\nCevap Anahtari:\n");
    for (int i = 0; i < S; i++)
    {
        printf("%.3d: %c | ", i + 1, cevap_anahtari[i]);
    }
    printf("\n\n");
}

// her bir ogrenci icin sinavi uygulayan fonksiyon
void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D){
    int i, j;
    srand(time(NULL));
    for (i = 0; i < N; i++){
        for (j = 0; j < S; j++){
            double r = (double) rand() / RAND_MAX;
            if (r <= B){
                ogrenci_cevaplari[i][j] = 'X'; // 'X' bos birakma ihtimali
            }
            else if (r <= B + D){
                ogrenci_cevaplari[i][j] = cevap_anahtari[j]; // dogru cevap ata
            }
            else {
                ogrenci_cevaplari[i][j] = 'A' + rand() % 5; // rastgele bir yanlis cevap uret
            }
        }
    }
}

// yukarida uygulanan sinavi her bir ogrenci icin ekrana yazdiran fonksiyon
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S){
    printf("%.3d. Ogrenci Cevaplari:\n", ogrenci_ID + 1);
    for (int i = 0; i < S; i++){
        printf("%.3d: %c | ", i + 1, ogrenci_cevaplari[ogrenci_ID][i]);
    }
    printf("\n");
}
//ogrenci_ID 0 ~ N-1 arasında değişen bir indis olarak verilmeli


//********* 1. bolum sonu *********

// her bir ogrenciyi puanlayan fonksiyon
void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int N, int S){
    double soru_basina_puan = 100/S;
    for (int i = 0; i < N; i++) {
        double ogr_puani = 0.0;
        for (int j = 0; j < S; j++) {
            if (ogrenci_cevaplari[i][j] == 'X')
                ;
            else if (ogrenci_cevaplari[i][j] == cevap_anahtari[j])
                ogr_puani += soru_basina_puan;
            else
                ogr_puani = ogr_puani - (soru_basina_puan*0.25);
        }
        HBN[i] = ogr_puani;
    }
}

// sinif ortalamasini bulup ekrana yazdiran fonksiyon
double sinif_ortalamasi_hesapla(double HBN[], int N){
    // Sınıf ortalamasını hesapla
    double topla = 0.0;
    for (int i = 0; i < N; i++)
        topla += HBN[i];

    double ort = topla / N;
    printf("Sinif ortalamasi: %.2lf,", ort);
    return ort;
}

// std hesaplayan fonksiyon
double standart_sapma_hesapla(double ortalama, double HBN[], int N){
    // Standart sapma değerini hesapla
    double std_top = 0.0;
    for (int i = 0; i < N; i++)
        std_top += pow(HBN[i] - ortalama,2);

    double std = sqrt(std_top / N);
    printf(" standart sapma: %.2lf",std);
    return std;
}

//fonksiyon, tüm öğrencilerin T skorlarını tek seferde hesaplayıp double T_skoru[] dizisine yazacak
void T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[]){
    // Her bir öğrencinin T skoru değerini hesapla
    for (int i = 0; i < N; i++) {
        T_skoru[i] = 60+10 * ((HBN[i] - ortalama) / std);
        // her bir ogrencinin HBN notunu T skorunu ve harf notunu ekrana yazdır
        printf("\n%.3d. ogrencinin HBN: %.2lf, T-skoru: %.2lf, harf notu: ", i+1, HBN[i], T_skoru[i]);
        if(T_skoru[i]<32.0)
            printf("FF");
        else if(T_skoru[i]<37.0)
            printf("FD");
        else if(T_skoru[i]<42.0)
            printf("DD");
        else if(T_skoru[i]<47.0)
            printf("DC");
        else if(T_skoru[i]<52.0)
            printf("CC");
        else if(T_skoru[i]<57.0)
            printf("CB");
        else if(T_skoru[i]<62.0)
            printf("BB");
        else if(T_skoru[i]<67.0)
            printf("BA");
        else
            printf("AA");
    }
}
// sinif duzeyini ortalamaya gore belirleyip duzeyini ekrana yazdirma fonksyonu
void sabp_Ort(double a){
    printf("Sinif duzeyi: ");
    if(a<=42.5)
        printf("Kotu");
    else if(a<=47.5)
        printf("Zayif");
    else if(a<=52.5)
        printf("Orta");
    else if(a<=57.5)
        printf("Ortanin Ustu");
    else if(a<=62.5)
        printf("iyi");
    else if(a<=70.0)
        printf("Cok İyi");
    else if(a<=80.0)
        printf("Mukemmel");
    else
        printf("Ustun Basari");
}

int main()
{
    int ogr,soru;
    printf("Ogrenci sayisini giriniz (max 100): ");
    scanf("%d",&ogr);
    printf("Soru sayisini giriniz (max 100): ");
    scanf("%d",&soru);

    double bos_ihtimal, dogru_ihtimal;
    printf("Bos birakma ihtimalini giriniz (0.0~1.0): ");
    scanf("%lf",&bos_ihtimal);
    printf("Dogru cevap verme ihtimalini giriniz (0.0~1.0): ");
    scanf("%lf",&dogru_ihtimal);

    char cevap_anahtari[soru];
    cevap_anahtari_uret(cevap_anahtari,soru);

    char ogrenci_cevaplari[ogr][100];
    sinavi_uygula(ogrenci_cevaplari,cevap_anahtari,ogr,soru,bos_ihtimal,dogru_ihtimal);

    for (int i = 0; i < ogr; i++){
        ogrenci_cevabini_yazdir(ogrenci_cevaplari, i, soru);
    }

    double T_skoru[ogr]; //T_skoru_hesapla(ort, hbn, ogr, std, T_skoru);

    double hbn[ogr];
    ogrencileri_puanla(ogrenci_cevaplari, cevap_anahtari, hbn, ogr, soru);
    double ort;
    printf("\n");
    ort=sinif_ortalamasi_hesapla(hbn, ogr);

    double std;
    std=standart_sapma_hesapla(ort, hbn, ogr);

    printf("\n");

    sabp_Ort(ort);

    printf("\n");

    T_skoru_hesapla(ort, hbn, ogr, std, T_skoru);
    printf("\n");
    return 0;
}
