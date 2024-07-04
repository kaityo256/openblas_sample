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

で、実行ファイル`a.out`が作成されるはず。

実行すると、2行3列の行列と3行2列の行列の積が計算され、2行2列の行列ができる。

```sh
$ ./a.out
22.000000 28.000000 
40.000000 52.000000 
```

### Pythonとの比較

全く同じ計算をPythonのNumPyで実行したい場合、以下のようにまずNumPyを使えるようにする。

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

### LICENSE

MIT

