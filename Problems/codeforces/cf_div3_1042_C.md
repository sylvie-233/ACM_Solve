# C - Make it Equal

简单计算

```go
func solve(n, k int, a, b []int) bool {
	c := make(map[int]int)
	for i := 0; i < n; i++ {
		c[b[i]%k]++
	}
	for i := 0; i < n; i++ {
		t := a[i] % k
		if _, ok := c[t]; ok {
			c[t]--
			if c[t] == 0 {
				delete(c, t)
			}
			continue
		}
		if _, ok := c[k-t]; ok {
			c[k-t]--
			if c[k-t] == 0 {
				delete(c, k-t)
			}
			continue
		}
		return false
	}
	return true
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		nk := readInts()
		n := nk[0]
		k := nk[1]
		a := readInts()
		b := readInts()
		if solve(n, k, a, b) {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
		t--
	}
}
```