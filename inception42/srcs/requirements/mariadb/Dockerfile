# Dockerfile MariaDB

# Base image
FROM alpine:3.21

# Update and install necessary packages including MariaDB and OpenSSL
RUN apk update && \
    apk add --no-cache mariadb mariadb-client openssl curl vim

# Ensure ownership of MySQL data directory during build (if needed)
RUN mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql

# Copy the configuration file for MariaDB
COPY ./conf/50-server.cnf /etc/my.cnf.d/mariadb-server.cnf

# Copy the database creation script to the container
COPY ./tools/create_database.sh /create_database_and_start_mariadb.sh
RUN chmod +x /create_database_and_start_mariadb.sh

# Copy the healthcheck script
COPY ./tools/healthcheck.sh /healthcheck.sh
RUN chmod +x /healthcheck.sh

# Create necessary directories for MariaDB
RUN mkdir -p /run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld

# Initialize MariaDB database files (this step may vary based on your setup)
RUN mariadb-install-db --user=mysql --datadir=/var/lib/mysql

# Set the user to run MariaDB as mysql
USER mysql

# Start the MariaDB service using the provided script
ENTRYPOINT ["/create_database_and_start_mariadb.sh"]

# Expose port 3306 for MariaDB
EXPOSE 3306

#docker build -t mariadb-image .
#docker run --name mariadb-container -d mariadb-image
#docker logs mariadb-container
#docker exec -it mariadb-container sh