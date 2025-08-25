# C2 - The Cunning Seller (hard version)

简单数学计算 + 贪心

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

func readInt64s() []int64 {
	line := readString()
	fields := strings.Fields(line)
	res := make([]int64, len(fields))
	for i, f := range fields {
		res[i], _ = strconv.ParseInt(f, 10, 64)
	}
	return res
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

func solve(x, k int64) int64 {
	var arr []int64
	var res int64 = 0
	var cnt int64 = 0
	for x > 0 {
		c := x % 3
		if c != 0 {
			cnt += c
		}
		arr = append(arr, c)
		x /= 3
	}
	if cnt > k {
		return -1
	}

    // 贪心：从最高位开始降位
	p := len(arr) - 1
	for p > 0 && cnt < k {
		if arr[p] > 0 {
			if cnt+2*arr[p] <= k {
				cnt += arr[p] * 2
				arr[p-1] += arr[p] * 3
				arr[p] = 0
			} else {
				c := (k - cnt) / 2
				cnt += c * 2
				arr[p-1] += c * 3
				arr[p] -= c
				break
			}
		}
		p -= 1
	}
	for i := 0; i < len(arr); i++ {
		if arr[i] > 0 {
			res += calc(i) * arr[i]
		}
	}

	return res
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		nk := readInt64s()
		n, k := nk[0], nk[1]
		x := solve(n, k)
		fmt.Fprintln(out, x)
		t--
	}
}
```