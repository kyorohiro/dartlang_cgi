# C言語 と Dart で CGI

昨今は動的なホームページを作成する場合には、「VPS で Linux インスタンスを立ち上げたり」、「Serverless の フレームワークを利用してコンテンツを配信したり」、「K8Sなどを利用してContainer に落としたり」するのが最近のトレンドだと思います。

が、レンタルサーバーを借りてCGIを利用して動的コンテンツを配信するのが一般的でした。

CGIについて解説して行きます。

## C言語とDart言語からCGIを利用

また、CGIと言えば、Perl や PHP などが、良く使われますが、
ここでは、C言語とDart言語を対象とします。

Dart言語 で CGI に利用した話が、DuckDuckGoしてもGoogleしても皆無だったからです。

もちろん、皆無だった理由はクラシックな技術で、
今後、利用される事もなかったからでしょう

## CGIはシンプルで容易

2004-2006年くらいでしょうか? PHP が 広まり、多くのサービスがCGIで作られました。
非エンジニアの人も多く。そんな非エンジニアの方々でも
全体像を把握出来、お金を稼ぐようなサービスが作られて行きました。

昨今の、React Vue Flutter や Firebase た Lambda など　Serverless と比較して
習得が容易だったからだと考えています。


# CGI とは

CGIは、Common Gateway Interface の略です。
https://en.wikipedia.org/wiki/Common_Gateway_Interface
https://tools.ietf.org/html/rfc3875

特にサーバーと外部のプログラムの間での、やりとり方法を決めたものです。
今時のInterface と違い 超シンプルです。


## サーバーからアプリを起動して、実行結果をもらう

CGIでは、サーバーからパラメータを指定してアプリを起動します。
そのアプリが出力する標準出力をを返り値としてもらう。

具体的に見てみましょう。



### Hello,World!! と表示するアプリ
```:hello.c
// hello.c
// gcc hello.c -o hello.cgi
#include<stdio.h>

int main(int argc, char* argv[]) {
    printf("Content-type: text/html\n\n");
    printf("Hello,World!!\n");
    return 0;
}

```

という、hello.cgi という名前のアプリがあるとします。
このアプリは、`./hello.cgi`  とコマンドを入力すると、
"""
Content-type: text/html

Hello,World!!
"""
と、コンソールにも文字列を表示するだけのアプリです。

### Hello,World!! と表示するページになる

ブラウザーから、 "http://example.com/hello.cgi" を呼び出すと、
"Hello,World!!" とブラウザーに表示されます。


## 実際に動かしてみよう

Docker 環境を用意しました。
細かな設定とかはDockerファイルを参照してください!!


### Container を起動
```
$ git clone https://github.com/kyorohiro/dartlang_cgi.git
$ cd ./dartlang_cgi/001
$ docker-compose build
$ docker-compose up -d
```

#### VSCodeを起動

ブラウザーでDocker Container の 中の VSCode を開く
http://127.0.0.1:8443 
※ 127.0.0.1 は　Dockerの環境依存です。


#### vscode の中で、Apacheサーバーの立ち上げ

```
$ apache2
```


#### cgiをビルド

```
$ cd /app/www/cgi
$ gcc hello.c -o hello.cgi
$ dart2native hello_dart.dart -o hello_daet.cgi
```

#### 動作確認

http://127.0.0.1:8080/ を開くと、 ./app/www/index.html　が表示されます

http://127.0.0.1:8080/cgi-bin/hello.cgi を開くと。./app/cgi/hello.cgi の実行結果が返ります

http://127.0.0.1:8080/cgi-bin/hello_dart.cgi を開くと、 ./app/cgi/hello_dart.cgi の実行結果が返ります


# 補足
Dart は dart2native を利用する事で、Nativeにコンパイル出来ます。
今回はそれを使用しています。

```
main(List<String> args) {
  print("Content-type: text/html\n\n");
  print("Hello,World From Dart!!\n");
  return 0;
}
```


# 次回

GET や POST や Cookie や
DB を扱ってみます。


