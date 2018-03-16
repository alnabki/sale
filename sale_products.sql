-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 16, 2018 at 09:05 AM
-- Server version: 10.1.30-MariaDB
-- PHP Version: 5.6.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sale_products`
--

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `ID` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `age` int(11) NOT NULL,
  `phone` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`ID`, `name`, `age`, `phone`) VALUES
(1, 'mohamad', 45, 721251234),
(2, 'yasser', 43, 734554321),
(3, 'gabriel', 26, 2147483647),
(4, 'ttt', 33, 54322333),
(5, 'gggg', 22, 322222),
(6, 'tttt', 44, 667654),
(7, 'maha', 33, 22221223),
(8, 'jjj', 99, 2147483647),
(9, 'yyyppp', 66, 98675764),
(10, 'yyyy', 44, 67584653),
(11, 'mjjji', 99, 87675876),
(12, 'uguygyu', 666, 788756),
(13, 'ggg', 444, 56474654),
(14, 'hgchgc', 65, 5555),
(15, 'jhbhj', 6666, 765746534),
(16, 'hvjh', 776, 87766),
(17, 'wrfwe', 123, 21323),
(18, 'gyftyftrhg', 4444, 76545),
(19, 'tftrdtr', 555, 88),
(20, 'mazen', 30, 765656),
(21, 'wewre', 33, 2222),
(22, 'qewfwe', 22, 444),
(23, 'yasen', 22, 1112223),
(24, '2', 0, 2222),
(25, 'ayman', 45, 777);

-- --------------------------------------------------------

--
-- Table structure for table `order_t`
--

CREATE TABLE `order_t` (
  `ID` int(11) NOT NULL,
  `cust_ID` int(11) NOT NULL,
  `prod_ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `order_t`
--

INSERT INTO `order_t` (`ID`, `cust_ID`, `prod_ID`) VALUES
(2, 1, 2),
(4, 7, 3),
(5, 20, 7),
(6, 25, 9),
(7, 3, 10),
(8, 3, 10),
(9, 3, 5);

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `ID` int(11) NOT NULL,
  `product_name` varchar(255) NOT NULL,
  `price` int(11) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`ID`, `product_name`, `price`, `quantity`) VALUES
(1, '', 0, 0),
(2, 'camera', 344, 29),
(3, 'car', 230000, 4),
(5, 'laptop', 2000, 1),
(6, 'headphone', 40, 44),
(7, 'test', 88, 0),
(8, 'test2', 22, 333),
(9, 'qq', 22, 1),
(10, 'cow', 10000, 8),
(11, 'car', 1222, 3),
(12, 'www', 0, 0),
(13, 'rrr', 333, 3),
(14, 'efd', 0, 0),
(15, 'dddd', 23, 22),
(16, 'eee', 33, 2),
(17, 'yyy', 55, 88),
(18, 'uuu', 77, 88),
(19, 'uuu', 676, 99),
(20, 'trtr', 555, 33),
(21, 'vaat', 22, 44),
(22, 'ee', 22, 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `order_t`
--
ALTER TABLE `order_t`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `orderfk1` (`cust_ID`),
  ADD KEY `orderfk2` (`prod_ID`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT for table `order_t`
--
ALTER TABLE `order_t`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `order_t`
--
ALTER TABLE `order_t`
  ADD CONSTRAINT `orderfk1` FOREIGN KEY (`cust_ID`) REFERENCES `customer` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `orderfk2` FOREIGN KEY (`prod_ID`) REFERENCES `products` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
