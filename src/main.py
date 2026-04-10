from vehicle import Vehicle
from parkinglot import ParkingLot

def main():
    lot = ParkingLot()

    while True:
        print("\n=== OTOPARK YÖNETİM SİSTEMİ ===")
        print("1. Araç Park Et")
        print("2. Araç Çıkar")
        print("3. Müsaitlik Kontrol Et")
        print("4. Araç Ara")
        print("5. Giriş Saatine Göre Sırala")
        print("6. Otoparkı Göster")
        print("0. Çıkış")
        secim = input("Seçiminiz: ")

        if secim == "1":
            plaka = input("Plaka: ")
            isim = input("Sahip Adı: ")
            tip = input("Araç Tipi: ")
            saat = int(input("Giriş Saati (örn: 1430): "))
            v = Vehicle(plaka, isim, tip, saat)
            lot.park_vehicle(v)

        elif secim == "2":
            plaka = input("Çıkarılacak Araç Plakası: ")
            lot.remove_vehicle(plaka)

        elif secim == "3":
            if lot.check_availability():
                print(f"Otopark müsait. Boş yer: {lot.capacity - len(lot.spaces)}")
            else:
                print("Otopark dolu!")

        elif secim == "4":
            plaka = input("Aranacak Plaka: ")
            v = lot.search_vehicle(plaka)
            if v:
                print("Araç bulundu:")
                v.print_vehicle()
            else:
                print("Araç bulunamadı.")

        elif secim == "5":
            lot.sort_by_entry_time()

        elif secim == "6":
            lot.print_parking_lot()

        elif secim == "0":
            print("Çıkış yapılıyor...")
            break

        else:
            print("Geçersiz seçim!")

if __name__ == "__main__":
    main()