import 'package:mysql1/mysql1.dart' as mysql1;

main(List<String> args) async {
    final conn = await mysql1.MySqlConnection.connect(
      mysql1.ConnectionSettings(host: 'mysqld', port: 3306, user: 'root', db: 'myapp', password: "passwd"));
    
    //
    print("[q] select * from apps\n");
    try {
      var results = await conn.query('select id, name from apps');
      for (var row in results) {
        print('  ${row[0]},${row[1]} ');
      }
    } catch(e) {
        print("err(2):${e}\n");
    }

    //
    print("[q] insert into apps(id,name)...\n");
    try {
      await conn.query("insert into apps(id,name) VALUES (2, 'dango') ");
    } catch(e) {
        print("err(2):${e}\n");
    }

    //
    print("[q] delete drom apps where id=2\n");
    try {
      await conn.query( "delete from apps where id=2 ");
    } catch(e) {
        print("err(2):${e}\n");
    }

    await conn.close();
}