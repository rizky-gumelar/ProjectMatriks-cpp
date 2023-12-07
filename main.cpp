#include <iostream>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1); cout << "=========================================\n";
        gotoxy(1,2); cout << "|>>>>>>> PROGRAM OPERASI MATRIKS <<<<<<<|\n";
        gotoxy(1,3); cout << "-----------------------------------------\n";
        gotoxy(1,4); cout << "|        1. Penjumlahan Matriks         |\n";
        gotoxy(1,5); cout << "|        2. Pengurangan Matriks         |\n";
        gotoxy(1,6); cout << "|        3. Perkalian Matriks           |\n";
        gotoxy(1,7); cout << "|        4. CEK FULL                    |\n";
        gotoxy(1,8); cout << "|        5. CEK KOSONG                  |\n";
        gotoxy(1,9);cout <<  "|        6. UKURAN STACK                |\n";
        gotoxy(1,10);cout << "|        7. SELESAI                     |\n";
        gotoxy(1,11);cout << "=========================================\n";
        //gotoxy(1,12);cout << datake;

        gotoxy(1,13);cout<<"Pilihan Anda [1-8] : ";
        cin>>pilih;

        if(pilih==1){ /*Menambah data baru diletakan di DATAKE*/
                if(isfull()){
                    gotoxy(46,14);cout << "Stack Penuh!!";
                    gotoxy(46,16);cout<<"Press Any Key...";
                    getch();
                }else{
                    tambahdata(datake);
                    datake++;
                }
            }
        if(pilih==2){ /*Menghapus Data Terakhir (DATAKE-1*/
                if(datake>0){
                    hapusdata(datake-1);
                    datake--;
                }else{
                    gotoxy(46,14);cout << "Data Kosong!!";
                    gotoxy(46,16);cout<<"Press Any Key...";
                    getch();
                }
            }
        if(pilih==3){
             /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);
        }
        if(pilih==4){
            if(isfull()){
                gotoxy(46,14);cout << "Stack Penuh!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }else{
                gotoxy(46,14);cout << "Stack Belum Penuh, Masih Bisa Push!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }
        }
        if(pilih==5){
            if(isempty()){
                gotoxy(46,14);cout << "Stack Kosong!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }else{
                gotoxy(46,14);cout << "Stack Tidak Kosong, Masih Bisa Pop!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }
        }
        if(pilih==6){
                gotoxy(46,14);cout << "Ukuran Stack Adalah : " << datake;
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
        }

    }
    while(pilih!=7);
    return 0;

    int m, n;

    cout << "Masukkan jumlah kolom : ";
    cin >> m;
    cout << "Masukkan jumlah baris : ";
    cin >> n;

    int a[m][n];

    cout << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << "Masukkan nilai kolom " << i+1 << ",baris " << j+1 << " : ";
            cin >> a[i][j];
        }
    }

    cout << "\nMatriks = \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
