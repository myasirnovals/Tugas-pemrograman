show databases;

use kuliah_basisdata_perpustakaan;

# menampilkan data dari sebuah tabel
select *
from kategori_buku;

select nama_kategori
from kategori_buku;

# menampilkan data dengan perintah where
select *
from anggota;

select *
from anggota
where alamat = 'jl. Cimahi';

# menampilkan data dengan between
select * from denda;

select *
from denda
where jumlah_denda between 10000 and 20000;

# menampilkan perintah dengan like
select *
from anggota
where alamat like '%cimahi%';

# menampilkan data dengan pengurutan sorting (order by)
select *
from anggota
order by nama_anggota asc;

select *
from anggota
order by nama_anggota desc;

# menampilkan data dengan pengelompokan data group by
select *
from anggota
group by alamat;