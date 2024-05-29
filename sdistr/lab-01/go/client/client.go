package main

import (
	"bufio"
	"flag"
	"fmt"
	"net"
	"os"
)

func main() {
	port := flag.Int("port", 12345, "port to listen on")
	host := flag.String("host", "localhost", "host to listen on")

	pong(*host, *port)
	// baseTCClient(*host, *port)
}
func pong(host string, port int) {
	addr := fmt.Sprintf("%s:%d", host, port)
	fmt.Println("Dialing", addr)

	conn, err := net.Dial("tcp", addr)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Printf("Connected to %s\n", addr)

	defer conn.Close()
	terminalReader := bufio.NewReader(os.Stdin)

	for {
		fmt.Print("Enter text: ")
		text, _ := terminalReader.ReadString('\n')
		conn.Write([]byte(text))
		if text == "SAIR\n" {
			break
		}

		buffer := make([]byte, 1024)
		n, err := conn.Read(buffer)
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Println("Recebido: ", string(buffer[:n]))
	}
}
func baseTCClient(host string, port int) {
	addr := fmt.Sprintf("%s:%d", host, port)
	conn, err := net.Dial("tcp", addr)

	if err != nil {
		fmt.Println(err)
		return
	}
	defer conn.Close()

	buffer := make([]byte, 1024)
	n, err := conn.Read(buffer)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("Recebido: ", string(buffer[:n]))
}
