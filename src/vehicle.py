# Vehicle sınıfı - Araç bilgilerini saklar
class Vehicle:
    def __init__(self, license_plate, owner_name, vehicle_type, entry_time):
        self.license_plate = license_plate  # Plaka numarası
        self.owner_name = owner_name        # Araç sahibinin adı
        self.vehicle_type = vehicle_type    # Araç tipi
        self.entry_time = entry_time        # Giriş saati 

    def print_vehicle(self):
        print(f"Plaka     : {self.license_plate}")
        print(f"Sahip     : {self.owner_name}")
        print(f"Araç Tipi : {self.vehicle_type}")
        print(f"Giriş     : {self.entry_time}")
        print("-------------------")

    def compare_entry_time(self, other):
        if self.entry_time < other.entry_time:
            return -1
        elif self.entry_time > other.entry_time:
            return 1
        return 0