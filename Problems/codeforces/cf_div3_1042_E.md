# E - Adjacent XOR

简单计算

```go
func solve(n int, a, b []int) bool {
	if a[n-1] != b[n-1] {
		return false
	}
	for i := n - 2; i >= 0; i-- {
		if a[i] == b[i] || a[i]^a[i+1] == b[i] || a[i]^b[i+1] == b[i] {
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
		n := readInt()
		a := readInts()
		b := readInts()
		if solve(n, a, b) {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
		t--
	}
}
```