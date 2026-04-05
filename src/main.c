
#include <stdio.h>
#include "parkinglot.h"

int main() {
    ParkingLot lot;
    initParkingLot(&lot);

    int secim;
    char plaka[20];
    char isim[50];
    char tip[20];
    int saat;

    while (1) {
        printf("\n=== OTOPARK YÖNETİM SİSTEMİ ===\n");
        printf("1. Araç Park Et\n");
        printf("2. Araç Çıkar\n");
        printf("3. Müsaitlik Kontrol Et\n");
        printf("4. Araç Ara\n");
        printf("5. Giriş Saatine Göre Sırala\n");
        printf("6. Otoparkı Göster\n");
        printf("0. Çıkış\n");
        printf("Seçiminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Plaka: ");
                scanf("%s", plaka);
                printf("Sahip Adı: ");
                scanf("%s", isim);
                printf("Araç Tipi: ");
                scanf("%s", tip);
                printf("Giriş Saati (örn: 1430): ");
                scanf("%d", &saat);
                Vehicle v = createVehicle(plaka, isim, tip, saat);
                parkVehicle(&lot, v);
                break;

            case 2:
                printf("Çıkarılacak Araç Plakası: ");
                scanf("%s", plaka);
                removeVehicle(&lot, plaka);
                break;

            case 3:
                if (checkAvailability(&lot))
                    printf("Otopark müsait. Boş yer: %d\n", lot.capacity - lot.currentSize);
                else
                    printf("Otopark dolu!\n");
                break;

            case 4:
                printf("Aranacak Plaka: ");
                scanf("%s", plaka);
                int index = searchVehicle(&lot, plaka);
                if (index != -1) {
                    printf("Araç bulundu:\n");
                    printVehicle(lot.spaces[index]);
                } else {
                    printf("Araç bulunamadı.\n");
                }
                break;

            case 5:
                sortByEntryTime(&lot);
                break;

            case 6:
                printParkingLot(&lot);
                break;

            case 0:
                printf("Çıkış yapılıyor...\n");
                return 0;

            default:
                printf("Geçersiz seçim!\n");
        }
    }

    return 0;
}