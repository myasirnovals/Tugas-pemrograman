# Membuat user
CREATE USER 'yasir'@'localhost' IDENTIFIED BY 'root';

# Memberikan Hak Akses kepada user
GRANT ALL PRIVILEGES on *.* TO 'yasir'@'localhost' WITH GRANT OPTION;