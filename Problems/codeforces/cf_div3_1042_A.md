# A - Lever

简单计算

```go
func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		n := readInt()
		a := readInts()
		b := readInts()
		sum := 1
		for i := 0; i < n; i++ {
			if a[i] > b[i] {
				sum += a[i] - b[i]
			}
		}
		fmt.Fprintln(out, sum)
		t--
	}
}
```