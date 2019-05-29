def Settings( **kwargs ):
  return {
    'flags': [ '-x', 'c++', '-Wall', '-Wextra', '-Werror', 
        '-Iinclude,include/integrators', '-Llib', '-lyaml-cpp', '-std=c++17'],
  }

