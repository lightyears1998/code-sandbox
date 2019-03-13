# Docker范例

## 在Docker中安装Wordpress

1. 拉取MariaDB镜像

    ```bash
    docker search mariadb
    docker pull mariadb
    ```

2. 启动MariaDB

    ```bash
    docker run --name wordpress-db -e MYSQL_ROOT_PASSWORD=my_password -d mariadb
    ```

3. 运行Wordpress，将其连接到MariaDB，并连接宿主机8080端口

    ```bash
    docker run --name wordpress-blog --link wordpress-db -p 8080:80 -d -e WORDPRESS_DB_HOST=wordpress-db:3306 -e WORDPRESS_DB_PASSWORD=my_password wordpress
    ```
