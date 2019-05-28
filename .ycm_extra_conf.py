def Settings( **kwargs ):
  return {
    'flags': [ '-x', 'c++', '-Wall', '-Wextra', '-Werror', 
        '-I include -I include/integrators', '-Llib', '-lyaml-cpp', '-std=c++17'],
  }

