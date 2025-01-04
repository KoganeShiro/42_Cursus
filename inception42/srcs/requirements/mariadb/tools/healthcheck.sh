
#!/bin/sh

echo "MariaDB health check..."

# Check if SQL_ROOT_PASSWORD is set
if [ -z "$SQL_ROOT_PASSWORD" ]; then
  echo "Error: SQL_ROOT_PASSWORD environment variable is not set."
  exit 1
fi

if ! mysql -u root -p"$SQL_ROOT_PASSWORD" -e "SELECT 1;" > /dev/null 2>&1; then
  echo "MariaDB is not responding."
  exit 1
fi

# Check if the file 'maria_db_config_ok' exists
if [ ! -f "/var/lib/mysql/maria_db_config_ok" ]; then
  echo "File 'maria_db_config_ok' not found."
  exit 1
fi

echo "Health check passed!"
exit 0
