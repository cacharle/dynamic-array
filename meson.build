project(
  'dynamic-array',
  'c',
  default_options : ['c_std=c99'],
  # c_args : ['Wall', 'Wextra']
)
# b_coverage=true
add_global_arguments('-g', language : 'c')
# if host_machine.system() == 'linux'
#   add_global_arguments('--coverage', language : 'c')
# endif
include_dir = include_directories('src')
subdir('src')
subdir('test')
executable('example', sources + ['example.c'], include_directories : include_dir)
