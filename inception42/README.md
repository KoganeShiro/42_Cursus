# Inception

Learn what docker is and create from scratch a docker compose with NGINX, Wordpress and MariaDB containers.

## Table of Contents

- [Introduction](#introduction)
- [Step by Step](#step-by-step)
    - [What is a Docker?](#what-is-a-docker)
    - [What is a Dockerfile?](#what-is-a-dockerfile)
    - [What is a Docker Image?](#what-is-a-docker-image)
    - [How Docker and Docker Compose work?](#how-docker-and-docker-compose-work)
    - [Difference between a Docker image used with Docker Compose and without Docker Compose](#difference-between-a-docker-image-used-with-docker-compose-and-without-docker-compose)
    - [The benefit of Docker compared to VMs](#the-benefit-of-docker-compared-to-vms)
    - [The pertinence of the directory structure required for this project](#the-pertinence-of-the-directory-structure-required-for-this-project)
    - [What is NGINX?](#what-is-nginx)
    - [What is SSL/TLS certificate?](#what-is-ssltls-certificate)
    - [Installation of Wordpress by Wordpress CLI](#installation-of-wordpress-by-wordpress-cli)
    - [How Docker Network works?](#how-docker-network-works)
    - [What is a Docker volume?](#what-is-a-docker-volume)
    - [What is MariaDB?](#what-is-mariadb)
    - [How to log into the database?](#how-to-log-into-the-database)

## Introduction

Inception is a project that aims to teach the basics of Docker and Docker Compose by creating a multi-container application from scratch. The application will include NGINX, Wordpress, and MariaDB containers, demonstrating how these technologies can work together to create a functional web application.

## Step by Step

### What is a Docker?

Docker is a platform that allows developers to automate the deployment of applications inside lightweight, portable containers. Containers include everything needed to run an application, such as the code, runtime, libraries, and system tools.

### What is a Dockerfile?

A Dockerfile is a text document that contains all the commands a user could call on the command line to assemble an image. Using a Dockerfile, you can create a custom Docker image by specifying the operating system, software packages, and configuration files needed for your application.

### What is a Docker Image?

A Docker image is a lightweight, standalone, and executable software package that includes everything needed to run a piece of software, including the code, runtime, libraries, environment variables, and configuration files.

### How Docker and Docker Compose work?

Docker allows you to create, deploy, and run applications in containers. Docker Compose is a tool for defining and running multi-container Docker applications. With Docker Compose, you can use a YAML file to configure your application's services, networks, and volumes, and then use a single command to start all the services.

### Difference between a Docker image used with Docker Compose and without Docker Compose

When using Docker Compose, you define multiple services in a single YAML file, which allows you to manage and orchestrate multiple containers as a single application. Without Docker Compose, you would need to manually start and manage each container individually.

### The benefit of Docker compared to VMs

Docker containers are more lightweight and efficient than virtual machines (VMs) because they share the host system's kernel and resources. This results in faster startup times, lower resource usage, and easier scalability compared to VMs.

### The pertinence of the directory structure required for this project

The directory structure for this project is designed to organize the different components of the application, such as Dockerfiles, configuration files, and source code, in a way that makes it easy to manage and maintain.

### What is NGINX?

NGINX is a high-performance web server and reverse proxy server that is commonly used to serve static content, handle incoming web traffic, and load balance requests across multiple servers.

### What is SSL/TLS certificate?

An SSL/TLS certificate is a digital certificate that provides authentication for a website and enables an encrypted connection. SSL/TLS certificates are used to secure data transmitted between a web server and a client, ensuring privacy and data integrity.

### Installation of Wordpress by Wordpress CLI

The Wordpress Command Line Interface (CLI) is a tool that allows you to manage your Wordpress installation from the command line. You can use the Wordpress CLI to install and configure Wordpress, manage themes and plugins, and perform other administrative tasks.

### How Docker Network works?

Docker Network allows containers to communicate with each other and with external networks. Docker provides several network drivers to create different types of networks for your containers:

- **Bridge**: The default network driver. It creates a private internal network on the host so that containers on the same bridge network can communicate with each other.
- **Host**: Removes network isolation between the container and the Docker host, and uses the host's networking directly.
- **Overlay**: Enables communication between containers on different Docker hosts. It is used for multi-host networking and is commonly used with Docker Swarm.

In this project, we are using a network called `inception` using `bridge` driver. We put all the container (nginx, mariadb, wordpress) in the same network so they can communicate with each other but keeping them isolated from other networks.

### What is a Docker volume?

A Docker volume is a persistent storage mechanism that allows you to store data outside of the container's filesystem. Volumes are used to share data between containers and to persist data across container restarts and updates.

### What is MariaDB?

MariaDB is an open-source relational database management system (RDBMS) that is a fork of MySQL. It is designed to be highly compatible with MySQL, providing a drop-in replacement with additional features and performance improvements.

### How to log into the database?

To log into the MariaDB database, you can use the `mysql` command-line client or a graphical database management tool. Here is the command to log in using the `mysql` client:

```sh
mysql -h <hostname> -u <username> -p
```
Then you have to enter your password.

Once logged into the MariaDB database, you can list all the databases using the following SQL command:

```sql
SHOW DATABASES;
```
This command will display a list of all databases available on the MariaDB server.

To see the content of a specific database, you need to select the database first and then list its tables. Use the following commands:

```sql
USE <database_name>;
SHOW TABLES;
```

To see the content of a specific table, use the following command:

```sql
SELECT * FROM <table_name>;
```
