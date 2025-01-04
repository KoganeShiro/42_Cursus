
# Project variables
PROJECT_NAME = Inception
DOCKER_COMPOSE = docker compose
DOCKER_COMPOSE_FILE = ./srcs/docker-compose.yml
DATA_FOLDER = /home/cejin/data

# Helper variables
BUILD_TARGET ?= mariadb  # Default service target for Docker Compose
DOCKER = docker


# Default target
.PHONY: help
help:
	@echo "Inception Maker should run in a root shell"
	@echo "Usage: make [target]"
	@echo "Available targets:"
	@echo "  build          Build the Docker images"
	@echo "  up             Start services in detached mode"
	@echo "  down           Stop and remove containers, networks, and volumes"
	@echo "  stop           Stop containers"
	@echo "  restart        Restart the services"
	@echo "  logs           View logs from services"
	@echo "  exec           Run a shell inside the running mariadb container"
	@echo "  clean          Remove all unused Docker resources"
	@echo "  fclean         Remove all Docker resources and clean contents of volumes."
	@echo "  -----------------"
	@echo "A file /srcs/.env should exist containing the following Variables:"
	@echo "CERTIFICAT="
	@echo "SERVERNAME="
	@echo "SQL_HOSTNAME="
	@echo "SQL_DATABASE="
	@echo "SQL_USER="
	@echo "SQL_PASSWORD="
	@echo "SQL_ROOT_PASSWORD="
	@echo "WP_USERNAME="
	@echo "WP_PASSWORD="
	@echo "WP_EMAIL="
	@echo "WP_ADMIN_NAME="
	@echo "WP_ADMIN_PASSWORD="
	@echo "WP_ADMIN_EMAIL="
	@echo "WP_TITLE="
	@echo "LOGIN="

# Build the Docker images
.PHONY: build
build:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) build

# Start the services in detached mode
.PHONY: up
up: create_folders
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up -d

# Stop and remove services
.PHONY: down
down:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down

# Stop services
.PHONY: stop
stop:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) stop

# Restart the services
.PHONY: restart
restart: down up

# View logs
.PHONY: logs
logs:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) logs -f

# Open a shell in the main app container
.PHONY: exec
exec:
	$(DOCKER) exec -it --user=root nginx /bin/sh

# Clean unused Docker resources
.PHONY: clean
clean: down
	$(DOCKER) system prune -af

# Clean unused Docker resources
.PHONY: fclean
fclean: down clean
	$(DOCKER) system prune -af --volumes
	@if [ -n "$(shell docker volume ls -q)" ]; then \
		echo "Removing unused volumes..."; \
		docker volume ls -q | xargs docker volume rm; \
	else \
		echo "No volumes to prune."; \
	fi	
	rm -Rf $(DATA_FOLDER)
	

# Clean Volumes
.PHONY: clean_volumes
clean_volumes:
	rm -Rf $(DATA_FOLDER)
	

# Create Folders for Volumes
.PHONY: create_folders
create_folders:	
	mkdir -p $(DATA_FOLDER)
	mkdir -p $(DATA_FOLDER)/mariadb
	mkdir -p $(DATA_FOLDER)/wordpress
