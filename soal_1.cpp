#include <iostream>
#include <algorithm>

using namespace std;

float KonversiSuhu(float TC, char kode) {
    float hasil;
    if (kode == 'F' || kode == 'f')
        hasil = (9.0 / 5.0) * TC + 32;
    else if (kode == 'R' || kode == 'r')
        hasil = (4.0 / 5.0) * TC;
    else if (kode == 'K' || kode == 'k')
        hasil = TC + 273;
    else
        hasil = 0;

    return hasil;
}

int main()
{
    bool exit_program = false;
    int option;

    do {
        printf("Ingin lihat tugas soal apa?\n\n");
        printf("1. Luas persegi panjang\n");
        printf("2. Cek bentuk (persegi panjang atau bujur sangkar)\n");
        printf("3. Menentukan kuadran titik\n");
        printf("4. Konversi suhu (C ke F/R/K)\n");
        printf("5. Urutan tiga bilangan (besar ke kecil)\n\n");
        printf("Ketik pilihan anda dengan mengetik nomor di atas!\nNomor: ");

        cin >> option;

        switch(option)
        {
            case 1:
            {
                float lebar, panjang;
                printf("Masukkan nilai panjang: ");
                cin >> panjang;
                printf("Masukkan nilai lebar: ");
                cin >> lebar;

                float hasil = (panjang * lebar);
                
                printf("persegi empat pls nya adalah: %.2f", hasil);
                break;
            }
            case 2:
            {
                bool lanjut = false;
                float lebar, panjang;

                do {
                    printf("Masukkan nilai panjang (tidak boleh kurang dari 0): ");
                    cin >> panjang;
                    
                    if(panjang > 0.0) {
                        lanjut = true;
                    }

                } while(lanjut == false);

                lanjut = false;

                do {
                    printf("Masukkan nilai lebar (tidak boleh kurang dari 0): ");
                    cin >> lebar;

                    if(lebar > 0.0) {
                        lanjut = true;
                    }

                } while(lanjut == false);

                if(panjang == lebar) {
                    printf("nilai yang anda masukkan. Hasilnya \"Persegi panjang\"");
                }
                
                if(panjang != lebar) {
                    printf("nilai yang anda masukkan. Hasilnya \"Bujur Sangkar\"");
                }

                break;
            }

            case 3:
            {
                typedef struct {
                    int x;
                    int y;
                } point;

                point P;

                printf("Masukkan nilai x: ");
                scanf("%d", &P.x);

                printf("Masukkan nilai y: ");
                scanf("%d", &P.y);

                if (P.x == 0 || P.y == 0) {
                    printf("Kuadran tidak bisa dihitung\n");
                } else {
                    if (P.x > 0 && P.y > 0)
                        printf("Kuadran 1\n");
                    else if (P.x < 0 && P.y > 0)
                        printf("Kuadran 2\n");
                    else if (P.x < 0 && P.y < 0)
                        printf("Kuadran 3\n");
                    else
                        printf("Kuadran 4\n");
                }
                break;
            }
            case 4:
            {
                float TC, hasil;
                char kode;

                printf("Masukkan suhu dalam Celcius: ");
                scanf("%f", &TC);
                printf("Masukkan kode konversi (F/R/K): ");
                scanf(" %c", &kode); // pakai spasi sebelum %c agar input karakter terbaca benar

                hasil = KonversiSuhu(TC, kode);

                if (kode == 'F' || kode == 'f')
                    printf("Hasil konversi ke Fahrenheit = %.2f\n", hasil);
                else if (kode == 'R' || kode == 'r')
                    printf("Hasil konversi ke Reamur = %.2f\n", hasil);
                else if (kode == 'K' || kode == 'k')
                    printf("Hasil konversi ke Kelvin = %.2f\n", hasil);
                else  
                    printf("Kode konversi tidak dikenal.\n");
                break;
            }
            case 5:
            {
                int a, b, c;

                cout << "Masukkan nilai a: ";
                cin >> a;
                cout << "Masukkan nilai b: ";
                cin >> b;
                cout << "Masukkan nilai c: ";
                cin >> c;

                int arr[3] = {a, b, c};
                int n = sizeof(arr) / sizeof(arr[0]);

                sort(arr, arr + 3, greater<int>());

                cout << endl << "Hasil urutan: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;
            }
            case 6: 
            {
                exit_program = true;
                break;
            }
            default:
            {
                printf("Masukkan pilihan dari 1 sampai 4 saja!\n\n");
                break;
            }
        }
    } while (!exit_program);

    return 1;
}