show databases;

use kuliah_basisdata_perpustakaan;

# Agregasi
select avg(denda.jumlah_denda) as rata_rata
from denda;

select count(buku.buku_id) as jumlah_buku
from buku;

select max(buku.tahun_terbit) as tahun_terbit_terbaru
from buku;

select min(denda.jumlah_denda) as denda_terkecil
from denda;

select sum(denda.jumlah_denda) as total_denda
from denda;

# Query join
# inner join
select peminjaman.peminjaman_id,
       anggota.nama_anggota,
       buku.judul_buku,
       peminjaman.tanggal_peminjaman
from peminjaman
         inner join anggota on peminjaman.anggota_id = anggota.anggota_id
         inner join buku on peminjaman.buku_id = buku.buku_id;

# right join
select buku.judul_buku,
       anggota.nama_anggota
from buku
         right join peminjaman on buku.buku_id = peminjaman.buku_id
         right join anggota on peminjaman.anggota_id = anggota.anggota_id;

# cross join
select anggota.nama_anggota,
       buku.judul_buku
from anggota
         cross join buku;
