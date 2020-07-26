
# Memo

```
$ docker-compose build
$ docker-compose up -d
```

open http://127.0.0.1:8443 to open vscode at browser
and in vscode,
```
$ apache2
$ cd /app/www/cgi
$ gcc hello.c -o hello.cgi
$ dart2native hello_dart.dart -o hello_daet.cgi
```

open http://127.0.0.1:8080/ then, open ./app/www/index.html

open http://127.0.0.1:8080/cgi-bin/hello.cgi then, open ./app/cgi/hello.cgi


open http://127.0.0.1:8080/cgi-bin/hello_dart.cgi then, open ./app/cgi/hello_dart.cgi 