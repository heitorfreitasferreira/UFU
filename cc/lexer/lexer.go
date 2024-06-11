package lexer

import "github.com/heitorfreitasferreira/UFU/cc/types"

type mainLexer struct {
	buffer      [][]rune
	bufferIndex int
	startIndex  int
	endIndex    int
}

func (l *mainLexer) prepareFile(path string) {

}
func (l *mainLexer) loadNextChunck() {

}
func InitLexer() types.Lexer {
	return mainLexer{}
}

func (l *mainLexer) GetNextToken() (types.Token, error) {

}
