# eFishery Skill Test
Sebuah sistem pengiriman data ke server dimana terdapat 2 perangkat yang berperan di dalam sistem ini, yaitu forwarder node dan sensor node.

# Rincian
Forwader Node: NodeMCU Lolin v3 sebagai penerima data acak dari beberapa sensor node, sebagai publisher dan subscriber, dan menampilkan web server untuk memberi perintah kepada forwarder node

Sensor Node: Arduino Uno sebagai penghasil dan pengirim data acak ke Forwader Node

Koneksi: Kedua perangkat berkomunikasi dengan perantara modul nRF24L01

# Catatan
- Alamat server MQTT yang digunakan adalah http://broker.mqtt-dashboard.com/
- Banyaknya pengguna yang mengakses server tersebut akan berdampak pada sistem pengiriman data ke server, seperti koneksi yang terputus secara tiba-tiba dalam waktu 3-5 menit
- Berhubung sistem dibuat dengan menggunakan perangkat asli, bukan simulasi, forwarder node perlu di-restart kembali jika koneksi server MQTT sudah terputus
- Saat ini, sistem WebServer sedang dinonaktifkan karena pemakaian protokol MQTT dan HTTP secara bersamaan dapat menyebabkan koneksi server MQTT terputus
- Jika WebServer sedang diakses, WebServer akan menampilkan sebuah switch yang berguna untuk menghidupkan/mematikan lampu LED pada Development Board
- Aplikasi yang digunakan untuk melihat data topik MQTT dari handphone adalah MyMQTT
- Topik MQTT yang digunakan sebanyak 2 buah, yaitu "pub_octa" dan "sub_octa"
- Forwader Node mengirim data ke MQTT server dengan topik pub_octa
- Forwader Node menerima data dari MQTT server dengan topik sub_octa
- Jika perangkat handphone mengirim nilai 1 atau 0 pada topik sub_octa, Forwarder Node akan menghidupkan/mematikan lampu LED pada Development Board
- BackEnd yang saya gunakan untuk melihat data pada MQTT server adalah Node-Red
