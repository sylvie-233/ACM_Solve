# C1 - The Cunning Seller (easy version)

简单数学计算：进制转换


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

// 读取一个整数
func readInt() int {
	line := readString()
	val, _ := strconv.Atoi(line)
	return val
}

func readInt64() int64 {
	line := readString()
	val, _ := strconv.ParseInt(line, 10, 64)
	return val
}

func writeInt64s(arr []int64) {
	strArr := make([]string, len(arr))
	for i, v := range arr {
		strArr[i] = strconv.FormatInt(v, 10) // int64 -> string
	}
	fmt.Fprintln(out, strings.Join(strArr, " ")) // 10 20 30 40
}

func pow(a, b int64) int64 {
	res := int64(1)
	for b > 0 {
		if b&1 == 1 { // 当前位为1
			res *= a
		}
		a *= a  // a = a^2
		b >>= 1 // b = b/2
	}
	return res
}

func calc(x int) int64 {
	if x == 0 {
		return 3
	}
	return pow(int64(3), int64(x+1)) + int64(x)*pow(int64(3), int64(x-1))
}

func solve(x int64) int64 {
	var res int64 = 0
	var base int = 0
	for x > 0 {
		c := x % 3
		if c != 0 {
			res += int64(c) * calc(base)
		}
		base += 1
		x /= 3
	}
	return res
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		n := readInt64()
		x := solve(n)
		fmt.Fprintln(out, x)
		t--
	}
}
```