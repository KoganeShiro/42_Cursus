# Dockerfile Wordpress + php

# Base image
FROM alpine:3.21

# Update and install necessary packages including nginx, PHP, and MariaDB
RUN apk update && \
apk add --no-cache nginx openssl curl php php-fpm php-mysqli php-phar php-mbstring php-json php-session php-zlib php-curl php-xml php-zip mariadb-client vim

# Create www-data user and group if they do not exist
RUN addgroup -S www-data || true && adduser -S www-data -G www-data || true

# Download the WordPress archive and extract it
RUN curl -o /var/www/wordpress-6.7.1.tar.gz https://wordpress.org/wordpress-6.7.1.tar.gz && \
    tar -xzf /var/www/wordpress-6.7.1.tar.gz -C /var/www && \
    rm /var/www/wordpress-6.7.1.tar.gz

# Create the run directory for PHP
RUN mkdir -p /run/php

# Create directories and set permissions
RUN chown -R www-data:www-data /var/www/wordpress /run/php && \
    chmod -R 755 /var/www/wordpress

# Download wp-cli and set permissions
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp-cli.phar && \
    chmod +x /usr/local/bin/wp-cli.phar && \
    chown -R www-data:www-data /usr/local/bin/wp-cli.phar

# Copy the configuration file for PHP-FPM (ensure this path is correct)
COPY conf/www.conf /etc/php83/php-fpm.d/www.conf

# Copy the script to set up the WordPress configuration and start the services
COPY ./tools/modify_wordpress_config_and_start.sh /modify_wordpress_config_and_start.sh
RUN chown -R www-data:www-data /modify_wordpress_config_and_start.sh && \
    chmod +x /modify_wordpress_config_and_start.sh

# Set permissions for Log Directory
RUN chown -R www-data:www-data /var/log && \
    chmod 755 /var/log

# Set the user to run WordPress as www-data
USER www-data

# Start the WordPress script
ENTRYPOINT ["/modify_wordpress_config_and_start.sh"]

# ENTRYPOINT [ "sh" ]

# Expose port 9000 for PHP-FPM
EXPOSE 9000


#docker build -t wordpress-image .
#docker run --name wordpress-container -d wordpress-image
#docker logs wordpress-container
#docker exec -it wordpress-container sh