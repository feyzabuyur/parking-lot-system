
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "vehicle.h"

#define MAX_CAPACITY 50  // Otoparkın maksimum kapasitesi

// Otopark veri tipi
typedef struct {
    Vehicle spaces[MAX_CAPACITY];  // Araçların tutulduğu dizi
    int currentSize;               // Şu an otoparkta kaç araç var
    int capacity;                  // Maksimum kapasite
} ParkingLot;

// Fonksiyon prototipleri
void initParkingLot(ParkingLot *lot);                    // Otoparkı başlat
int parkVehicle(ParkingLot *lot, Vehicle v);             // Araç park et
int removeVehicle(ParkingLot *lot, char licensePlate[]); // Araç çıkar
int checkAvailability(ParkingLot *lot);                  // Müsait yer var mı?
int searchVehicle(ParkingLot *lot, char licensePlate[]); // Araç ara
void sortByEntryTime(ParkingLot *lot);                   // Giriş saatine göre sırala
void printParkingLot(ParkingLot *lot);                   // Otoparkı ekrana yaz

#endif