-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 25, 2024 at 08:30 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `apotek_online`
--

-- --------------------------------------------------------

--
-- Table structure for table `cart`
--

CREATE TABLE `cart` (
  `id_barang` int(11) NOT NULL,
  `nama_barang` varchar(225) NOT NULL,
  `harga_barang` varchar(225) NOT NULL,
  `gambar_barang` varchar(225) NOT NULL,
  `jumlah_barang` int(225) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cart`
--

INSERT INTO `cart` (`id_barang`, `nama_barang`, `harga_barang`, `gambar_barang`, `jumlah_barang`) VALUES
(31, 'Antangin', '7500', '66569b2559bc2.png', 3),
(32, 'Aspilet', '25500', '66569b6cd10cb.png', 1),
(33, 'Betadine', '16000', '66569b993c1af.png', 1);

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `id_pesanan` int(11) NOT NULL,
  `nama_user` varchar(225) NOT NULL,
  `no_hp` varchar(225) NOT NULL,
  `email` varchar(225) NOT NULL,
  `pembayaran` int(11) NOT NULL,
  `alamat` varchar(225) NOT NULL,
  `total_produk` varchar(255) NOT NULL,
  `total_harga` varchar(225) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`id_pesanan`, `nama_user`, `no_hp`, `email`, `pembayaran`, `alamat`, `total_produk`, `total_harga`) VALUES
(23, 'Jeremiah', '08392213992', 'jeremiah@gmail.com', 200000, 'Bamboo', 'Antangin (3) , Aspilet (1) , Betadine (1) ', '64000');

-- --------------------------------------------------------

--
-- Table structure for table `produk`
--

CREATE TABLE `produk` (
  `id` int(11) NOT NULL,
  `nama_produk` varchar(225) NOT NULL,
  `keterangan_produk` varchar(225) NOT NULL,
  `harga` int(11) NOT NULL,
  `gambar_produk` varchar(225) NOT NULL,
  `tanggal_exp` varchar(225) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `produk`
--

INSERT INTO `produk` (`id`, `nama_produk`, `keterangan_produk`, `harga`, `gambar_produk`, `tanggal_exp`) VALUES
(6, 'Antangin', 'Obat herbal untuk mengatasi masuk angin', 7500, '6671fcb34db8b.png', '2025-07-17'),
(7, 'Aspilet', 'Obat pengencer darah', 25500, '66569b6cd10cb.png', '2024-10-26'),
(8, 'Betadine', 'Obat penutup luka ringan', 16000, '66569b993c1af.png', '2025-12-01'),
(9, 'Boderx', 'Obat sakit kepala', 9500, '66569bf527aa7.png', '2024-08-27'),
(10, 'OBH Combi', 'Obat flu dan batuk berdahak', 14500, '66569c1bea5cd.png', '2025-01-31'),
(11, 'Vitamin C', 'suplemen vitamin yang baik bagi tubuh', 3500, '66569c54d16e0.png', '2025-03-25'),
(12, 'Paramex', 'Obat sakit kepala', 6000, '66569c7413f78.png', '2024-12-04'),
(13, 'Paracetamol', 'Obat penurun panas/demam', 7500, '667235d6c8ba0.png', '2025-04-15'),
(14, 'Ponstan', 'Obat sakit gigi', 27500, '66569cb5c302e.png', '2025-09-30'),
(17, 'Strepsils', 'Permen pereda tenggorokan', 17000, '6671fc2450047.png', '2024-06-29');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `nama` varchar(225) NOT NULL,
  `email` varchar(225) NOT NULL,
  `password` varchar(225) NOT NULL,
  `alamat` varchar(224) NOT NULL,
  `tanggal` varchar(225) NOT NULL,
  `role` varchar(1) DEFAULT '0',
  `foto_profile` varchar(225) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `nama`, `email`, `password`, `alamat`, `tanggal`, `role`, `foto_profile`) VALUES
(1, 'admin', 'admin@gmail.com', '$2y$10$J73tUjR7NTcmWj/1BsZL9eqqwlgZrte1CVVQFXc5fADc2fOuvY/Ye', '', '', '1', ''),
(2, 'Suzukaze Aoba', 'karyawan1@gmail.com', '$2y$10$DluyWVOckjXAH0osbkN09uCRv1dhbwEJv9UBb9qXsSfp1cKi6ZOGS', 'Tokyo, Jepang', '2006-02-02', '2', '667235af4f9d8.jpg'),
(3, 'Satomi Rentaro', 'karyawan2@gmail.com', '$2y$10$E6DoERll/7NP/qaNCF9p3.p9Cbg9sb7pqZcKPbaB5DfsRqUAoOq/O', 'Tokyo, Jepang', '2008-11-01', '2', '66668e1f83c6a.jpg'),
(10, 'Jeremiah', 'jeremiah@gmail.com', '$2y$10$UZYU38ePqQiZVK1smLZsue5oV8KSdUdO2XNRoWHtdC3F1NXRhf/lK', 'Kec.Batujajar Barat, KBB, Bandung, Prov.Jawa Barat, Indonesia', '', '0', ''),
(11, 'Tachibana Kanade', 'karyawan3@gmail.com', '$2y$10$jtDChBVz9iI2cp7/Nse5pujBtgk0GW0uIP5WJakLScMlwWPXhFtlC', 'Tokyo, Jepang', '2007-03-07', '2', '66723581006eb.jpg');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id_barang`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`id_pesanan`);

--
-- Indexes for table `produk`
--
ALTER TABLE `produk`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cart`
--
ALTER TABLE `cart`
  MODIFY `id_barang` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=34;

--
-- AUTO_INCREMENT for table `orders`
--
ALTER TABLE `orders`
  MODIFY `id_pesanan` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `produk`
--
ALTER TABLE `produk`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
