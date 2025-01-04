#!/bin/sh

# SQL_DATABASE="${SQL_DATABASE:-wordpress}"
# SQL_USER="${SQL_USER:-wordpressuser}"
# SQL_PASSWORD="${SQL_PASSWORD:-wordpresspassword}"
# SQL_ROOT_PASSWORD="${SQL_ROOT_PASSWORD:-rootpassword}"

if [ ! -f "/var/lib/mysql/maria_db_config_ok" ]; then
    echo "maria_db_config_ok does not exist. Setup Mariadb for Wordpress..."

    # service mariadb start;
    mariadbd-safe &
    # Loop until MariaDB service is running
    while ! mariadb-admin ping --silent; do
        echo "mariadb is not yet up. Checking again in 2 seconds..."
        sleep 2
    done

    # Once the service is up
    echo "mariadb is now running. Create DB and users."

    mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
    mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
    mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
    mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"    
    echo "User and database created. Flushing privileges."
    mysql -uroot -p$SQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
    echo "Privileges flushed. Shutting down the database."    
    mariadb-admin -u root -p"${SQL_ROOT_PASSWORD}" shutdown  
    echo "MariaDB configuration is complete. Database shutdown started. Checking if the database is down..."
    
    while mariadb-admin ping --silent; do
            echo "mariadb is still running. Checking again in 2 seconds..."
        sleep 2
    done
   
    touch /var/lib/mysql/maria_db_config_ok   
    echo "MariaDB setup is complete. Restart Database as PID 1."
else
    echo "Maria_db_config_ok exists, so setup was done earlier. Simply start the database."
fi 

exec mariadbd
