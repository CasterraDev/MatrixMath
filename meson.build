project('static lib', 'c')
lib = static_library('matrixMath', 'matrix.c')

exe = executable('tests', 'tests.c',
  install : true, link_with : lib)

test('basic', exe)
