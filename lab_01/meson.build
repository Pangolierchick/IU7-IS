project('lab_04', ['cpp'], default_options: ['cpp_std=c++17'])

i = include_directories('./src')

exe = executable('main.out',
[
  './src/main.cpp',
  './src/rotor/rotor.cpp',
  './src/enigma/enigma.cpp',
  './src/coder/coder.cpp',
  './src/io/io.cpp'
],
cpp_args : ['-Wall', '-Wextra', '-O3'])
