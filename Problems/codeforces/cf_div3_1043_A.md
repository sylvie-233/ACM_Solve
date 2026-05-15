# A - Homework

简单模拟

```go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func readString() string {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

// 读取一行并拆分为字符串数组
func readLine() []string {
	line := readString()
	return strings.Split(line, " ")
}

// 读取一个整数
func readInt() int {
	line := readString()
	val, _ := strconv.Atoi(line)
	return val
}


func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		readInt()
		a := readString()
		m := readInt()
		b := readString()
		c := readString()
		for i := 0; i < m; i++ {
			if c[i] == 'D' {
				a = a + string(b[i])
			} else {
				a = string(b[i]) + a
			}
		}
		fmt.Fprintln(out, a)
		t--
	}
}
```