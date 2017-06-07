```
git clone --recursive https://github.com/sifive/freedom-e-sdk.git

cd freedom-e-sdk

make tools

git clone git@github.com:prusnak/sifive-bench.git software/bench

make software PROGRAM=bench

make upload PROGRAM=bench
```
