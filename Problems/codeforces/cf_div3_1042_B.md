# B - Alternating Series

简单模拟

```go
func solve(n int) []int {
	var ans []int
	cnt := n / 2
	if n%2 == 1 {
		for cnt > 0 {
			ans = append(ans, -1)
			ans = append(ans, 3)
			cnt--
		}
		ans = append(ans, -1)
	} else {
		cnt--
		for cnt > 0 {
			ans = append(ans, -1)
			ans = append(ans, 3)
			cnt--
		}
		ans = append(ans, -1)
		ans = append(ans, 2)
	}
	return ans
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		n := readInt()
		writeInts(solve(n))
		t--
	}
}
```