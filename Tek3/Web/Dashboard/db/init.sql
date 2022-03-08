CREATE TABLE IF NOT EXISTS `user` (
    `id` INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `email` VARCHAR(200) NOT NULL,
    `password` VARCHAR(200) NULL,
    `idOAuth2` VARCHAR(1230) NULL,
    `service` ENUM('Google', 'Facebook', 'Microsoft', 'None') NOT NULL DEFAULT 'None',
    `urlCover` VARCHAR(500) NOT NULL
);

CREATE TABLE IF NOT EXISTS `widget` (
    `id` INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `user_id` INT NOT NULL,
    `service` ENUM('Youtube', 'Github', 'NASA', 'Spotify', 'Weather', 'CurrencyConverter', 'None') NOT NULL DEFAULT 'None',
    `title` VARCHAR(200) NOT NULL,
    `city` VARCHAR(200) NULL,
    `date` VARCHAR(200) NULL,
    `urlProfile` VARCHAR(200) NULL,
    `x` INT NOT NULL,
    `y` INT NOT NULL,
    FOREIGN KEY (`user_id`) REFERENCES `user` (`id`)
);
