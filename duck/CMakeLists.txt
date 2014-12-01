cmake_minimum_required(VERSION 2.8)

include(FindSDL)
include(FindOpenGL)

add_custom_command(OUTPUT duck.c duck.h grammar.c grammar.h
  COMMAND ../bin/parser-generator ARGS --input ../parser-generator/grammar.txt --output ../duck/duck
  DEPENDS parser-generator
  COMMENT generate duck.c and duck.h
)

# duck
add_executable(duck
  main.c
  interpreter.c
  lexer.c
  parser.c
  grammar.c
  duck.c
  memory.c
  lib/library.c
  lib/stdduck.c
  lib/dmath.c
  lib/drand.c
)

# gduck
add_executable(gduck
  main.c
  interpreter.c
  lexer.c
  parser.c
  grammar.c
  duck.c
  memory.c
  lib/library.c
  lib/stdduck.c
  lib/SDLlib.c
  lib/dmath.c
  lib/drand.c
)

include_directories(../duck)

SET_TARGET_PROPERTIES(duck PROPERTIES COMPILE_FLAGS "-O2")
TARGET_LINK_LIBRARIES(duck -lm)
SET_TARGET_PROPERTIES(gduck PROPERTIES COMPILE_FLAGS "-D_GDUCK -D_LIB_SDL")
TARGET_LINK_LIBRARIES(gduck ${SDL_LIBRARY} ${OPENGL_LIBRARY} -lm)
