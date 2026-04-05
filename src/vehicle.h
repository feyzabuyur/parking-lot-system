
#ifndef VEHICLE_H
#define VEHICLE_H

// Araç veri tipi
typedef struct {
    char licensePlate[20];  // Plaka numarası
    char ownerName[50];     // Araç sahibinin adı
    char vehicleType[20];   // Araç tipi (araba, motosiklet vb.)
    int entryTime;          // Giriş saati (örn: 1430 = 14:30)
} Vehicle;

// Fonksiyon prototipleri
Vehicle createVehicle(char licensePlate[], char ownerName[], char vehicleType[], int entryTime);
void printVehicle(Vehicle v);
int compareEntryTime(Vehicle v1, Vehicle v2);

#endif
