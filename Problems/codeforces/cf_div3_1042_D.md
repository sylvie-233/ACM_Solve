# D - Arboris Contractio

简单计算

```go
func solve(g [][]int, cnt []int, n int) int {
	cntOne := 0
	for i := 1; i <= n; i++ {
		if cnt[i] == 1 {
			cntOne++
		}
	}
	ans := cntOne
	for i := 1; i <= n; i++ {
		cntAdjOne := 0
		if cnt[i] == 1 {
			cntAdjOne++
		}
		for j := 0; j < len(g[i]); j++ {
			v := g[i][j]
			if cnt[v] == 1 {
				cntAdjOne++
			}
		}
		ans = min(ans, cntOne-cntAdjOne)
	}
	return ans
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		n := readInt()
		g := make([][]int, n+1)
		cnt := make([]int, n+1)
		for i := 0; i < n-1; i++ {
			uv := readInts()
			u, v := uv[0], uv[1]
			g[u] = append(g[u], v)
			g[v] = append(g[v], u)
			cnt[u]++
			cnt[v]++
		}
		fmt.Fprintln(out, solve(g, cnt, n))
		t--
	}
}
```