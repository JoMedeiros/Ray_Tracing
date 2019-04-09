def Settings( **kwargs ):
  return {
    'flags': [ '-x', 'c++', '-Wall', '-Wextra', '-Werror', '-Iinclude', '-Llib', '-lyaml-cpp', '-std=c++17'],
  }

