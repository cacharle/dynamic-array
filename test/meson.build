test_sources = files(
  'test_dynarray.c',
)
cc = meson.get_compiler('c')
criterion_dep = cc.find_library('criterion', required : true)
deps = [criterion_dep]
c_args = []
# if host_machine.system() == 'linux'
#   gcov_dep = cc.find_library('gcov', required : true)
#   deps += [gcov_dep]
#   c_args = ['--coverage']
# endif
test_exec = executable(
  'test_criterion',
  sources + test_sources,
  # default_options : ['debug'],
  c_args : c_args,
  dependencies : deps,
  include_directories : include_dir
)
test('test', test_exec)
