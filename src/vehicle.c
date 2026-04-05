
#include <stdio.h>
#include <string.h>
#include "vehicle.h"

// Yeni araç oluşturur ve geri döndürür
Vehicle createVehicle(char licensePlate[], char ownerName[], char vehicleType[], int entryTime) {
    Vehicle v;
    strcpy(v.licensePlate, licensePlate);
    strcpy(v.ownerName, ownerName);
    strcpy(v.vehicleType, vehicleType);
    v.entryTime = entryTime;
    return v;
}

// Araç bilgilerini ekrana yazdırır
void printVehicle(Vehicle v) {
    printf("Plaka     : %s\n", v.licensePlate);
    printf("Sahip     : %s\n", v.ownerName);
    printf("Araç Tipi : %s\n", v.vehicleType);
    printf("Giriş     : %d\n", v.entryTime);
    printf("-------------------\n");
}

// İki aracın giriş saatini karşılaştırır
// v1 önce girdiyse -1, v2 önce girdiyse 1, aynıysa 0 döner
int compareEntryTime(Vehicle v1, Vehicle v2) {
    if (v1.entryTime < v2.entryTime) return -1;
    if (v1.entryTime > v2.entryTime) return 1;
    return 0;
}