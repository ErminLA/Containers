lxc exec Database -- sh -c 'mysql -u root -e "CREATE DATABASE MyDB;"'
lxc exec Database -- sh -c "mysql -u root -e \"CREATE USER 'chronic' IDENTIFIED BY 'Test321';\""
lxc exec Database -- sh -c "mysql -u root -e \"GRANT USAGE ON *.* TO 'chronic'@'%' IDENTIFIED BY 'Test321';\""
lxc exec Database -- sh -c "mysql -u root -e \"GRANT ALL privileges ON 'MyDB'.* TO 'chronic'@'%';\""
#lxc exec Database -- sh -c "mysql -u root -e \"GRANT ALL privileges ON `MyDB`.* TO 'chronic'@'%';\""
#lxc exec Database -- sh -c "mysql -u root -e \"SET PASSWORD FOR 'root'@'localhost' = PASSWORD('321TestForRoot321');\""
lxc exec Database -- sh -c "mysql -u root -e \"FLUSH PRIVILEGES;\""
