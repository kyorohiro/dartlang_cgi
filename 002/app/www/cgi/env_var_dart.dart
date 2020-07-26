import 'dart:io' as io;

// dart2native env_var_dart.dart -o env_var_dart.cgi
main(List<String> args) {
  print("Content-type: text/html\n\n");
  print("\n");

  Map variables = io.Platform.environment;
  for(var key in variables.keys) {
    print("${key}:${variables[key]}<br>\n");
  }
  return 0;
}
