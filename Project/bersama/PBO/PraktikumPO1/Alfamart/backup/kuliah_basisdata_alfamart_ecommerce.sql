-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 13, 2025 at 09:57 AM
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
-- Database: `kuliah_basisdata_alfamart_ecommerce`
--

-- --------------------------------------------------------

--
-- Table structure for table `cart_items`
--

CREATE TABLE `cart_items` (
                              `cart_item_id` int(11) NOT NULL,
                              `product_id` int(11) DEFAULT NULL,
                              `quantity` int(11) NOT NULL DEFAULT 1,
                              `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `categories`
--

CREATE TABLE `categories` (
                              `category_id` int(11) NOT NULL,
                              `name` varchar(50) NOT NULL,
                              `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `categories`
--

INSERT INTO `categories` (`category_id`, `name`, `created_at`) VALUES
                                                                   (1, 'Makanan Instan', '2025-01-12 00:42:20'),
                                                                   (2, 'Minuman', '2025-01-12 00:42:20'),
                                                                   (3, 'Sembako', '2025-01-12 00:42:20'),
                                                                   (4, 'Perlengkapan Mandi', '2025-01-12 00:42:20'),
                                                                   (5, 'Perlengkapan Rumah Tangga', '2025-01-12 00:42:20'),
                                                                   (6, 'Snack & Cemilan', '2025-01-12 00:42:20'),
                                                                   (7, 'Susu & Olahan Susu', '2025-01-12 00:42:20'),
                                                                   (8, 'Perawatan Bayi', '2025-01-12 00:42:20'),
                                                                   (9, 'Obat & Suplemen', '2025-01-12 00:42:20'),
                                                                   (10, 'Perlengkapan Tulis', '2025-01-12 00:42:20');

-- --------------------------------------------------------

--
-- Table structure for table `contact_messages`
--

CREATE TABLE `contact_messages` (
                                    `message_id` int(11) NOT NULL,
                                    `name` varchar(100) NOT NULL,
                                    `phone` varchar(20) DEFAULT NULL,
                                    `email` varchar(100) DEFAULT NULL,
                                    `message` text NOT NULL,
                                    `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `contact_messages`
--

INSERT INTO `contact_messages` (`message_id`, `name`, `phone`, `email`, `message`, `created_at`) VALUES
    (1, 'Muhamad Yasir Noval', '088345678123', 'example@example.com', 'terdapat bug pada aplikasi tolong perbaiki', '2025-01-12 19:33:21');

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
                          `order_id` int(11) NOT NULL,
                          `customer_name` varchar(100) NOT NULL,
                          `phone` varchar(20) NOT NULL,
                          `payment_amount` decimal(10,2) NOT NULL DEFAULT 0.00,
                          `change_amount` decimal(10,2) NOT NULL DEFAULT 0.00,
                          `total_amount` decimal(10,2) NOT NULL,
                          `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`order_id`, `customer_name`, `phone`, `payment_amount`, `change_amount`, `total_amount`, `created_at`) VALUES
    (2, 'muhamad yasir noval', '088712345678', 100000.00, 5200.00, 94800.00, '2025-01-13 08:50:11');

-- --------------------------------------------------------

--
-- Table structure for table `order_items`
--

CREATE TABLE `order_items` (
                               `order_item_id` int(11) NOT NULL,
                               `order_id` int(11) DEFAULT NULL,
                               `product_id` int(11) DEFAULT NULL,
                               `quantity` int(11) NOT NULL,
                               `price` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `order_items`
--

INSERT INTO `order_items` (`order_item_id`, `order_id`, `product_id`, `quantity`, `price`) VALUES
                                                                                               (7, 2, 1, 1, 3500.00),
                                                                                               (8, 2, 2, 1, 3300.00),
                                                                                               (9, 2, 3, 1, 5000.00),
                                                                                               (10, 2, 40, 1, 55000.00),
                                                                                               (11, 2, 17, 1, 28000.00);

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
                            `product_id` int(11) NOT NULL,
                            `category_id` int(11) DEFAULT NULL,
                            `name` varchar(100) NOT NULL,
                            `description` text DEFAULT NULL,
                            `price` decimal(10,2) NOT NULL,
                            `discount_percentage` int(11) DEFAULT 0,
                            `image_url` varchar(255) DEFAULT NULL,
                            `stock` int(11) NOT NULL DEFAULT 0,
                            `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`product_id`, `category_id`, `name`, `description`, `price`, `discount_percentage`, `image_url`, `stock`, `created_at`) VALUES
                                                                                                                                                    (1, 1, 'Indomie Goreng', 'Mie goreng instant favorit Indonesia', 3500.00, 0, 'indomie_goreng.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (2, 1, 'Mie Sedaap Goreng', 'Mie goreng dengan rasa khas', 3300.00, 0, 'sedaap_goreng.jpg', 85, '2025-01-12 00:45:11'),
                                                                                                                                                    (3, 1, 'Pop Mie Rasa Ayam', 'Mie cup instant rasa ayam', 5000.00, 5, 'pop_mie_ayam.jpg', 50, '2025-01-12 00:45:11'),
                                                                                                                                                    (4, 1, 'Sarimi Isi 2 Rasa Soto', 'Mie instant dengan porsi dobel', 4500.00, 0, 'sarimi_soto.jpg', 75, '2025-01-12 00:45:11'),
                                                                                                                                                    (5, 1, 'Bubur Ayam Instan', 'Bubur instan dengan rasa ayam', 6500.00, 0, 'bubur_ayam.jpg', 40, '2025-01-12 00:45:11'),
                                                                                                                                                    (6, 2, 'Aqua 600ml', 'Air mineral kemasan botol', 3500.00, 0, 'aqua_600ml.jpg', 200, '2025-01-12 00:45:11'),
                                                                                                                                                    (7, 2, 'Coca Cola 1.5L', 'Minuman bersoda kemasan keluarga', 12000.00, 10, 'coca_cola_1.5L.jpg', 45, '2025-01-12 00:45:11'),
                                                                                                                                                    (8, 2, 'Teh Pucuk Harum 350ml', 'Teh dalam kemasan', 4000.00, 0, 'teh_pucuk.jpg', 150, '2025-01-12 00:45:11'),
                                                                                                                                                    (9, 2, 'Pocari Sweat 500ml', 'Minuman isotonik', 7000.00, 0, 'pocari_sweat.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (10, 2, 'Good Day Cappuccino', 'Kopi cappuccino dalam kemasan', 6500.00, 5, 'good_day.jpg', 80, '2025-01-12 00:45:11'),
                                                                                                                                                    (11, 3, 'Beras Pandan Wangi 5kg', 'Beras premium kualitas terbaik', 68000.00, 0, 'beras_pandanwangi.jpg', 30, '2025-01-12 00:45:11'),
                                                                                                                                                    (12, 3, 'Minyak Goreng Bimoli 2L', 'Minyak goreng berkualitas', 45000.00, 5, 'bimoli_2L.jpg', 40, '2025-01-12 00:45:11'),
                                                                                                                                                    (13, 3, 'Gula Pasir 1kg', 'Gula pasir putih berkualitas', 15000.00, 0, 'gula_pasir.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (14, 3, 'Telur Ayam 1kg', 'Telur ayam segar', 25000.00, 0, 'telur_ayam.jpg', 50, '2025-01-12 00:45:11'),
                                                                                                                                                    (15, 3, 'Tepung Terigu Segitiga 1kg', 'Tepung terigu serbaguna', 12000.00, 0, 'tepung_segitiga.jpg', 60, '2025-01-12 00:45:11'),
                                                                                                                                                    (16, 4, 'Lifebuoy Sabun Mandi 250ml', 'Sabun mandi antiseptik', 8500.00, 10, 'lifebuoy_sabun.jpg', 75, '2025-01-12 00:45:11'),
                                                                                                                                                    (17, 4, 'Clear Shampoo 170ml', 'Shampoo anti ketombe', 28000.00, 15, 'clear_shampoo.jpg', 45, '2025-01-12 00:45:11'),
                                                                                                                                                    (18, 4, 'Pepsodent 225g', 'Pasta gigi pemutih', 15000.00, 0, 'pepsodent.jpg', 90, '2025-01-12 00:45:11'),
                                                                                                                                                    (19, 4, 'Formula Sikat Gigi', 'Sikat gigi dengan bulu halus', 8500.00, 0, 'formula_sikatgigi.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (20, 4, 'Lux Body Wash 250ml', 'Sabun mandi cair', 25000.00, 5, 'lux_bodywash.jpg', 55, '2025-01-12 00:45:11'),
                                                                                                                                                    (21, 5, 'Rinso 1kg', 'Deterjen bubuk', 28000.00, 10, 'rinso_1kg.jpg', 60, '2025-01-12 00:45:11'),
                                                                                                                                                    (22, 5, 'Super Pel Pembersih Lantai', 'Pembersih lantai aroma lemon', 15000.00, 0, 'super_pel.jpg', 40, '2025-01-12 00:45:11'),
                                                                                                                                                    (23, 5, 'Stella Air Freshener', 'Pengharum ruangan otomatis', 35000.00, 5, 'stella.jpg', 30, '2025-01-12 00:45:11'),
                                                                                                                                                    (24, 5, 'Wipol Karbol 800ml', 'Pembersih lantai disinfektan', 18000.00, 0, 'wipol.jpg', 45, '2025-01-12 00:45:11'),
                                                                                                                                                    (25, 5, 'Baygon 600ml', 'Pembasmi serangga', 42000.00, 0, 'baygon.jpg', 35, '2025-01-12 00:45:11'),
                                                                                                                                                    (26, 6, 'Chitato 68g', 'Keripik kentang rasa sapi panggang', 9500.00, 0, 'chitato.jpg', 80, '2025-01-12 00:45:11'),
                                                                                                                                                    (27, 6, 'Oreo 137g', 'Biskuit sandwich vanilla', 10000.00, 5, 'oreo.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (28, 6, 'Tango Wafer 176g', 'Wafer rasa coklat', 12000.00, 0, 'tango.jpg', 75, '2025-01-12 00:45:11'),
                                                                                                                                                    (29, 6, 'Pocky 47g', 'Biskuit stick dengan lapisan coklat', 9000.00, 0, 'pocky.jpg', 60, '2025-01-12 00:45:11'),
                                                                                                                                                    (30, 6, 'Silverqueen 65g', 'Coklat susu', 15000.00, 10, 'silverqueen.jpg', 50, '2025-01-12 00:45:11'),
                                                                                                                                                    (31, 7, 'Ultra Milk 1L', 'Susu UHT full cream', 18000.00, 0, 'ultra_milk.jpg', 70, '2025-01-12 00:45:11'),
                                                                                                                                                    (32, 7, 'Dancow Fortigro 400g', 'Susu bubuk', 45000.00, 5, 'dancow.jpg', 40, '2025-01-12 00:45:11'),
                                                                                                                                                    (33, 7, 'Yakult 5pcs', 'Minuman probiotik', 10000.00, 0, 'yakult.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (34, 7, 'Indomilk 190ml', 'Susu kental manis', 12000.00, 0, 'indomilk.jpg', 85, '2025-01-12 00:45:11'),
                                                                                                                                                    (35, 7, 'Cimory Yogurt 250ml', 'Yogurt segar', 9500.00, 0, 'cimory.jpg', 45, '2025-01-12 00:45:11'),
                                                                                                                                                    (36, 8, 'Pampers Baby Dry M-20', 'Popok bayi ukuran M', 45000.00, 10, 'pampers.jpg', 50, '2025-01-12 00:45:11'),
                                                                                                                                                    (37, 8, 'My Baby Minyak Telon 60ml', 'Minyak telon plus', 25000.00, 0, 'mybaby_telon.jpg', 40, '2025-01-12 00:45:11'),
                                                                                                                                                    (38, 8, 'Zwitsal Baby Bath 200ml', 'Sabun bayi', 28000.00, 5, 'zwitsal.jpg', 35, '2025-01-12 00:45:11'),
                                                                                                                                                    (39, 8, 'SGM 1+ 400g', 'Susu formula', 65000.00, 0, 'sgm.jpg', 30, '2025-01-12 00:45:11'),
                                                                                                                                                    (40, 8, 'Sweety Bronze M-38', 'Popok bayi ekonomis', 55000.00, 15, 'sweety.jpg', 45, '2025-01-12 00:45:11'),
                                                                                                                                                    (41, 9, 'Paracetamol 500mg', 'Obat penurun panas', 8000.00, 0, 'paracetamol.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (42, 9, 'Vitamin C IPI', 'Suplemen vitamin C', 12000.00, 0, 'vitaminc.jpg', 75, '2025-01-12 00:45:11'),
                                                                                                                                                    (43, 9, 'Antangin JRG', 'Obat masuk angin', 3500.00, 0, 'antangin.jpg', 120, '2025-01-12 00:45:11'),
                                                                                                                                                    (44, 9, 'Tolak Angin', 'Obat herbal masuk angin', 3800.00, 0, 'tolak_angin.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (45, 9, 'Promag', 'Obat maag', 9500.00, 0, 'promag.jpg', 80, '2025-01-12 00:45:11'),
                                                                                                                                                    (46, 10, 'Buku Tulis Sinar Dunia', 'Buku tulis 58 lembar', 5000.00, 0, 'buku_tulis.jpg', 150, '2025-01-12 00:45:11'),
                                                                                                                                                    (47, 10, 'Pulpen Pilot', 'Pulpen hitam', 3500.00, 0, 'pilot.jpg', 200, '2025-01-12 00:45:11'),
                                                                                                                                                    (48, 10, 'Pensil 2B Faber Castell', 'Pensil untuk ujian', 4500.00, 0, 'pensil_2b.jpg', 100, '2025-01-12 00:45:11'),
                                                                                                                                                    (49, 10, 'Penghapus Steadtler', 'Penghapus putih', 3000.00, 0, 'penghapus.jpg', 120, '2025-01-12 00:45:11'),
                                                                                                                                                    (50, 10, 'Correction Pen Kenko', 'Tip-ex pen', 7500.00, 0, 'correction_pen.jpg', 75, '2025-01-12 00:45:11');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cart_items`
--
ALTER TABLE `cart_items`
    ADD PRIMARY KEY (`cart_item_id`),
  ADD KEY `product_id` (`product_id`);

--
-- Indexes for table `categories`
--
ALTER TABLE `categories`
    ADD PRIMARY KEY (`category_id`);

--
-- Indexes for table `contact_messages`
--
ALTER TABLE `contact_messages`
    ADD PRIMARY KEY (`message_id`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
    ADD PRIMARY KEY (`order_id`);

--
-- Indexes for table `order_items`
--
ALTER TABLE `order_items`
    ADD PRIMARY KEY (`order_item_id`),
  ADD KEY `order_id` (`order_id`),
  ADD KEY `product_id` (`product_id`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
    ADD PRIMARY KEY (`product_id`),
  ADD KEY `category_id` (`category_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cart_items`
--
ALTER TABLE `cart_items`
    MODIFY `cart_item_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `categories`
--
ALTER TABLE `categories`
    MODIFY `category_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `contact_messages`
--
ALTER TABLE `contact_messages`
    MODIFY `message_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `orders`
--
ALTER TABLE `orders`
    MODIFY `order_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `order_items`
--
ALTER TABLE `order_items`
    MODIFY `order_item_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
    MODIFY `product_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=51;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `cart_items`
--
ALTER TABLE `cart_items`
    ADD CONSTRAINT `cart_items_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `products` (`product_id`);

--
-- Constraints for table `order_items`
--
ALTER TABLE `order_items`
    ADD CONSTRAINT `order_items_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `orders` (`order_id`),
  ADD CONSTRAINT `order_items_ibfk_2` FOREIGN KEY (`product_id`) REFERENCES `products` (`product_id`);

--
-- Constraints for table `products`
--
ALTER TABLE `products`
    ADD CONSTRAINT `products_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `categories` (`category_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
