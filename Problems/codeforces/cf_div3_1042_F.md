# F - Unjust Binary Life

FFT优化

暴力算法(n^2)
```go
func solve(n int, a, b string) int {
	ans := 0
	cntA0 := make([]int, n+1)
	cntA1 := make([]int, n+1)
	cntB0 := make([]int, n+1)
	cntB1 := make([]int, n+1)
	if a[0] == '0' {
		cntA0[1] = 1
	} else {
		cntA1[1] = 1
	}
	if b[0] == '0' {
		cntB0[1] = 1
	} else {
		cntB1[1] = 1
	}

	for i := 2; i <= n; i++ {
		if a[i-1] == '0' {
			cntA0[i] = cntA0[i-1] + 1
			cntA1[i] = cntA1[i-1]
		} else {
			cntA0[i] = cntA0[i-1]
			cntA1[i] = cntA1[i-1] + 1
		}
		if b[i-1] == '0' {
			cntB0[i] = cntB0[i-1] + 1
			cntB1[i] = cntB1[i-1]
		} else {
			cntB0[i] = cntB0[i-1]
			cntB1[i] = cntB1[i-1] + 1
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			cnt0 := cntA0[i] + cntB0[j]
			cnt1 := cntA1[i] + cntB1[j]
			ans += i + j - max(cnt0, cnt1)
		}
	}
	return ans
}

func main() {
	defer out.Flush()

	t := readInt()
	for t > 0 {
		n := readInt()
		a := readString()
		b := readString()
		fmt.Fprintln(out, solve(n, a, b))
		t--
	}
}
```

FFT优化(nlogn)
```go
func fft(a []complex128, invert bool) {
	n := len(a)
	// 位逆序
	for i, j := 1, 0; i < n; i++ {
		bit := n >> 1
		for ; j&bit != 0; bit >>= 1 {
			j ^= bit
		}
		j ^= bit
		if i < j {
			a[i], a[j] = a[j], a[i]
		}
	}
	for len_ := 2; len_ <= n; len_ <<= 1 {
		ang := 2 * math.Pi / float64(len_)
		if invert {
			ang = -ang
		}
		wlen := complex(math.Cos(ang), math.Sin(ang))
		for i := 0; i < n; i += len_ {
			w := complex(1, 0)
			half := len_ >> 1
			for j := 0; j < half; j++ {
				u := a[i+j]
				v := a[i+j+half] * w
				a[i+j] = u + v
				a[i+j+half] = u - v
				w *= wlen
			}
		}
	}
	if invert {
		inv := 1.0 / float64(n)
		for i := 0; i < n; i++ {
			a[i] *= complex(inv, 0)
		}
	}
}

func convolutionInt64(f, g []int64) []int64 {
	// 输入非负整型频率，输出整数卷积
	n := 1
	need := len(f) + len(g) - 1
	for n < need {
		n <<= 1
	}
	A := make([]complex128, n)
	B := make([]complex128, n)
	for i := range f {
		A[i] = complex(float64(f[i]), 0)
	}
	for i := range g {
		B[i] = complex(float64(g[i]), 0)
	}
	fft(A, false)
	fft(B, false)
	for i := 0; i < n; i++ {
		A[i] *= B[i]
	}
	fft(A, true)
	res := make([]int64, need)
	for i := 0; i < need; i++ {
		// 四舍五入
		val := math.Round(real(A[i]))
		if val < 0 {
			val = 0 // 保险，理论上不会 <0
		}
		res[i] = int64(val)
	}
	return res
}

// ---------- 解题核心 ----------

func solve(n int, a, b string) int64 {
	// 统计 di = 2*cnt0A[i] - i, ej = 2*cnt0B[j] - j 的频率
	offset := n               // di/ej 取值在 [-n..n]，用偏移映射到 [0..2n]
	size := 2*n + 1           // 频率数组长度
	FA := make([]int64, size) // 频率
	FB := make([]int64, size)

	// 扫描 a
	cnt0 := 0
	for i := 1; i <= n; i++ {
		if a[i-1] == '0' {
			cnt0++
		}
		di := 2*cnt0 - i
		FA[di+offset]++
	}
	// 扫描 b
	cnt0 = 0
	for j := 1; j <= n; j++ {
		if b[j-1] == '0' {
			cnt0++
		}
		ej := 2*cnt0 - j
		FB[ej+offset]++
	}

	// 卷积得到 s = di + ej 的频率 C[s]
	C := convolutionInt64(FA, FB) // 长度为 4n+1，索引 r 对应 s = r - 2*offset

	// Σ(i,j)(i+j)/2  = n^2 (n+1) / 2
	n64 := int64(n)
	T := n64 * n64 * (n64 + 1) / 2

	// S_abs = Σ_s |s| * C[s]
	var Sabs int64 = 0
	for r := 0; r < len(C); r++ {
		s := int64(r - 2*offset)
		if s < 0 {
			if C[r] != 0 {
				Sabs += (-s) * C[r]
			}
		} else {
			if C[r] != 0 {
				Sabs += s * C[r]
			}
		}
	}

	// ans = T - Sabs/2
	return T - Sabs/2
}

func main() {
	defer out.Flush()
	t := readInt()
	for ; t > 0; t-- {
		n := readInt()
		a := readString()
		b := readString()
		fmt.Fprintln(out, solve(n, a, b))
	}
}
```