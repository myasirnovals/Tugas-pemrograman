show databases;

use kuliah_basisdata_perpustakaan;

show tables;

# 1. Tampilkan data peminjaman dari tanggal 1-31 (bulan dan tahun tergantung data yang sudah di insert)
desc peminjaman;

select *
from peminjaman
where tanggal_peminjaman between 1 and 31;

# 2. tampilkan data anggota yang berjenis kelamin laki-laki
desc anggota;

select *
from anggota
where jenis_kelamin = 'L';

# 3. tampilkan data pengembalian yang sudah melewati tenggat hari ini
desc peminjaman;

select *
from peminjaman
where tanggal_pengembalian > current_date;

# 4. tampilkan denda paling banyak ke paling sedikit
desc denda;

select jumlah_denda
from denda
order by jumlah_denda desc;

# 5. tampilkan data buku berdasarkan kategorinya
desc buku;

select *
from buku
group by kategori_id;