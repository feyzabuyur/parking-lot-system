# ParkingLot sınıfı - Otopark yönetimini sağlar
from vehicle import Vehicle

MAX_CAPACITY = 50  # Otoparkın maksimum kapasitesi

class ParkingLot:
    def __init__(self):
        self.spaces = []                # Araçların tutulduğu liste
        self.capacity = MAX_CAPACITY    # Maksimum kapasite

    # Araç park eder
    def park_vehicle(self, vehicle):
        if len(self.spaces) >= self.capacity:
            print("Otopark dolu!")
            return False
        self.spaces.append(vehicle)
        print(f"{vehicle.license_plate} plakalı araç park edildi.")
        return True

    # Plakaya göre araç çıkarır
    def remove_vehicle(self, license_plate):
        for i, vehicle in enumerate(self.spaces):
            if vehicle.license_plate == license_plate:
                self.spaces.pop(i)
                print(f"{license_plate} plakalı araç çıkarıldı.")
                return True
        print(f"Araç bulunamadı: {license_plate}")
        return False

    # Müsait yer kontrolü
    def check_availability(self):
        return len(self.spaces) < self.capacity

    # Plakaya göre araç arar
    def search_vehicle(self, license_plate):
        for vehicle in self.spaces:
            if vehicle.license_plate == license_plate:
                return vehicle
        return None

    # Giriş saatine göre sıralar
    def sort_by_entry_time(self):
        self.spaces.sort(key=lambda v: v.entry_time)
        print("Araçlar giriş saatine göre sıralandı.")

    # Otoparkı ekrana yazdırır
    def print_parking_lot(self):
        if len(self.spaces) == 0:
            print("Otopark boş.")
            return
        print(f"=== OTOPARK DURUMU ({len(self.spaces)}/{self.capacity}) ===")
        for vehicle in self.spaces:
            vehicle.print_vehicle()