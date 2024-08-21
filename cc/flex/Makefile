run : build
	./lexer
clean:
	rm -f lexer.c lexer lexer.h
build-flex:
	flex -DYY_DECL="Token * yylex()" main.lex
build: build-flex
	gcc lexer.c exp.c -o lexer
build-dev: build-flex
	zig cc -DDEBUG lexer.c exp.c -o lexer

PHONY: build-flex build run