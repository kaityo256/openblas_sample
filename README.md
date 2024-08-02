# OpenBLASを使うサンプル

## 環境設定

### OpenBLASのインストール

```sh
brew install openblas
```

コンパイル時にインクルードパスとライブラリパスを指定する必要がある(`makefile`参照)。

正しくインストールされていれば、

```sh
make
```

で、実行ファイル`a.out`と`b.out`が作成されるはず。

実行すると、2行3列の行列と3行2列の行列の積が計算され、2行2列の行列ができる。

```sh
$ ./a.out
22.000000 28.000000 
40.000000 52.000000 
```

### Pythonとの比較

全く同じ計算をPythonのNumPyで実行して比較したい場合、以下のようにまずNumPyを使えるようにする。

```sh
python3 -m venv myenv
source myenv/bin/activate
python3 -m pip install --upgrade pip
python3 -m pip install numpy
```

`sample.py`実行すると、同じ結果となる。

```sh
$ python3 sample.py
[[22. 28.]
 [49. 64.]]
```

## スレッド並列の確認

実行ファイル`b.out`はスレッド並列実行の確認。環境変数`OMP_NUM_THREADS`を指定することでスレッド数を変えて実行できる。以下は1スレッドから4スレッドまで変えて実行した結果(途中経過の出力は省略)。

```sh
$ time OMP_NUM_THREADS=1 ./b.out
OMP_NUM_THREADS=1 ./b.out  10.09s user 0.02s system 99% cpu 10.118 total

$ time OMP_NUM_THREADS=2 ./b.out
OMP_NUM_THREADS=2 ./b.out  10.75s user 0.04s system 184% cpu 5.843 total

$ time OMP_NUM_THREADS=4 ./b.out 
OMP_NUM_THREADS=4 ./b.out  12.18s user 0.04s system 327% cpu 3.734 total
```

`system 327%`など、100%を超えており、並列実行できていることがわかる。また、実行時間も短くなっている。

### LICENSE

MIT
