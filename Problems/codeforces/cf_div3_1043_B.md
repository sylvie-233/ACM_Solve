# B - The Secret Number

简单数学计算


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

func solve(x int64) []int64 {
	var res []int64
	base := int64(1e18)
	for base > 1 {
		v := base + 1
		if x%v == 0 {
			res = append(res, x/v)
		}
		base /= 10
	}
	return res
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		n := readInt64()
		x := solve(n)
		fmt.Fprintln(out, len(x))
		if len(x) != 0 {
			writeInt64s(x)
		}
		t--
	}
}
```