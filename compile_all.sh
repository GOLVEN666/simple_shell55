#!/bin/bash

# Compile each source file into an executable
for file in atoi.c builtin.c errors1.c exits.c getinfo.c history.c lists.c memory.c shell.h string1.c tokenizer.c builtin1.c environ.c errors.c getenv.c getLine.c lists1.c main.c parser.c realloc.c shell_loop.c string.c vars.c; do
  # Extract the base name of the source file (without extension)
  base_name="${file%.c}"
  # Compile and create the executable
  if gcc -o "${base_name}_program" "$file" -lm; then
    echo "Compiled $file successfully as ${base_name}_program"
  else
    echo "Compilation of $file failed"
  fi
done
