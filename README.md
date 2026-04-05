# Parking Lot Management System
## CENG110 – Programming and Computation II – Project 7

## Grup Üyeleri
- Feyzanur Buyur
- Asya Naz Uyanık
- Yasemin Mehter
- Samet Şen

## Proje Açıklaması
Bu proje, bir otoparkın yönetimini simüle eden konsol tabanlı bir 
yazılım sistemidir. Sistem, araçların otoparka girişini ve çıkışını 
takip eder, müsait yer kontrolü yapar ve araçları giriş saatine göre 
sıralayabilir. Proje, nesne yönelimli olmayan C dili kullanılarak 
modüler bir yapıda geliştirilmiştir.

## Kullanılan Veri Yapısı
Veri yapısı olarak dizi (Array) tercih edilmiştir. Otoparkın sabit 
bir kapasitesi olduğundan ve araçlara plaka numarasıyla rastgele 
erişim gerektiğinden dizi en uygun seçenek olarak belirlenmiştir.

## Özellikler
- Araç park etme
- Araç çıkarma
- Müsait yer kontrolü
- Plakaya göre araç arama
- Giriş saatine göre sıralama
- Tüm otoparkı listeleme

## Gereksinimler
- GCC derleyici
- MacOS veya Linux işletim sistemi

## Derleme
Projeyi derlemek için terminal üzerinden aşağıdaki komutu çalıştırın:

gcc src/main.c src/vehicle.c src/parkinglot.c -o parking

## Çalıştırma
Derleme tamamlandıktan sonra programı çalıştırmak için:

./parking

## Dosya Yapısı
parking-lot-system/
├── README.md
└── src/
    ├── vehicle.h       → Vehicle ADT tanımı ve fonksiyon prototipleri
    ├── vehicle.c       → Vehicle fonksiyonlarının implementasyonu
    ├── parkinglot.h    → ParkingLot ADT tanımı ve fonksiyon prototipleri
    ├── parkinglot.c    → ParkingLot fonksiyonlarının implementasyonu
    └── main.c          → Ana program ve kullanıcı arayüzü

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

Menüden istediğiniz işlemi seçerek devam edebilirsiniz.
Araç park ederken plaka, sahip adı, araç tipi ve giriş saati 
bilgilerini girmeniz gerekmektedir.