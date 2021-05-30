# Proposal - Program Sistem PPDB
Repositori ini berisi _source code_ program dari sistem penerimaan peserta didik baru. Program ini dibangun menggunakan bahasa C++. Pembuatan program ini ditujukan untuk memenuhi penugasan _final project_ mata kuliah Struktur Data.

## Contributors
- Adam Putra Bramantyo (19081010053)
- Hamdan Yuwafi Mastu Wijaya (19081010092)

## Permulaan
### Abstraksi
Kami memilih kasus sistem pendaftaran siswa baru. Sistem ini memiliki cakupan: (1) Sistem antrian pendaftaran; (2) Sistem seleksi berdasarkan nilai uji tulis; (3) Sistem pembagian kelas berdasarkan nilai uji tulis. 

Pada sistem ini, tipe data yang mungkin dapat digunakan yaitu (_single_) _linked list_, _queue_, dan _forest_.

### Narasi
Saat pendaftaran siswa baru, calon peserta didik akan mendaftar menggunakan nilai tes tulis. Calon peserta didik wajib memasukkan nomor ujian untuk mendapatkan nomor antrian. Mereka akan mengantri untuk mendaftar.

Setelah nomor antrian terpanggil, berkas pendaftaran akan dikumpulkan dan masuk ke seleksi dokumen. Seleksi ini membandingkan nilai antar peserta didik yang akan diterima. Nilai uji tulis terbaik yang masuk dalam pemeringkatan kuota penerimaan, akan dinyatakan _eligible_ dan lulus untuk menjadi peserta didik sekolah tersebut. Calon peserta didik yang nilai uji tulisnya tidak memenuhi akan dinyatakan tidak _eligible_ dan tidak lulus untuk menjadi peserta didik sekolah tersebut. Batasan kuota calon peserta didik yang diterima ditetapkan sebelum masa pendaftaran peserta didik berjalan.

Setelah masa pendaftaran peserta didik baru selesai, sistem pendaftaran tidak lagi akan mengalami _input_ data. Admin akan menentukan jumlah kelas dan jumlah peserta didik dengan beberapa validasi.

Hasil seleksi akan keluar berdasarkan urutan nilai uji tulis. Pengumuman akan dirilis ke media cetak. Dalam pengumuman ini, hanya menampilkan nama dan asal sekolah calon peserta didik. Peserta didik belum dibagi dalam kelas-kelas.

Setelah hasil seleksi dirilis, calon peserta didik yang diterima akan dibagi dalam kelas berdasarkan nilai uji tulis. Jumlah kelas dan jumlah maksimal peserta didik per kelas ditetapkan sebelum hasil seleksi diumumkan. Pengumuman pembagian kelas peserta didik baru akan dicantumkan dalam media cetak.

## Tipe Data
### _Single Linked List_
_Single Linked List_ akan diterapkan pada sistem seleksi berdasarkan nilai. Konsep _inner insert_ (memasukkan data di tengah), _front insert_ (memasukkan data di depan), _rear insert_ (memasukkan data di belakang), _rear dropping_ (menghapus data di belakang), _read all_ (baca semua data) dan _read spesific data_ (baca data spesifik) akan diterapkan. Tipe data ini juga akan digunakan pada tipe data-tipe data yang akan diterapkan setelahnya.

### _Queue_
_Queue_ akan digunakan untuk sistem antrian calon peserta didik untuk proses penyerahan berkas. Sehingga, berkas yang pertama datang akan diproses terlebih dahulu.

### _Forest_
_Forest_ akan digunakan untuk sistem pembagian kelas bagi calon peserta didik yang telah diterima. Dengan metode stacking, calon peserta didik akan dibagi berdasarkan nilai uji tulis.

## Hubungan Antar Tipe Data
### Sistem Antrian
Perekaman data pada sistem antrian akan menggunakan single linked list yang dikelola dengan metode _regular queue_. Sehingga, jumlah data yang dapat ditampung akan fleksibel dan akan dikeluarkan berdasarkan sistem FIFO (_First In, First Out_).

### Sistem Antrian - Sistem Seleksi
Calon peserta didik dengan nomor antrian yang terpanggil akan menuju bagian admin untuk menyerahkan dokumen untuk proses seleksi nilai. Nomor antrian yang terpanggil secara otomatis akan terhapus dari daftar antrian dan data nomor ujian akan masuk ke sistem seleksi.

### Sistem Seleksi
Petugas pendaftaran akan memasukkan beberapa data yang dibutuhkan (nomor pendaftaran, nama calon peserta didik, sekolah asal calon peserta didik dan nilai uji tulis). Berkas pendaftaran akan disimpan untuk keperluan administrasi. Data yang di-_input_-kan akan diseleksi dan dieliminasi oleh sistem secara otomatis melalui pemeringkatan dengan _single linked list_.

### Sistem Seleksi - Sistem Pembagian Kelas
Ketika masa pendaftaran telah ditutup, data seleksi akan difiksasi sehingga didapat daftar calon peserta didik yang diterima. Kemudian, daftar tersebut akan dirilis dalam sebuah tabel pengumuman. Selain itu, data tersebut akan masuk ke sistem pembagian kelas untuk membagi peserta didik dalam beberapa kelas berdasarkan urutan tersebut. Jumlah kelas dan peserta didik per kelas akan ditetapkan di sini dengan beberapa validasi data _input_.

### Sistem Pembagian Kelas
Setelah jumlah kelas dan jumlah maksimum peserta didik ditetapkan, sistem akan membagi data peserta didik yang diterima dalam beberapa kelas yang ditentukan. Dengan tipe data _forest_, yang akan memberikan fleksibilitas jumlah kelas yang akan dibentuk. Setiap kelas akan terhubung dengan peserta didiknya dengan tipe data _acyclic graph_. Kemudian, hasil pembagian kelas akan dirilis dalam sebuah tabel pengumuman pembagian kelas.
