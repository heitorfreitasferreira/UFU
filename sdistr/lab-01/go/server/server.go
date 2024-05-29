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

	ping(*host, *port)
	// baseTC(*host, *port)
}

func baseTC(host string, port int) {
	addr := fmt.Sprintf("%s:%d", host, port)
	l, err := net.Listen("tcp", addr)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer l.Close()
	fmt.Printf("Waiting for conn on %s\n", addr)

	for {
		conn, err := l.Accept()
		if err != nil {
			fmt.Println(err)
			return
		}

		go func(c net.Conn) {
			// Echo all incoming data.
			fmt.Println("Got connection from", c.RemoteAddr()) // Shut down the connection.
			c.Write([]byte("Thank you for connecting"))
			// c.Close()
		}(conn)
	}
}

func ping(host string, port int) {
	addr := fmt.Sprintf("%s:%d", host, port)
	l, err := net.Listen("tcp", addr)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer l.Close()
	fmt.Printf("Waiting for conn on %s\n", addr)

	for {
		conn, err := l.Accept()
		if err != nil {
			fmt.Println(err)
			return
		}
		go handleConnection(conn)

	}
}

func handleConnection(conn net.Conn) {
	defer conn.Close()
	terminalReader := bufio.NewReader(os.Stdin)
	for {
		buf := make([]byte, 1024)
		n, err := conn.Read(buf)
		if err != nil {
			fmt.Println(err)
			return
		}
		message := string(buf[:n])
		if message == "SAIR" {
			break
		}

		fmt.Printf("[%s] sent: %s\n", conn.RemoteAddr(), message)
		fmt.Printf("send to [%s]: ", conn.RemoteAddr())
		text, _ := terminalReader.ReadString('\n')

		conn.Write([]byte(text))
	}
}
