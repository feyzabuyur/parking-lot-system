
#include <stdio.h>
#include <string.h>
#include "parkinglot.h"

// Otoparkı başlatır
void initParkingLot(ParkingLot *lot) {
    lot->currentSize = 0;
    lot->capacity = MAX_CAPACITY;
}

// Araç park eder
// Başarılıysa 1, otopark doluysa 0 döner
int parkVehicle(ParkingLot *lot, Vehicle v) {
    if (lot->currentSize >= lot->capacity) {
        printf("Otopark dolu!\n");
        return 0;
    }
    lot->spaces[lot->currentSize] = v;
    lot->currentSize++;
    printf("%s plakalı araç park edildi.\n", v.licensePlate);
    return 1;
}

// Plakaya göre araç çıkarır
// Başarılıysa 1, araç bulunamazsa 0 döner
int removeVehicle(ParkingLot *lot, char licensePlate[]) {
    for (int i = 0; i < lot->currentSize; i++) {
        if (strcmp(lot->spaces[i].licensePlate, licensePlate) == 0) {
            for (int j = i; j < lot->currentSize - 1; j++) {
                lot->spaces[j] = lot->spaces[j + 1];
            }
            lot->currentSize--;
            printf("%s plakalı araç çıkarıldı.\n", licensePlate);
            return 1;
        }
    }
    printf("Araç bulunamadı: %s\n", licensePlate);
    return 0;
}

// Müsait yer kontrolü
// Yer varsa 1, doluysa 0 döner
int checkAvailability(ParkingLot *lot) {
    return lot->currentSize < lot->capacity;
}

// Plakaya göre araç arar
// Bulursa index numarasını, bulamazsa -1 döner
int searchVehicle(ParkingLot *lot, char licensePlate[]) {
    for (int i = 0; i < lot->currentSize; i++) {
        if (strcmp(lot->spaces[i].licensePlate, licensePlate) == 0) {
            return i;
        }
    }
    return -1;
}

// Giriş saatine göre küçükten büyüğe sıralar (bubble sort)
void sortByEntryTime(ParkingLot *lot) {
    for (int i = 0; i < lot->currentSize - 1; i++) {
        for (int j = 0; j < lot->currentSize - i - 1; j++) {
            if (compareEntryTime(lot->spaces[j], lot->spaces[j + 1]) > 0) {
                Vehicle temp = lot->spaces[j];
                lot->spaces[j] = lot->spaces[j + 1];
                lot->spaces[j + 1] = temp;
            }
        }
    }
    printf("Araçlar giriş saatine göre sıralandı.\n");
}

// Otoparkdaki tüm araçları ekrana yazdırır
void printParkingLot(ParkingLot *lot) {
    if (lot->currentSize == 0) {
        printf("Otopark boş.\n");
        return;
    }
    printf("=== OTOPARK DURUMU (%d/%d) ===\n", lot->currentSize, lot->capacity);
    for (int i = 0; i < lot->currentSize; i++) {
        printVehicle(lot->spaces[i]);
    }
}