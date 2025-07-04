# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../..

ARGS = "2 5 2025"

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/DateProblem.c \
  test/DateTests.c \
  test/test_runners/TestDate_Runner.c \
  test/test_runners/all_tests.c

SRC_FILES2=\
  src/DateProblem.c \
  test/DateTests.c \
  test/test_runners/TestDate_Runner.c \
  test/test_runners/all_tests.c

INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=

all: clean compile run

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction --inconclusive --force $(INC_DIRS) $(SRC_FILES1)

valgrind: # aparece erro quando compilo "make valgrind" porem se compilo sem makefile por linha de comando, funciona (?????)
	$(C_COMPILER) -g -Wall -Wfatal-errors $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET1) -v

sanitizer:
	$(C_COMPILER) -g -Wall -Wfatal-errors -fsanitize=address $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1) -verbose

compile:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)	

run:
	- ./$(TARGET1) -v

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: compile
