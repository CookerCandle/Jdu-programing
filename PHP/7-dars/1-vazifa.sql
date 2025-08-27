CREATE DATABASE texnomart;

USE texnomart;

CREATE TABLE `telefonlar` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `nomi` VARCHAR(45) NULL,
  `narxi` INT NULL,
  `soni` INT NULL,
  PRIMARY KEY (`id`)
);