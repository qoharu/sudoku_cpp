#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;
int angka[10][10],nilai(int x),x=1,y=1,m=5;
void TampilPapan(),AcakNomor(),Reset(),HapusAngka(int n),Mulai(),Ubah(int a);
void Atas(), Bawah(), Kiri(), Kanan(),tempat(),arah(),Berhasil();
bool CekAngka(),kunci[10][10]={false},posisi[10][10];
void setcolor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}
main(){
    int b,level;
    system("cls");
    cout<< "Sudoku Salman \nPilih Level\n1. Gampang\n2. Lumayan\n3. Susah\n";
    cin>>level;
    srand(time(NULL));
    Reset();
    cout<<"loading";
    while(!CekAngka()){
        cout<<".";
        AcakNomor();
    }
    HapusAngka(level);
    Mulai();
    arah();
    getch();
    return 0;
}

void TampilPapan(){
    cout<<"_____________\n";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<< "| ";
                if(x==j and y==i){
                    setcolor(2);
                    cout << angka[j][i];
                    setcolor(7);
                }else{
                    cout<< angka[j][i];
                }
                cout<< " ";
        }
        cout << "|\n-------------\n";
    }
}

void AcakNomor(){
    bool kosong;
    int counter;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            counter=0;
            do{
                kosong=true;
                angka[j][i]=rand()%m+1;
                for(int k=1;k<=m;k++){
                    if(k!=i){
                        if(angka[j][i]==angka[j][k])(kosong=false);
                    }
                    if(k!=j){
                        if(angka[j][i]==angka[k][i])(kosong=false);
                    }
                }
                counter++;
                if(counter>=m){
                    break;
                }
            }while(!kosong);
        }
    }
}

void Reset(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            angka[j][i] = 0;
        }
    }
}

bool CekAngka(){
    bool nol=true;
    int a,b;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(angka[j][i] == 0){
                nol=false;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(k!=i){
                    if(angka[j][i]==angka[j][k])(nol=false);
                }
                if(k!=j){
                    if(angka[j][i]==angka[k][i])(nol=false);
                }
            }
        }
    }

    return nol;
}

void HapusAngka(int n){
    int a=1,x,y;
    switch(n){
        case 1 : n=m*m/3;break;
        case 2 : n=m*m/2;break;
        case 3 : n=m*m*3/4;break;
    }
    while(a<=n){
        x=rand()%m+1;
        y=rand()%m+1;
        if(angka[x][y]!=0){
            angka[x][y]=0;
            a++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(angka[j][i]!=0){
                kunci[j][i]=true;
            }
        }
    }
}

int nilai(){
    int a=0;
    for(int i=1;i<=m;i++){
        a += i;
    }
    return a;
}

void Mulai()
{
    system("cls");
    TampilPapan();
    if(CekAngka()){
        Berhasil();
    }

}

void arah()
{
    char arah;
    while(arah=getch()){
    if(CekAngka()){continue;}
    switch(arah){
        case 'H' : Atas();Mulai();break;
        case 'P' : Bawah();Mulai();break;
        case 'M' : Kanan();Mulai();break;
        case 'K' : Kiri();Mulai();break;
        case '1' : Ubah(1);Mulai();break;
        case '2' : Ubah(2);Mulai();break;
        case '3' : Ubah(3);Mulai();break;
        case '4' : Ubah(4);Mulai();break;
        case '5' : Ubah(5);Mulai();break;
        case '6' : Ubah(6);Mulai();break;
        case '7' : Ubah(7);Mulai();break;
        case '8' : Ubah(8);Mulai();break;
        case '9' : Ubah(9);Mulai();break;

    }
  }
}

void Atas(){
    y -=1;
    if(y<1)(y=3);
}
void Bawah(){
    y +=1;
    if(y>m)(y=1);
}
void Kiri(){
    x -=1;
    if(x<1)(x=3);
}
void Kanan(){
    x +=1;
    if(x>m)(x=1);
}
void tempat(){
    for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                posisi[j][i]=false;
            }
        }
}
void Berhasil(){
    char pilihan;
    cout<<"Selamat anda berhasil!!! :D\nMain lagi? (y/n)";
    pilihan=getch();
    if(pilihan=='y'){
        main();
    }else if(pilihan=='n'){
        return;
    }

}
void Ubah(int a){
    if(!kunci[x][y]){
        angka[x][y]=a;
    }
}
