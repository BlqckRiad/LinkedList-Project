#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "..\include\Basamak.hpp"
#include "..\include\Sayi.hpp"
#include "..\include\SayiListesi.hpp"
using namespace std;

int main()
{
    
    
    ifstream dosya("veriler.txt");
    vector<int> dizim; // Dinamik dizi
    int sayi;
    while (dosya >> sayi) {
        dizim.push_back(sayi);
    }
    dosya.close(); // Dosyayı kapat

    SayiListesi sayiListesi;
    
    for(int i=0;i<dizim.size();i++)
    {
        sayiListesi.ekleSayi(dizim[i]);

    }
    for(int i=0;i<dizim.size();i++)
    {
         int arananSayi = dizim[i];
     Basamak * arananSayiNesnesi = sayiListesi.getBasamaklar(arananSayi);
     sayiListesi.SayiMenusu(arananSayiNesnesi,dizim[i]);
        
    }

    
    cout<<endl;
    cout << endl<<endl;
    int secim=0;
    while(secim!=4)
    {
        if (secim==1)
        {
            // Tekleri Başa Almak
            sayiListesi.tekleriBasaAl();
             cout << "Tekler basa alinmis hali:" << endl;
            sayiListesi.Yazdir(); // Yeniden düzenlenmiş basamakları yazdır
        }
        else if(secim==2)
        {  
            // Basamakları Terslemek
            sayiListesi.basamaklariTersCevir();
            cout << "Basamaklari ters cevrilmis hali:" << endl;
            sayiListesi.Yazdir(); // Yeniden düzenlenmiş basamakları yazdı

        }
        else if(secim==3)
        {
            sayiListesi.EnBuyukSil();
            sayiListesi.Yazdir();

        }
        else if(secim==4)
        {
            return 0;
        }
        else if(secim==0)
        {

        }
        else{
            cout<< "Seciminiz gecersizdir tekrar deneyiniz "<<endl;
            cin>>secim;
        }
        cout<<endl;
        cout<<"1. Tekleri Basa Al"<<endl;
        cout<<"2. Basamaklari Tersle"<<endl;
        cout<<"3. En Buyuk Cikar"<<endl;
        cout<<"4. Cikis"<<endl;
        cin>>secim;
    }

    

    return 0;
}