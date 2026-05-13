# IP - Port - DNS - TCP - UDP nedir?
## IP (Internet Protocol)
Tanım: Bir ağa bağlı olan her cihazın (bilgisayar, sunucu, telefon) sahip olduğu benzersiz dijital kimlik numarasıdır. Veri paketlerinin dünya genelindeki ağlar üzerinden doğru hedefe yönlendirilmesini sağlar.
* Sunucu Yönetimi: Bir web uygulamasını yayına aldığınızda (deployment), uygulamanızın barındığı makinenin bir IP adresi vardır.
* API Güvenliği: Backend geliştirirken, API'nize sadece belirli güvenli IP'lerden (Whitelist) erişim verilmesini sağlayarak güvenliği katmanlandırırsınız.
* Ağ Yapılandırması: Mikroservis mimarilerinde servislerin birbiriyle konuşması için iç ağ (internal network) IP'leri kullanılır.

## Port 
Tanım: Bir bilgisayar veya sunucu üzerindeki belirli bir servis veya uygulamaya açılan sanal kapıdır. IP adresi veriyi cihaza getirirken, Port veriyi cihazın içindeki doğru yazılıma yönlendirir.
* Servis Yönetimi: Web sunucuları genellikle 80 (HTTP) veya 443 (HTTPS) portlarını dinler. Bir mühendis olarak, yerel geliştirme yaparken uygulamanızı genellikle 3000, 5000 veya 8080 gibi portlarda çalıştırırsınız.
* Konteynerleştirme (Docker): Docker kullanırken, konteyner içindeki bir portu (örneğin 80) kendi makinenizdeki bir porta (örneğin 8080) eşlersiniz (Port Mapping).
* Çakışma Çözümü: İki farklı uygulamanın aynı anda aynı portu kullanmaya çalışması "Port Conflict" hatasına yol açar; bu durumu yönetmek yazılımcının temel görevlerindendir.

## DNS (Domain Name System)
Tanım: Karmaşık IP adreslerini (örn: 142.251.37.110) insanların hatırlayabileceği anlamlı isimlere (örn: google.com) çeviren bir rehber sistemidir.
* Alan Adı Yönetimi: Yazılımın son kullanıcıya ulaşması için IP adresini bir alan adına bağlamanız gerekir.
* Load Balancing (Yük Dengeleme): DNS kayıtları aracılığıyla tek bir isim üzerinden trafiği birden fazla sunucu IP'sine dağıtarak sistemin performansını artırırsınız.
* Yerel Geliştirme: Yazılımcılar kendi makinelerinde localhost (127.0.0.1) ismini kullanarak ağ trafiğini dışarı çıkmadan test ederler.

## TCP (Transmission Control Protocol)
Tanım: Veri iletiminde güvenliği ve tamlığı garanti eden, bağlantı yönelimli bir protokolüdür. Veriyi paketlere böler, numaralandırır ve karşı tarafa eksiksiz ulaştığından emin olur.
* Veri Bütünlüğü: Web siteleri (HTTP), e-posta servisleri (SMTP) ve dosya aktarımı gibi verinin "tek bir bitinin" bile kaybolmaması gereken yerlerde TCP kullanılır.
* Hata Yönetimi: Yazdığınız kod üzerinden bir TCP bağlantısı kurduğunuzda, paket kaybı durumunda protokol bunu otomatik olarak tekrar gönderir; yazılımcının bu düşük seviyeli hatayla uğraşmasına gerek kalmaz.
* Performans: TCP'nin "el sıkışma" (Handshake) süreci zaman aldığı için, çok yüksek hız gerektiren ama veri kaybının tolere edilebildiği yerlerde tercih edilmez.

## UDP (User Datagram Protocol)
Tanım: Hız odaklı, bağlantısız ve kontrol mekanizması bulunmayan bir protokolüdür. Veriyi "fırlatır" ve karşı tarafa ulaşıp ulaşmadığını denetlemez.
* Gerçek Zamanlı Uygulamalar: Online oyun geliştiriciliği, canlı yayın (streaming) ve VoIP (sesli görüşme) yazılımlarında düşük gecikme (latency) sağlamak için UDP kullanılır.
* Yüksek Performanslı Sistemler: Sistem izleme (monitoring) veya loglama gibi saniyede binlerce verinin aktığı ve birkaç paketin kaybolmasının kritik olmadığı sistemlerde kullanılır.
* Düşük Gecikme Önceliği: Yazılımcı, verinin güvenliği yerine hızın kritik olduğu senaryolarda bilinçli olarak UDP soketleri açar.

# Paket Yapısı Nasıl Çalışır?
## Paketin Anatomisi (Bir Veri Paketinin İçinde Ne Var?)
Bir paket, tıpkı fiziksel bir posta paketi gibi üç ana bölümden oluşur:
A. Header (Başlık / Zarf)
Paketin "yönlendirme" bilgilerini içerir.
* Kaynak ve Hedef IP: Paket nereden çıktı, nereye gidiyor?
* Port Numarası: Hangi uygulamaya (HTTP, Spotify, Oyun vb.) teslim edilecek?
* Protokol Bilgisi: TCP mi yoksa UDP mi kullanılıyor?
* Sıra Numarası (Sequence Number): Veri parçalara bölündüğü için, karşı tarafta doğru sırayla birleşmesi için gereken numara.
B. Payload (Veri / İçerik)
Paketin asıl taşıdığı "yük"dür. Gönderdiğin WhatsApp mesajının bir parçası, bir resmin birkaç pikseli veya bir HTML kodunun bir satırı burada yer alır.
C. Trailer (Kuyruk / Kontrol)
Paketin sonuna eklenen ve verinin yolda bozulup bozulmadığını kontrol eden bölümdür (Checksum). Eğer buradaki hesaplama karşı tarafta tutmazsa, paket hatalı kabul edilir.

## Kapsülleme Süreci
Veri, uygulama katmanından fiziksel kabloya inene kadar her aşamada yeni bir "zarfın" içine girer. Buna Encapsulation denir.
1. Veri (Data): Senin yazdığın "Merhaba" mesajı.
2. Segment (TCP/UDP): Verinin başına port numarası eklenir.
3. Paket (IP): Başına IP adresleri eklenir.
4. Frame (Ethernet): En dışa fiziksel adres (MAC adresi) eklenir.
5. Bitler: Artık veri 1 ve 0'lara dönüşüp kablodan veya Wi-Fi'dan fırlar.

## Yazılım Mühendisliği ile Kavram ilişkisi
Bir yazılımcı neden paket yapısını bilmelidir?
A. MTU (Maximum Transmission Unit) ve Parçalama
İnternet üzerinde bir paketin taşıyabileceği maksimum boyut sınırlıdır (genelde 1500 byte).
* İlişki: Çok büyük bir JSON verisi gönderdiğinde, ağ kartı bunu otomatik olarak paketlere böler. Yazılım mühendisi olarak, verinin parçalanarak (fragmentation) gideceğini bilmek, ağ üzerindeki gecikmeleri (latency) anlamanı sağlar.
B. Paket Kaybı ve "Retry" Mekanizmaları
Ağda bazen paketler kaybolur (Packet Loss).
* İlişki: Eğer TCP kullanıyorsan, protokol bunu senin yerine halleder. Ancak UDP kullanıyorsan (örneğin bir oyun yazıyorsan), kaybolan paketlerin yarattığı "takılma" (lag) sorunlarını yazılımsal olarak senin yönetmen gerekebilir.
C. Güvenlik (Deep Packet Inspection)
Kötü amaçlı yazılımlar bazen paketlerin "Payload" kısmına zararlı kodlar gizler.
* İlişki: Siber güvenlik odaklı bir yazılım geliştiriyorsan, gelen paketlerin başlıklarını ve içeriklerini analiz ederek (Packet Sniffing) saldırıları tespit eden algoritmalar yazarsın.
D. Serialization (Serileştirme)
Yazılımda bir "Object" (nesne) oluşturursun, ama bu nesne olduğu gibi paket içine giremez.
* İlişki: Nesneyi paketlerin taşıyabileceği bir formata (JSON, XML veya Binary) çevirme işlemine Serialization denir. Yazılım mühendisleri, paket boyutunu küçültmek için en verimli serileştirme yöntemini seçmek zorundadır.

# Ping, Tracerout, Nslookup Ne İşe Yarar?
## Ping
Tanım: Hedefteki bir cihazın (sunucunun) hayatta olup olmadığını ve ona ne kadar sürede ulaşıldığını kontrol eden en temel araçtır. ICMP protokolünü kullanarak karşı tarafa küçük bir paket gönderir ve "Eko" (cevap) bekler.
* Erişilebilirlik Testi: Yazdığınız uygulama bir veri tabanına veya dış API'ye bağlanamıyorsa, ilk iş ilgili IP adresine "ping" atmaktır. Eğer cevap gelmiyorsa sorun koddur değil, ağ erişimidir.
* Gecikme (Latency) Analizi: Ping sonucu dönen ms (milisaniye) değeri, uygulamanın tepki hızını belirler. Özellikle oyun veya borsa yazılımlarında yüksek ping, yazılımın performansını doğrudan etkiler.

## Tracerout
Tanım: Bir veri paketinin bilgisayarınızdan çıkıp hedef sunucuya varana kadar hangi duraklardan (router/yönlendirici) geçtiğini listeleyen araçtır. Paketlerin izlediği yolu "sekme sekme" (hop by hop) gösterir.
* Darboğaz Tespiti: Uygulamanız yavaş çalışıyorsa, traceroute ile paketin hangi düğümde (hop) takıldığını veya çok uzun süre beklediğini görebilirsiniz.
* Bölgesel Sorunlar: Yazılımınız dünyanın bir ucundaki kullanıcılar için yavaşken diğerleri için hızlıysa, ağ rotasındaki kopuklukları veya hatalı yönlendirmeleri teşhis etmekte kullanılır.

## Nslookup
Tanım: Bir alan adının (DNS) hangi IP adresine karşılık geldiğini sorgulayan ve DNS kayıtlarını detaylıca inceleyen araçtır. "Bu sitenin IP'si ne?" sorusunun teknik cevabıdır.
* DNS Yapılandırma Kontrolü: Yeni bir domain aldığınızda veya sunucu taşıdığınızda, DNS kayıtlarının (A, CNAME, MX vb.) doğru IP'ye yönlenip yönlenmediğini nslookup ile teyit edersiniz.
* Environment (Ortam) Yönetimi: Şirket içi ağlarda (Intranet) bazen api.test.yerel gibi özel isimler kullanılır. Yazılımın yanlış sunucuya (örneğin test yerine prodüksiyon sunucusuna) bağlanma hatasını çözmek için DNS kayıtları bu araçla kontrol edilir.