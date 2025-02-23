project('shared lib', 'c')
lib = library('matrixMath', 'matrix.c')

exe = executable('tests', 'tests.c',
  install : true, link_with : lib)

test('basic', exe)
