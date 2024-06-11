package main

import "github.com/zalgonoise/lex"

type TextToken int

const (
	TokenEOF TextToken = iota
	TokenError
	TokenIDENT
	TokenLBRACE
	TokenRBRACE
	TokenLPAREN
	TokenRPAREN
	TokenRELOP
)

func relopState[C TextToken, T rune](l lex.Lexer[C, T]) lex.StateFn[C, T] {
	switch l.Next() {
	case'=':
		
	}
	}
}
func main() {

}
