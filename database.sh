lxc exec Database -- sh -c 'mysql -u root -e "CREATE DATABASE MyDB;"'
lxc exec Database -- sh -c "mysql -u root -e \"CREATE USER 'cloud_user' IDENTIFIED BY 'Test321';\""
lxc exec Database -- sh -c "mysql -u root -e \"GRANT USAGE ON *.* TO 'cloud_user'@'%' IDENTIFIED BY 'Test321';\""
lxc exec Database -- sh -c "mysql -u root -e \"GRANT ALL privileges ON MyDB.* TO 'cloud_user'@'%';\""
lxc exec Database -- sh -c "mysql -u root -e \"SET PASSWORD FOR 'root'@'localhost' = PASSWORD('321TestForRoot321');\""
lxc exec Database -- sh -c "mysql -u root -e \"FLUSH PRIVILEGES;\""
