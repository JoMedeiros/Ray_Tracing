def Settings( **kwargs ):
  return {
    'flags': [ 
        '-x',
        'c++', 
        '-Wall', 
        '-Wextra', 
        '-Werror', 
        '-Iinclude',
        '-Iinclude/integrators',
        '-Iinclude/lights',
        '-Llib', 
        '-lyaml-cpp', 
        '-std=c++17'],
  }

