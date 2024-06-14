-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 14, 2024 at 04:11 AM
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
(18, 'Antangin', '7500', '66569b2559bc2.png', 1),
(19, 'Aspilet', '25500', '66569b6cd10cb.png', 1),
(20, 'Betadine', '16000', '66569b993c1af.png', 1);

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
(6, 'Antangin', 'Obat herbal untuk mengatasi masuk angin', 7500, '66569b2559bc2.png', '2025-05-29'),
(7, 'Aspilet', 'Obat pengencer darah', 25500, '66569b6cd10cb.png', '2024-10-26'),
(8, 'Betadine', 'Obat penutup luka ringan', 16000, '66569b993c1af.png', '2025-12-01'),
(9, 'Boderx', 'Obat sakit kepala', 9500, '66569bf527aa7.png', '2024-08-27'),
(10, 'OBH Combi', 'Obat flu dan batuk berdahak', 14500, '66569c1bea5cd.png', '2025-01-31'),
(11, 'Vitamin C', 'suplemen vitamin yang baik bagi tubuh', 3500, '66569c54d16e0.png', '2025-03-25'),
(12, 'Paramex', 'Obat sakit kepala', 6000, '66569c7413f78.png', '2024-12-04'),
(13, 'Paracetamol', 'Obat penurun panas/demam', 7000, '66569c98a43ce.png', '2025-04-15'),
(14, 'Ponstan', 'Obat sakit gigi', 27500, '66569cb5c302e.png', '2025-09-30'),
(15, 'Strepsils', 'Permen pereda tenggorokan', 14000, '66668e690e25c.png', '2024-07-17');

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
(2, 'Suzukaze Aoba', 'karyawan1@gmail.com', '$2y$10$r3BkW0EL17tNPIkdoCcZmuVXGoYOx1StPwb1NbceI5LUQ4HAhl6Tm', 'Tokyo, Jepang', '2006-02-02', '2', '66668d872256a.jpg'),
(3, 'Satomi Rentaro', 'karyawan2@gmail.com', '$2y$10$E6DoERll/7NP/qaNCF9p3.p9Cbg9sb7pqZcKPbaB5DfsRqUAoOq/O', 'Tokyo, Jepang', '2008-11-01', '2', '66668e1f83c6a.jpg'),
(10, 'Jeremiah', 'jeremiah@gmail.com', '$2y$10$UZYU38ePqQiZVK1smLZsue5oV8KSdUdO2XNRoWHtdC3F1NXRhf/lK', '', '', '0', '');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id_barang`);

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
  MODIFY `id_barang` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT for table `produk`
--
ALTER TABLE `produk`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
