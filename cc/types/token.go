package types

type Token struct {
	Type string
	Attr struct{}
}

type Lexer interface {
	GetNextToken() (Token, error)
}
