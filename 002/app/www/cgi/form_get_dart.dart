import 'dart:io' as io;
import 'dart:core' as core;
import 'dart:core';

main(List<String> args) {
  print("Content-type: text/html\n\n");
  print("<h1>QUERY_STRING!!</h1>\n");

  Map variables = io.Platform.environment;
  print("${variables['QUERY_STRING']}<br>\n");
  Map query_params = core.Uri.splitQueryString(variables['QUERY_STRING']);
  print("fname:${query_params['fname']}<br>\n");
  return 0;
}

