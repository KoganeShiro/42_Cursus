# Dockerfile Nginx

# Base image
FROM alpine:3.21

# Update and upgrade the system, Install nginx and openssl, Clean the cache
RUN apk update && \
    apk upgrade && \
    apk add --no-cache nginx openssl curl vim busybox-extras

# Create a user and group for nginx if they do not already exist
RUN addgroup -S nginx || true && adduser -S -G nginx nginx || true

# Copy the script to generate the SSL certificate and start the nginx service
COPY ./tools/create_ssl_and_start_nginx.sh /create_ssl_and_start_nginx.sh
RUN chmod +x /create_ssl_and_start_nginx.sh

# Copy the nginx conf file into the container
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# Create various directories for nginx and set appropriate permissions
RUN mkdir -p /run /var/cache/nginx /var/www/html && \
    chown -R nginx:nginx /etc/nginx /var/lib/nginx /var/log/nginx /var/cache/nginx /var/www/html /run /etc/ssl && \
    chmod 755 /var/www/html

# Set the user to run Nginx as
USER nginx

# Start the nginx service
ENTRYPOINT ["/create_ssl_and_start_nginx.sh"]
# ENTRYPOINT ["sh"]

# Expose port 443
EXPOSE 443


#docker build -t nginx-image .
#docker run --name nginx-container -d -p 8080:80 nginx-image
#docker run --name nginx-container -it nginx-image
#docker logs nginx-container
#docker exec -it nginx-container sh