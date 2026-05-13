# NTFS - ext4 - APFS farkları nelerdir?
Yazılım mühendisliği perspektifinden dosya sistemleri, verinin fiziksel depolama birimleri üzerindeki organizasyonunu, erişim protokollerini ve veri bütünlüğünü yöneten alt seviye katmanlardır. Günümüzde en yaygın kullanılan üç mimari; Windows ekosistemi için NTFS, Linux tabanlı sistemler için ext4 ve Apple donanımları için optimize edilmiş olan APFS’tir.
## NTFS
Microsoft tarafından geliştirilen NTFS, kurumsal düzeyde güvenlik ve veri yapılandırması sunan bir sistemdir.

## ext4
Linux çekirdeğinin varsayılan dosya sistemi olan ext4, performans ve ölçeklenebilirlik odaklıdır.

## APFS
Flash ve SSD depolama teknolojileri için özel olarak tasarlanmış modern bir dosya sistemidir.

# Blok Yapısı Nedir?
İşletim sisteminin depolama birimlerini soyutlayarak veriyi yönettiği temel birimdir. Yazılım mühendisliğinde, dosya sisteminin blok boyutu ile uygulamanın veri işleme karakteristiği (küçük çok sayıda dosya veya büyük tekil dosyalar) arasındaki uyum, sistemin genel verimliliğini ve veri erişim hızını belirleyen ana parametrelerden biridir.

# HDD vs SSD Çalışma Prensipleri
HDD ve SSD arasındaki temel fark, veriye erişim yöntemleridir; HDD’ler dönen manyetik plakalar üzerinde hareket eden mekanik bir okuma kolu kullanarak plak üzerindeki verileri fiziksel olarak arayıp bulurken, SSD’ler hiçbir hareketli parça barındırmayan NAND flash bellek yongaları sayesinde verileri doğrudan elektrik sinyalleriyle işler. Bu yapısal fark, SSD’lerin HDD’lere göre çok daha yüksek hızlarda çalışmasını, darbelere karşı dayanıklı ve tamamen sessiz olmasını sağlarken; HDD’ler daha düşük maliyetle yüksek depolama kapasitesi sunma avantajını korumaktadır.