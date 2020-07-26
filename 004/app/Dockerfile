FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update
RUN apt-get install apache2 -y

WORKDIR /works
# enable cgi link
RUN ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load


RUN cat /etc/apache2/mods-available/mime.conf | sed -e "s/#[ ]*AddHandler cgi-script/AddHandler cgi-script/g" > mime.conf 
RUN cp mime.conf /etc/apache2/mods-available/mime.conf 
RUN cat /etc/apache2/sites-available/000-default.conf | sed -e "s/#[ ]*Include conf-available\/serve-cgi-bin.conf/Include conf-available\/serve-cgi-bin.conf/g" > 000-default.conf 
RUN cp 000-default.conf /etc/apache2/sites-available/000-default.conf 
RUN mkdir /var/run/apache2/
RUN mv /bin/sh /bin/sh_tmp && ln -s /bin/bash /bin/sh
RUN source /etc/apache2/envvars 
RUN rm /bin/sh && mv /bin/sh_tmp /bin/sh
RUN a2enmod cgid


# source /etc/apache2/envvars 
ENV APACHE_RUN_USER=www-data
ENV APACHE_RUN_GROUP=www-data
ENV APACHE_PID_FILE=/var/run/apache2/apache2.pid
ENV APACHE_RUN_DIR=/var/run/apache2
ENV  APACHE_LOCK_DIR=/var/lock/apache2
ENV APACHE_LOG_DIR=/var/log/apache2
ENV LANG=C

# for test clang
RUN apt-get install -y build-essential


# install code-server
WORKDIR /works
RUN apt-get update
RUN apt-get install -y curl
RUN curl -sSOL https://github.com/cdr/code-server/releases/download/v3.4.1/code-server_3.4.1_amd64.deb
RUN dpkg -i code-server_3.4.1_amd64.deb

# install mysql and sqlite3
RUN apt-get install -y mysql-server mysql-client
RUN apt-get install -y libmysqlclient-dev
RUN apt-get install -y sqlite3
RUN apt-get install -y libsqlite3-dev



# install Dart
RUN apt-get update
RUN apt-get install -y wget gnupg1
RUN apt-get install apt-transport-https
RUN sh -c 'wget -qO- https://dl-ssl.google.com/linux/linux_signing_key.pub | apt-key add -'
RUN sh -c 'wget -qO- https://storage.googleapis.com/download.dartlang.org/linux/debian/dart_stable.list > /etc/apt/sources.list.d/dart_stable.list'
RUN apt-get update
RUN apt-get -y install dart

ENV PATH=${PATH}:/lib/dart/bin
ENV PATH="${PATH}:/root/.pub-cache/bin"

## install vscode plugin
RUN code-server --install-extension Dart-Code.dart-code
RUN code-server --install-extension ms-vscode.cpptools
RUN code-server --install-extension ms-vscode.cmake-tools



# Apache Setting 2
RUN cat /etc/apache2/sites-available/000-default.conf | sed -e "s/\/var\/www\/html/\/app\/www\/html/g" > 000-default.conf 
RUN cp 000-default.conf /etc/apache2/sites-available/000-default.conf 

RUN cat /etc/apache2/conf-available/serve-cgi-bin.conf | sed -e "s/\/usr\/lib\/cgi-bin/\/app\/www\/cgi/g" > serve-cgi-bin.conf
RUN cp serve-cgi-bin.conf /etc/apache2/conf-available/serve-cgi-bin.conf

RUN cat /etc/apache2/apache2.conf | sed -e "s/\/var\/www/\/app\/www/g" > apache2.conf
RUN cp apache2.conf /etc/apache2/apache2.conf

