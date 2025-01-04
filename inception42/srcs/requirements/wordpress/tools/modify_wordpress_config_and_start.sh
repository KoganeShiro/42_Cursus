#!/bin/sh

#Set the default values
SQL_HOSTNAME="${SQL_HOSTNAME: mariadb}"

# Define the file to rename
# SAMPLE_CONFIG="/var/www/wordpress/wp-config-sample.php"
WP_CONFIG="/var/www/wordpress/wp-config.php"

# Check if the config file exists (means WP was already configured)
if [ ! -f "/var/www/wordpress/wp_config_ok" ]; then
    echo "/var/www/wordpress/wp_config_ok does not exist. Proceeding with creation process."

    wp-cli.phar config create	--dbname=$SQL_DATABASE \
								--dbuser=$SQL_USER \
								--dbpass=$SQL_PASSWORD \
								--dbhost=$SQL_HOSTNAME:3306 \
                                --path='/var/www/wordpress'

    wp-cli.phar core install    --url=$SERVERNAME \
                                --title=$WP_TITLE \
                                --admin_user=$WP_ADMIN_NAME \
                                --admin_password=$WP_ADMIN_PASSWORD \
                                --admin_email=$WP_ADMIN_EMAIL \
                                --path='/var/www/wordpress'

    wp-cli.phar user create     $WP_USERNAME $WP_EMAIL \
                                --role=author \
                                --user_pass=$WP_PASSWORD \
                                --path='/var/www/wordpress'

    chmod -R 775 /var/www/wordpress/wp-content/uploads
    chmod -R 775 /var/www/wordpress/wp-content/plugins
    chmod -R 775 /var/www/wordpress/wp-content/themes
    # Create witness file to show that config was done
    touch /var/www/wordpress/wp_config_ok

else
    echo "/var/www/wordpress/wp_config_ok exists. Skipping creation process."
fi

# Start php in the foreground
exec /usr/sbin/php-fpm83 -F
