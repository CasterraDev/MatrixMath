project('proj', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

exe = executable('proj', 'proj.c', 'hello.c',
  install : true)

test('basic', exe)
