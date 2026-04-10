# Parking Lot Management System
## CENG110 – Programming and Computation II – Project 7

## Grup Üyeleri
- Feyzanur Buyur
- Asya Naz Uyanık
- Yasemin Mehter
- Samed Şen

## Proje Açıklaması
Bu proje, bir otoparkın yönetimini simüle eden konsol tabanlı bir 
yazılım sistemidir. Sistem, araçların otoparka girişini ve çıkışını 
takip eder, müsait yer kontrolü yapar ve araçları giriş saatine göre 
sıralayabilir. Proje Python dili kullanılarak modüler bir yapıda 
geliştirilmiştir.

## Kullanılan Veri Yapısı
Veri yapısı olarak liste (List) tercih edilmiştir. Otoparkın sabit 
bir kapasitesi olduğundan ve araçlara plaka numarasıyla rastgele 
erişim gerektiğinden liste en uygun seçenek olarak belirlenmiştir.

## Özellikler
- Araç park etme
- Araç çıkarma
- Müsait yer kontrolü
- Plakaya göre araç arama
- Giriş saatine göre sıralama
- Tüm otoparkı listeleme

## Gereksinimler
- Python 3.x

## Çalıştırma
python3 src/main.py

## Dosya Yapısı
parking-lot-system/
├── README.md
└── src/
    ├── vehicle.py      → Vehicle sınıfı
    ├── parkinglot.py   → ParkingLot sınıfı
    └── main.py         → Ana program ve kullanıcı arayüzü

## Örnek Kullanım
Program çalıştırıldığında aşağıdaki menü görüntülenir:

=== OTOPARK YÖNETİM SİSTEMİ ===
1. Araç Park Et
2. Araç Çıkar
3. Müsaitlik Kontrol Et
4. Araç Ara
5. Giriş Saatine Göre Sırala
6. Otoparkı Göster
0. Çıkış