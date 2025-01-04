#!/bin/sh

# If SSL Cert does not exist, create it
if [ ! -f "/etc/ssl/certs/nginx-inception.crt" ]; then

    mkdir -p /etc/ssl/private
    mkdir -p /etc/ssl/certs

    # Create a self-signed certificate; default to localhost if CERTIFICAT is not set
    CERT_SUBJECT="${CERTIFICAT:-/CN=localhost}"
    SSERVERNAME="${SERVERNAME:-localhost}"

    echo "Creating self-signed certificate for $CERT_SUBJECT"
    echo "Change Servername to $SSERVERNAME"

    openssl req -x509 -nodes -out /etc/ssl/certs/nginx-inception.crt -keyout /etc/ssl/private/nginx-inception.key -subj "$CERT_SUBJECT"

    # Adapt the nginx configuration to use the real server name from env
    sed -i "s/server_name localhost;/server_name localhost $SSERVERNAME;/" /etc/nginx/nginx.conf

else
    echo "Certificate already exists in /etc/ssl/certs/nginx-inception.crt"
fi

# Start nginx in the foreground
exec nginx -g "daemon off;"
