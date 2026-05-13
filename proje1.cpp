#include <iostream>
#include <stdio.h>

using namespace std;
int main(){
    cout << "Ogrenci Not Analiz Sistemi" << endl;

    int ogrenciSayisi;
    float notlar[100];
    float toplam = 0;
    float ortalama;
    cout << "Ogrenci sayisini giriniz;"
    cin >> ogrencisayisi;

    for (int i=0; i<ogrenciSayisi; i++){
        cout << "Ogrenci " << i+1 << " notunu giriniz: ";
        cin >> notlar[i];
        toplam += notlar[i];
    }
    ortalama = toplam / ogrenciSayisi;
    cout << "Sınıf ortalaması: " << ortalama << endl;

    for (int i=0; i<ogrenciSayisi; i++){
        if (notlar[i] < 50){
            cout << "Ogrenci " << i+1 << " KALDI!" << endl;
        }
        else{
            cout << "Ogrenci " << i+1 << " GECTI!" << endl;
        }
    }

    cout << "Bellek Adresleri:" << endl;
    cout << "Ogrenci Sayisi: " << &ogrenciSayisi << endl;
    cout << "Notlar Dizisi: " << &notlar[0] << endl;
    cout << "Ortalama: " << &ortalama << endl;

    int negatifDeger = -100;
    unsigned int pozitifDeger = 100;
    cout << "Isaretli int: " << negatifDeger << endl;
    cout << "Isaretsiz int: " << pozitifDeger << endl;
    return 0;
}