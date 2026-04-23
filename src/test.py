import pytest
from parkinglot import ParkingLot
from vehicle import Vehicle

# Otopark kapasite ve park etme testi
def test_park_vehicle():
    lot = ParkingLot() # Default kapasite 50
    v1 = Vehicle("06ABC123", "Samed", "Binek", 1030)
    
    # Başarılı park işlemi
    assert lot.park_vehicle(v1) is True
    assert len(lot.spaces) == 1

# Müsaitlik kontrolü testi
def test_check_availability():
    lot = ParkingLot()
    # Başta boş olmalı
    assert lot.check_availability() is True
    
    # Kapasiteyi zorlayalım (Örnek için kapasiteyi 1 yapalım)
    lot.capacity = 1
    v1 = Vehicle("06ABC123", "Samed", "Binek", 1030)
    lot.park_vehicle(v1)
    
    # Artık dolu olmalı
    assert lot.check_availability() is False

# Araç arama testi
def test_search_vehicle():
    lot = ParkingLot()
    v1 = Vehicle("34XYZ789", "Feyza", "SUV", 1100)
    lot.park_vehicle(v1)
    
    # Mevcut aracı bulmalı
    found = lot.search_vehicle("34XYZ789")
    assert found is not None
    assert found.owner_name == "Feyza"
    
    # Olmayan aracı bulmamalı
    not_found = lot.search_vehicle("00HATA00")
    assert not_found is None

# Giriş saatine göre sıralama testi
def test_sort_by_entry_time():
    lot = ParkingLot()
    v1 = Vehicle("06A", "A", "T", 1500)
    v2 = Vehicle("06B", "B", "T", 900)
    v3 = Vehicle("06C", "C", "T", 1200)
    
    lot.park_vehicle(v1)
    lot.park_vehicle(v2)
    lot.park_vehicle(v3)
    
    lot.sort_by_entry_time()
    
    # İlk araç en erken giren (0900) olmalı
    assert lot.spaces[0].entry_time == 900
    # Son araç en geç giren (1500) olmalı
    assert lot.spaces[2].entry_time == 1500